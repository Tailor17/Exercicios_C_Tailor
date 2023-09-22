/*--------------------------------
Arquivo: mainListaCF.c
----------------------------------*/
/*
Tailor Gabriel Zitzke
*/
#include <stdio.h>
#include "ListaCF.h"


int main() {
	ListaCF lista;
	Dado dado;
	int cod,x;
	
	criaLista(&lista);
	do {
		printf("0-Fim\n");
		printf("1-Inclui no fim\n");
		printf("2-Exibe lista\n");		
		printf("3-Quantidade de nodos\n");
		printf("4-Exibe situacao da lista\n");
		printf("5-Exclui do fim\n");
		printf("6-Inclui no inicio\n");
		printf("7-Exclui do inicio\n");
		printf("8-Consulta por codigo\n");	
		printf("9-Inclui antes\n");		
		printf("10-Exclui nodo\n\n");	
		printf("Informe a operacao: ");
		scanf("%d",&cod);
		
		switch (cod)
			{
			case 1 : printf("Informe o codigo: ");
					 scanf("%d",&dado.cod);
					 printf("Informe o peso: ");
					 scanf("%f",&dado.peso);
					 if (incluiNoFim(&lista,dado)==LISTA_CHEIA)
					 	printf("ERRO: Lista Cheia!\n");
					 else
					    printf("Dados Incluidos com SUCESSO!\n");
	//				 exibeErro(erro); 			
			break;
			
			case 2 : 
				exibe(lista);
			 break;
			 
			case 3 : 
				quantidadeDeNodos(lista);		
			break;
				
			case 4 :
				if(SituacaoLista(lista,&x) == LISTA_CHEIA){
					printf("Lista Cheia\n");
				}
				if(SituacaoLista(lista,&x) == LISTA_VAZIA){
					printf("Lista Vazia\n");
				}
				else{
					printf("A Lista tem %d Lugares Livres\n", x);
				}				
			break;	
						
			case 5 :
				ExcluiDoFim(&lista);		
			break;
				
			case 6 :
				printf("Informe o codigo: ");
				scanf("%d",&dado.cod);
				printf("Informe o peso: ");
				scanf("%f",&dado.peso);
				if (incluiNoInicio(&lista,dado)==LISTA_CHEIA)
					printf("ERRO: Lista Cheia!\n");
				else
					printf("Dados Incluidos com SUCESSO!\n");
			
			
			break;
			case 7 :
				if(ExcluiDoInicio(&lista,&x)==LISTA_VAZIA){
					printf("ERRO: Lista vazia\n");
				}				
				else
					printf("Dado Excluido \n");
				break;
			
			case 8 :
					printf("Digite o codigo do dado a ser procurado: ");
					scanf("%d", &dado.cod); 
					consultaPorCodigo(lista,dado);
				break;
					
			case 9 :
					printf("Informe o codigo que voce deseja incluir: ");
					scanf("%d",&dado.cod);
					printf("Informe o peso que voce deseja incluir: ");
					scanf("%f",&dado.peso);
					printf("Voce deseja incluir o codigo - %d e o peso %.2f na posicao anterior ao codigo: ",dado.cod,dado.peso);
					scanf("%d", &x);
					incluiAntes(&lista, dado, x);				
				break;
			
			
			case 10 :
					printf("Digite o codigo do dado que voce deseja excluir: ");
					scanf("%d", &dado.cod);
					excluiNodo(&lista,&dado);
				break;
			}
		if (cod != 2)
			exibe(lista);

	} while (cod !=0);

	return 0;
}
