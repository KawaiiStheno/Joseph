#include "fichas.h"

Lista* cria_lista(){
	Lista* li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}
	return li;
}

void libera_lista(Lista* li){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free(*li);
}

int tamanho_lista(Lista* li){
	if(li==NULL){
		return -1;
	}
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}

int lista_vazia(Lista* li){
	if(li == NULL){
		return 1;
	}else if(*li == NULL){
		return 1;
	}else
	return 0;
}

int insere_ordenada(Lista* li, struct entrada al){
	if(li == NULL){
		return 0;
	}
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL){
		return 0;
	}
	no->dados = al;
	if(lista_vazia(li)){
		no->prox=(*li);
		*li = no;
		return 1;
	}else{
		Elem *ant, *atual = *li;
		while(atual != NULL && atual->dados.id <al.id){
			ant = atual;
			atual = atual->prox;
		}
		if(atual == *li){
			no->prox = (*li);
			*li = no;
		}else{
			no->prox = ant->prox;
			ant->prox = no;
		}
		return 1;
	}
}
void imprime(Lista* li){
	if(li==NULL||(*li)==NULL){
		printf("A lista esta vazia!\n");
	}else{
		Elem *aux = *li;
		int cont = 0;
		while(aux != NULL){
			cont++;
			printf("\t\t\tJogador %d\n",cont);
			printf("Id do Jogador: %d\n",(aux->dados).id);
			printf("Nome do Jogador: %s\n",(aux->dados).nome);
			printf("Nome do Personagem: %s\n",(aux->dados).player);
			printf("Raca: %s\n",(aux->dados).raca);
			printf("Forca: %d\n",(aux->dados).fo);
			printf("Constituicao: %d\n",(aux->dados).cons);
			printf("Destreza: %d\n",(aux->dados).des);
			printf("Inteligencia: %d\n",(aux->dados).inte);
			printf("Sabedoria: %d\n",(aux->dados).sab);
			printf("Carisma: %d\n",(aux->dados).car);
			
			aux = aux->prox;
		}
	}
}

int remove_inicio(Lista* li){
	if(li==NULL||(*li)==NULL){
		return 0;
	}
	Elem *no = *li;
	*li = no->prox;
	free(no);
	return 1;
}

int remove_final(Lista* li){
	if(li==NULL||(*li)==NULL){
		return 0;
	}
	Elem *ant, *no = *li;
	while(no->prox != NULL){
		ant = no;
		no = no->prox;
	}
	if(no==(*li)){
		*li=no->prox;
	}else{
		ant->prox = no->prox;
	}
	free(no);
	return 1;
}

int remove_qlqr(Lista* li, int id){
	if(li==NULL){
		return 0;
	}
	Elem *ant, *no = *li;
	while(no!=NULL && no->dados.id!=id){
		ant = no;
		no=no->prox;
	}
	if(no==NULL){
		return -1;
	}
	if(no == *li){
		*li = no->prox;
	}else{
		ant->prox = no->prox;
	}
	free(no);
	return 1;
}
