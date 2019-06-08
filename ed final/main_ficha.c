#include "ladae.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif // _WIN32

int main(){
	int x, aux, cont, aux2;
	Lista *li;
	struct entrada al;
	do{
		printf("1.Criar lista.\n");
		printf("2.Verificar se a lista eh vazia.\n");
		printf("3.Liberar a lista.\n");
		printf("4.Inserir dados de jogador.\n");
		printf("5.Remover ficha no inicio da lista.\n");
		printf("6.Remover ficha no final da lista.\n");
		printf("7.Remover ficha especifica.\n");
		printf("8.Verificar a quantidade de jogadores.\n");
		printf("9.Imprimir fichas.\n");
		printf("10.Finalizar o programa.\n");
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
				printf("A lista nao esta vazia!\n\n");
			}else{
				printf("A lista esta vazia!\n\n");
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
			    printf("Forca: ");
			    scanf("%d",&al.fo);
			    printf("Constituicao: ");
			    scanf("%d",&al.cons);
			    printf("Destreza: ");
			    scanf("%d",&al.des);
			    printf("Inteligencia: ");
			    scanf("%d",&al.inte);
			    printf("Sabedoria: ");
			    scanf("%d",&al.sab);
			    printf("Carisma: ");
			    scanf("%d",&al.car);
			    x = insere_ordenada(li, al);
			    system(CLEAR);
			    if(x==0){
				printf("Erro!\n");
			    }else{
				printf("Ficha inserida com sucesso!\n\n");
			    }
			break;
			case 5:
			x = remove_inicio(li);
			if(x==0){
				printf("Erro!\n");
			}else{
				printf("Ficha removida com sucesso!\n\n");
			}
			break;
			case 6:
			x = remove_final(li);
			if(x==0){
				printf("Erro!\n");
			}else{
				printf("Ficha removida com sucesso!\n\n");
			}
			break;
			case 7:
				printf("Digite o Id do jogador que deseja remover: ");
				scanf("%d",&aux2);
				x = remove_qlqr(li, aux2);
				if(x==0){
					printf("Erro!\n");
				}else if(x==-1){
					printf("Jogador nao encontrado!\n\n");
				}else{
					printf("Jogador removido com sucesso!\n\n");
				}
			break;
			case 8:
			x = tamanho_lista(li);
			if(x==-1){
				printf("Erro!\n");
			}else{
				printf("A quantidade de jogadores eh:%d\n\n",x);
			}
			break;
			case 9:
				imprime(li);
				printf("\n\n");
			break;
		}
	}while(aux!=10);

	return 0;
}
