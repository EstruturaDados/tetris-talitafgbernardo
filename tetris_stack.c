#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define INICIAL 5

// Struct que representa uma peça do Tetris
typedef struct {
    char nome; // I, O, T ou L
    int id;    // identificador unico
} Peca;

// Funcao para gerar uma nova peca automaticamente
Peca gerarPeca(int id) {
    Peca p;
    char tipos[] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = id;
    return p;
}

// Funcao para mostrar a fila
void mostrarFila(Peca fila[], int total) {
    printf("\nFila de pecas:\n");
    for (int i = 0; i < total; i++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
    }
    printf("\n");
}

int main() {

    Peca fila[MAX];
    int total = 0;
    int proximoId = 0;
    int opcao;

    // Inicializa a fila com 5 pecas
    for (int i = 0; i < INICIAL; i++) {
        fila[total] = gerarPeca(proximoId);
        total++;
        proximoId++;
    }

    do {
        mostrarFila(fila, total);

        printf("\nMenu:\n");
        printf("1 - Jogar peca (remover da fila)\n");
        printf("2 - Adicionar nova peca\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Dequeue
            if (total == 0) {
                printf("Fila vazia!\n");
            } else {
                printf("Peca jogada: [%c %d]\n", fila[0].nome, fila[0].id);
                for (int i = 0; i < total - 1; i++) {
                    fila[i] = fila[i + 1];
                }
                total--;
            }

        } else if (opcao == 2) {
            // Enqueue
            if (total >= MAX) {
                printf("Fila cheia!\n");
            } else {
                fila[total] = gerarPeca(proximoId);
                total++;
                proximoId++;
                printf("Nova peca adicionada!\n");
            }
        }

    } while (opcao != 0);

    return 0;
}
