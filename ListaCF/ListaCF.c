/*--------------------------------
* Arquivo: ListaCF.c
----------------------------------*/
/*
Tailor Gabriel Zitzke
*/
#include <stdio.h>
#include "ListaCF.h"

/*-----------------
* S: uma lista
*/
void criaLista(ListaCF *lt) {
	lt->n = 0;
}

/*-----------------
* E/S: uma lista
* E: um dado
* R: SUCESSO ou LISTA_CHEIA
*/
int incluiNoFim(ListaCF *lt, Dado d) {
	if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;
	else {
		lt->v[lt->n] = d;
		lt->n++;
		return SUCESSO;
	}	
}

/*-----------------
* E: uma lista
*/
void exibe(ListaCF lt) {
	int i;
	
	printf("-------------\n");
	printf("Lista:\n");
	for (i=0; i<lt.n; i++) 
		printf("   %d %.2f\n", lt.v[i].cod,lt.v[i].peso);
	printf("-------------\n\n");			
}
int quantidadeDeNodos(ListaCF lt){
	printf("Quantidade de Nodos: %d \n",lt.n);	
}
int SituacaoLista (ListaCF lt, int *x){
	if(lt.n == MAX_NODOS){
		return LISTA_CHEIA;
	}
	if(lt.n == 0){
		return LISTA_VAZIA;
	}
	if(lt.n != MAX_NODOS && lt.n != 0){

		*x = MAX_NODOS - lt.n;
		return x;
	}	
}

int ExcluiDoFim(ListaCF *lt){
	lt->n--;	
}
int ExcluiDoInicio(ListaCF *lt, Dado *d){
	int i;
	if (lt->n == 0){
		return LISTA_VAZIA;
}
	else{
		*d = lt->v[0];
		for(i=1; i<lt->n;i++){
			lt->v[i-1] = lt ->v[i];
		}
		lt->n--;
		return SUCESSO;
		}
	}
int incluiNoInicio (ListaCF *lt,Dado d){
	int i;
	if (lt->n == MAX_NODOS)
		return LISTA_CHEIA;

	 if (lt->n > 0) {
		for(i=lt->n; i >=0; i--){
				lt->v[i+1] = lt ->v[i];
			}
		lt->v[0] = d;
			lt->n++;
			return SUCESSO;		
	}
	}

int consultaPorCodigo(ListaCF lt, Dado d){
	int i;
	for(i=0;i<=lt.n;i++){
		if(lt.v[i].cod==d.cod){
		printf("\nDado encontrado! posicao - [%d]   codigo - %d    peso - %.2f\n",i, lt.v[i].cod,lt.v[i].peso);
		return SUCESSO;
	}
	 else return CODIGO_INEXISTENTE;
    }
}
int incluiAntes(ListaCF *lt, Dado d, int codigoFuncao){
	int i,j,achou;
			if (lt->n == MAX_NODOS){
			printf("\nLista cheia!\n");
			return LISTA_CHEIA;
		}
		if (lt->n == 0){
			printf("\nLista vazia!\n");
			return LISTA_VAZIA;
		}
		if(lt->n!=MAX_NODOS && lt->n!=0){
				for(i=0;i<=lt->n;i++){
					if(lt->v[i].cod==codigoFuncao){
						for(j=lt->n+1;j>i;j--){
							lt->v[j]=lt->v[j-1];
						}
						lt->v[i].peso=d.peso;
						lt->v[i].cod=d.cod;
						lt->n++;
						achou=1;
						printf("\nDado incluido com Sucesso!\n");		
					}if(achou==1) break;
				}
				if(achou==1){
					return SUCESSO;
				} else return CODIGO_INEXISTENTE;


}}

int excluiNodo(ListaCF *lt, Dado *d){
	int i,j,achou;
	if (lt->n == 0){
			printf("\nLista vazia!\n");
			return LISTA_VAZIA;
		}
		else{
			for(i=0;i<=lt->n;i++){
				if(lt->v[i].cod==d->cod){
					for(j=i;j<=lt->n;j++){
						lt->v[j]=lt->v[j+1];
					}
					achou=1;
					lt->n--;
					printf("\nDado excluido com sucesso!\n");
				} if(achou==1) break;
			}if (achou==1){
					return SUCESSO;
				}else return CODIGO_INEXISTENTE;
		}
}
	
 










