#include "ladae.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

int main(){
	int x, aux, cont;
	Lista *li;
	struct entrada al;
	do{
		printf("1.Criar lista.\n");
		printf("2.Verificar se a lista eh vazia.\n");
		printf("3.Liberar a lista.\n");
		printf("4.Inserir elemento na lista.\n");
		printf("5.Remover elemento no inicio da lista.\n");
		printf("6.Remover elemento no final da lista.\n");
		printf("7.Verificar o tamanho da lista.\n");
		printf("8.Imprimir a lista.\n");
		printf("9.Finalizar o programa.\n");
		printf("Digite sua escolha: ");
		scanf("%d",&aux);
		system(CLEAR);
		switch(aux){
			case 1:
			li = cria_lista();
			break;
			case 2:
			x = lista_vazia(li);
			if(x==0){
				printf("A lista nao esta vazia!\n");
			}else{
				printf("A lista esta vazia!\n");
			}
			break;
			case 3:
			libera_lista(li);
			break;
			case 4:
				printf("Digite seu ID: ");
				scanf("%d",&al.id);
				getchar();
			    printf("Digite seu nome: ");
			    scanf("%[^\n]",al.nome);
			    getchar();
			    printf("Digite o nome do seu personagem: ");
			    scanf("%[^\n]",al.player);
			    getchar();
			    printf("Digite sua raca: ");
			    scanf("%[^\n]",al.raca);
			    for(cont=0;cont<6;cont++){
			    	printf("%d atributo: ",cont+1);
			    	scanf("%d",&al.atributos[cont]);
			    }
			x = insere_ordenada(li, al);
			if(x==0){
				printf("\nErro!\n");
			}else{
				printf("\nFicha inserida com sucesso!\n");
			}
			break;
			case 5:
			x = remove_inicio(li);
			if(x==0){
				printf("\nErro!\n");
			}else{
				printf("\nFicha removida com sucesso!\n");
			}
			break;
			case 6:
			x = remove_final(li);
			if(x==0){
				printf("\nErro!\n");
			}else{
				printf("\nFicha removida com sucesso!\n");
			}
			break;
			case 7:
			x = tamanho_lista(li);
			if(x==-1){
				printf("\nErro!\n");
			}else{
				printf("\nO tamanho da lista eh:%d\n\n",x);
			}
			break;
			case 8:
				imprime(li);
				printf("\n\n");
			break;
		}
	}while(aux!=9);

	return 0;
}
