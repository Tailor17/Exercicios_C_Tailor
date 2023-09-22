/*--------------------------------
* Arquivo: ListaCF.h
*/
/*
Tailor Gabriel Zitzke
*/

#ifndef ListaCF_H
#define ListaCF_H

#define MAX_NODOS 5

#define SUCESSO            0
#define LISTA_VAZIA        1
#define LISTA_CHEIA        2
#define POSICAO_INVALIDA   3
#define CODIGO_INEXISTENTE 4

typedef struct {
	int cod;
	float peso;
} Dado;

typedef struct {
    int n;
	Dado v[MAX_NODOS];
} ListaCF;

/*--------------------------------
*  Protótipos das funções
*/
void criaLista(ListaCF *lt);
int  incluiNoFim(ListaCF *lt, Dado d);
void exibe(ListaCF lt);
int  quantidadeDeNodos(ListaCF lt);
int SituacaoLista(ListaCF lt, int *x);
int ExcluiDoFim (ListaCF *lt);
int ExcluiDoInicio(ListaCF *lt, Dado *d);
int incluiNoInicio (ListaCF *lt,Dado d);
int consultaPorCodigo(ListaCF lt, Dado d);
int incluiAntes(ListaCF *lt, Dado d, int codigoFuncao);
int excluiNodo(ListaCF *lt, Dado *d);

#endif
