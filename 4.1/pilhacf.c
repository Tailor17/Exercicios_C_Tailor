#include <stdio.h>
#include <stdlib.h>
#include "pilhacf.h"

void criaPilha(PilhaCF *pl){
     pl->topo= -1;
}

void exibePilha(PilhaCF pl){
     int f;
     printf("Exibindo a Pilha\n");
     printf("[dado]\n");
     for (f=pl.topo;f >= 0;f--)
         printf("%4d\n", pl.v[f]);     
}

int empilha(PilhaCF *pl, int d){
	if(pl->topo == MAX_NODOS-1){
		return(PILHA_CHEIA);
		}
	else{
		pl -> topo++;
		pl -> v[pl->topo]=d;
		return(SUCESSO);
	}
}
int desempilha(PilhaCF *pl, int *d){
	if(pl->topo == -1)
		return(PILHA_VAZIA);
	else{
		*d=pl->v[pl->topo];
		pl->topo--;
		return(SUCESSO);
	}
}

void nodos(PilhaCF pl){
     int f;
    printf("%4d\n", pl.topo+1);
}

int situacao(PilhaCF pl, int *x){
	
	if(MAX_NODOS == pl.topo+1){
		return(PILHA_CHEIA);
	}
	if(pl.topo == -1){
		return(PILHA_VAZIA);
	}
	if(pl.topo!=-1 && MAX_NODOS != pl.topo+1 ){
		*x = MAX_NODOS - pl.topo-1;	
	
	}
}
int consulta(PilhaCF *pl,int *d){
	*d=pl->v[pl->topo];
	
}



