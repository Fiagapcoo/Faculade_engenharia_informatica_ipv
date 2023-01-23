#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 10 //filas da sala
#define C 10 //cadeiras por fila na sala

typedef struct {
    char nome[100]; //nome do cliente
    int pago; //se está pago ou não (0 ou 1)
} Reserva;

void criar_reserva(Reserva sala[F][C]){
    int i, j;
    for (i = 0; i < F; i++){  //percorrer todas as filas da sala
        for (j = 0; j < C; j++){ //percorrer todas as cadeiras da fila
            if (sala[i][j].nome[0] == '\0'){ //ver se está ocupado ou não, se estiver livre entra no IF
                printf("Insira o nome do cliente: ");
                scanf("%s", sala[i][j].nome);
                printf("Insira 1 se o cliente pagou ou 0 se não pagou: ");
                scanf("%d", &sala[i][j].pago);
                return;
            }
        }
    }
    //se não houver lugares disponiveis 
    printf("Não há lugares disponíveis\n");
}

void cancelar_reserva(Reserva sala[F][C]){
    int i, j;
    char nome[100];
    printf("Insira o nome do cliente: \n");//procura por nome
    scanf("%s", nome);
    for (i = 0; i < F; i++){//percorrer todas as filas da sala
        for (j = 0; j < C; j++){//percorrer todas as cadeiras da fila
            if (strcmp(sala[i][j].nome, nome) == 0){ //comparar o nome inserido com a lista de nomes, se sim limpar os campos correspondentes
                sala[i][j].nome[0] = '\0';
                sala[i][j].pago = 0;
                return;
            }
        }
    }
    //se não não ha reservas com o nome indicado
    printf("Não há reservas com esse nome\n");
}

void listar_reservas(Reserva sala[F][C]){
    int i, j;
    for (i = 0; i < F; i++){//percorrer as filas da sala
        for (j = 0; j < C; j++){//percorrer as cadeiras da fila da sala
            if (sala[i][j].nome[0] != '\0'){//se estiver ocupado, listar os campos
                printf("Nome: %s | Pago: %d | Lugar: %d%d | \n", sala[i][j].nome, sala[i][j].pago, i, j);
            }
        }
    }
}


void mapa(Reserva sala[F][C]){
    int i,j;

    for(i = 0; i < F; i++){//percorrer as filas
            printf("[");//colocar [ para iniciar uma fila
        for(j = 0; j < C; j++){//percorrer as cadeiras da fila
            if (sala[i][j].nome[0] == '\0'){//se estiver livre coloca '(L)' se não coloca '(O)'
                printf(" (L) ");
            } else {
                printf(" (O) ");
            }

        }
        printf("]");//termino da fila
        printf("\n");//passar para a fila seguinte
    }
}



int main(){
    Reserva sala[F][C]; //variavel do tipo reserva
    int i, j;
    for (i = 0; i < F; i++){
        for (j = 0; j < C; j++){
            sala[i][j].nome[0] = '\0';
            sala[i][j].pago = 0;
        }
    }
    int opcao;//a noça variavel opcao
    do{
        //case para ir para a opcao correta
        printf("1 - Criar reserva | 2 - Cancelar reserva | 3 - Listar reservas | 4- Mostrar mapa de ocupação 0 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                criar_reserva(sala);
                break;
            case 2:
                cancelar_reserva(sala);
                break;
            case 3:
                listar_reservas(sala);
                break;
            case 4:
                mapa(sala);
                break;
            case 0:
                return 0;
                break;
            default:
                printf("Digite uma opcao valida");
                break;
        }
}while (opcao != 0);

}


