#include <stdio.h>
#include <stdlib.h>

struct entrada{
	char nome[100], player[100], raca[100];
	int fo, sab, inte, car, des, cons, id;
};
typedef struct elemento* Lista;

struct elemento{
	struct entrada dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista();

void libera_lista(Lista* li);

int tamanho_lista(Lista* li);

int lista_vazia(Lista* li);

int insere_ordenada(Lista* li, struct entrada al);

int remove_inicio(Lista* li);

int remove_final(Lista* li);

void imprime(Lista* li);

int remove_qlqr(Lista* li, int id);

