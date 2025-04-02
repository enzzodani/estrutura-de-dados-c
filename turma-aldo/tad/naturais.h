//Declaração das funções 

#ifdef NATURAIS_H
#define NATURAIS_H

//Definição da struct Conjunto 
typedef struct conjunto {

  elemento* inicio;
  elemento* final;
  unsigned int tamanho;

} conjunto;

//Definição da struct elemento
typedef struct elemento {
  unsigned int num;
  elemento* prox;
} elemento;

//Cria um conjunto
conjunto* criaConjunto();
//Verificar se o conjunto esta vazio
int estaVazio(conjunto* conjunto);
//Inclui um elemento no conjunto. Não incluir se ele já estiver no conjunto
void inserirElemento(conjunto* conjunto, int num);
//Exluir um elemento no conjunto. Não excluir se ele não estiver no conjunto.
void removerElemento(conjunto* conjunto, int num);
//Cardinalidade do conjunto.
int cardinalidade(conjunto* conjunto);
//Quantidade de elementos maiores que certo valor
int maioresQue(conjunto* conjunto, int num);
//Quantidade de elementos menores que certo valor
int menoresQue(conjunto* conjunto, int num);
//Averiguar se um elemento pertence ao conjunto
int pertence(conjunto* conjunto, int num);
//Verificar se 2 conjuntos são identicos
int igualdade(conjunto* conjunto1, conjunto* conjunto2);
//Identificar se um conjunto é subconjunto do outro
int estaContido(conjunto* conjunto1, conjunto* conjunto2);
//O complemento de um conjunto em relação a outro conjunto. Retorne o conjunto complemento, inclusive, quando este for um conjunto vaio.
conjunto* conjuntoComplemento(conjunto* conjunto);
//União de 2 conjuntos.
conjunto* conjuntoUniao(conjunto* conjunto1, conjunto* conjunto2);
//Intersecção de 2 conjuntos.
conjunto* conjuntoInterseccao(conjunto* conjunto1, conjunto* conjunto2);
//Mostrar o conjunto de maneira crescente ou decrescente.
void printConjunto(conjunto* conjunto, int ordem);
//Copiar o conjunto para outro conjunto.
void copiaConjunto(conjunto* conjunto1, conjunto* conjunto2);
//Destruir o conjunto.
void exluirConjunto(conjunto* conjunto);

#endif //NATURAIS_H
