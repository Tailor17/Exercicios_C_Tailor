#include <stdio.h>

typedef struct {
    int nConta;
    float saldo;
} Conta;

// Protótipos das funções
void obtemSaldo(Conta *scc, Conta *scp);
void depositoNaConta(Conta *conta, float valor);
void retiradaContaCorrente(Conta *cc, Conta *cp, float valor);

int main() {
    Conta cc, cp;
    int op, flag = 0;
    float valorDepositoCC, valorDepositoCP, ValorSaque, falta,*p;

    do {
        printf("Escolha uma opcao:\n");
        printf("1. Deposito em Conta Corrente; 2. Deposito em Conta Poupanca;\n3. Retirada da Conta Corrente; 4. Retirada da Poupanca; 5. Fim. \n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                // Deposito em Conta Corrente
                obtemSaldo(&cc, &cp);
                printf("Saldo atual na conta corrente: R$%.2f\n", cc.saldo);
                printf("Digite o valor a ser depositado na conta corrente:\n");
                scanf("%f", &valorDepositoCC);
                depositoNaConta(&cc, valorDepositoCC);
                printf("O seu saldo atualizado da conta corrente e %.2f\n\n", cc.saldo);
                break;

            case 2:
                // Deposito em Conta Poupanca
                obtemSaldo(&cc, &cp);
                printf("Saldo atual na conta poupanca: R$%.2f\n", cp.saldo);
                printf("Digite o valor a ser depositado na conta poupanca:\n");
                scanf("%f", &valorDepositoCP);
                depositoNaConta(&cp, valorDepositoCP);
                printf("O seu saldo atualizado da conta poupanca e %.2f\n\n", cp.saldo);
                break;

            case 3:
                // Retirada da Conta Corrente
                obtemSaldo(&cc, &cp);
                printf("Saldo atual na conta corrente: R$%.2f\n", cc.saldo);
                printf("Digite o valor a ser retirado da conta corrente:\n");
                scanf("%f", &ValorSaque);

                if (ValorSaque <= cc.saldo) {
                    // Se há saldo suficiente na conta corrente, realize a retirada
                    cc.saldo -= ValorSaque;
                    printf("Retirada bem-sucedida. O seu saldo atualizado da conta corrente e %.2f\n\n", cc.saldo);
                } else {
                    // Se não há saldo suficiente na conta corrente, verifique a conta poupança
                    falta = ValorSaque - cc.saldo;
                    if (falta <= cp.saldo) {
                        // Se há saldo suficiente na conta poupança para cobrir a diferença, realize a retirada
                        cc.saldo = 0;
                        cp.saldo -= falta;
                        printf("Retirada bem-sucedida. O seu saldo atualizado da conta corrente e %.2f\n", cc.saldo);
                        printf("O seu saldo atualizado da conta poupanca e %.2f\n\n", cp.saldo);
                    } else {
                        // Não há saldo suficiente em ambas as contas
                        printf("Saldo insuficiente em ambas as contas. A retirada nao pode ser realizada.\n\n");
                    }
                }
                break;

            case 5:
                printf("Sistema Finalizado!\n");
                flag++;
                break;
        }
    } while (flag == 0);

    return 0;
}

void obtemSaldo(Conta *scc, Conta *scp) {
    scc->saldo = 1000;
    scp->saldo = 1000;
}

void depositoNaConta(Conta *conta, float valor) {
    conta->saldo += valor;
}

