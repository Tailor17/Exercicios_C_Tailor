#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

int main(){
    int op;
    PilhaCF pl;
    int d;
    
    criaPilha(&pl);

    do {
      printf("\n0. Fim                         4. Exibe Situacao da Pilha\n");    
      printf("1. Empilha                     5. Consulta Topo\n");    
      printf("2. Desempilha                  6. Pesquisa\n");    
      printf("3. Quantidade de Nodos\n");    
      printf("Operacao: ");    
      scanf("%d", &op);

      switch(op){
            case 1:
             	printf("Digite a idade: \n");
            	scanf("%d", &d);
            	if(empilha(&pl,d)==SUCESSO){
            		printf("Operacao Realizada!\n");
				}
				else{
					printf("Pilha Cheia!\n\n");
				} 
                break;
            case 2:
            	if(desempilha(&pl,&d)==SUCESSO){
            		printf("Operação Realizada!\n");
				}
				else
					printf("Pilha Vazia!\n");
            	break;
            case 3:
            	nodos(pl);          	
                 break;
            case 4:
            	if(situacao(pl,&d)==PILHA_CHEIA){
            		printf("Pilha Cheia!\n\n");
				}
				if(situacao(pl,&d)==PILHA_VAZIA){
            		printf("Pilha Vazia!\n\n");
				}
				if(situacao(pl,&d)!=PILHA_VAZIA && situacao(pl,&d)!=PILHA_CHEIA ){
					//situacao(pl,&d);
					
					printf("A pilha tem %d lugares disponiveis \n\n",d);
				}

                 break;
            case 5:
            	consulta(&pl,&d);
            	printf("\nTopo: %d\n\n",d);
            	
                 break;   
            case 6:

                 break;   
      }
      exibePilha(pl);            
    } while (op!=0);  
                 
  return 0;
}
