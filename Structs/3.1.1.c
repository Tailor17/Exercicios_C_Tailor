#include <stdio.h>

typedef struct {
	int nConta;
	float saldo;
}Conta;

void obtemSaldo(Conta *scc, Conta *scp);
void depositoNaConta(Conta *conta, float valor);
void retiradaConta(Conta *contar, float rvalor);
void criaConta(Conta *nc);

int main(){
	Conta cc, cp, nr;
	int op, flag = 0;
	float valorDepositoCC, valorDepositoCP,ValorSaque,falta,retira,falta2;
	cc.saldo =0;//Saldo inicial
	cp.saldo =0;//Saldo inicial
	criaConta(&nr);
	printf("Numero da conta: %d\n\n",nr.nConta);
	
	do{
	printf("Escolha uma opcao:\n");
	printf("1. Deposito em Conta Corrente; 2. Deposito em Conta Poupanca;\n3. Retirada da Conta Corrente; 4. Retirada da Poupanca; 5.Fim. \n");
	scanf("%d", &op);
	
	switch (op){
		case 1:	
		//Deposito em Conta Corrente
			obtemSaldo(&cc, &cp);
			printf("Saldo atual na conta corrente: R$%.2f\n", cc.saldo);
			 printf("Digite o valor a ser depositado na conta corrente:\n");
            scanf("%f", &valorDepositoCC);	
			depositoNaConta(&cc, valorDepositoCC);
			printf("O seu saldo atualizado da conta corrente e R$%.2f\n\n",cc.saldo);
			break;
			
		case 2:
		//Deposito em Conta Poupanca
			obtemSaldo(&cc,&cp);
			printf("Saldo atual na conta poupanca: R$%.2f\n", cp.saldo);
			printf("Digite o valor a ser depositado na conta poupanca:\n");
            scanf("%f", &valorDepositoCP);
			depositoNaConta(&cp, valorDepositoCP);
			printf("O seu saldo atualizado da conta poupanca e R$%.2f\n\n",cp.saldo);
			break;
		case 3:
		//Saque Conta Corrente
			obtemSaldo(&cc,&cp);
			printf("Saldo atual na conta corrente: R$%.2f\n", cc.saldo);
			printf("Saldo atual na conta poupanca: R$%.2f\n", cp.saldo);
			printf("Digite o valor a ser retirado da conta corrente:\n");
			scanf("%f",&ValorSaque);
			
			if(ValorSaque <= cc.saldo){
				retiradaConta(&cc, ValorSaque);
				obtemSaldo(&cc,&cp);
				printf("Saldo atual na conta corrente: R$%.2f\n\n", cc.saldo);
			}
			if(ValorSaque > cc.saldo){
				falta=ValorSaque-cc.saldo;
				if(falta <= cp.saldo){
					falta=ValorSaque-cc.saldo;			
					retiradaConta(&cp, falta);					
					falta2 = ValorSaque-falta;			
					retiradaConta(&cc, falta2);
					obtemSaldo(&cc,&cp);
					printf("O seu saldo atualizado da conta poupanca e R$%.2f e na corrente e R$%.2f\n\n",cp.saldo,cc.saldo);
					
				}
				else{
					printf("Saldo insuficiente\n\n");
				}						
			}			
			break;	
		
		case 4:	
		//Saque Conta Poupança
			obtemSaldo(&cc,&cp);
			printf("Saldo atual na conta poupanca: R$%.2f\n", cp.saldo);
			printf("Digite o valor a ser retirado da conta poupanca:\n");
			scanf("%f",&ValorSaque);
			if(ValorSaque < cp.saldo){
				retiradaConta(&cp, ValorSaque);
				printf("O seu saldo atualizado da conta poupanca e R$%.2f\n\n",cp.saldo);				
			}
			else{
				printf("Saldo insuficiente\n\n");
			}
			
			break;
		case 5:
			printf("Sistema Finalizado!\n");
			flag++;
			break;
	}}while(flag == 0);
	
	return 0;
}

void criaConta(Conta *nc){
	char nome[20] ;
	int n;
	printf("Vamos criar uma conta.\n\n");
	printf("Digite seu Nome:\n");
	scanf("%s",nome);
	printf("Sr(a). %s, Digite um numero de conta:\n",nome);
	scanf("%d", &nc->nConta);	
}

void retiradaConta(Conta *contar, float rvalor){	
	contar -> saldo -= rvalor;		
	}


void obtemSaldo(Conta *scc, Conta *scp){
	scc->saldo;
	scp->saldo;

}

void depositoNaConta(Conta *conta, float valor){
	conta -> saldo += valor;
	
}
