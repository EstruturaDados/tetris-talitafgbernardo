#include <stdio.h>
#include <stdlib.h>

/*
    Definição do tamanho máximo da fila de peças.
    Esse valor limita quantas peças podem existir ao mesmo tempo.
*/
#define MAX 10

/*
    Quantidade inicial de peças que a fila deve possuir
    quando o programa começa a ser executado.
*/
#define INICIAL 5

/*
    Estrutura que representa uma peça do jogo Tetris Stack.
    Cada peça possui:
    - nome: caractere que indica o tipo da peça (I, O, T ou L)
    - id: identificador único que indica a ordem de criação
*/
typedef struct {
    char nome;
    int id;
} Peca;

/*
    Função: gerarPeca
    Objetivo:
    Criar automaticamente uma nova peça do jogo.

    Parâmetro:
    - id: número inteiro que identifica exclusivamente a peça

    Retorno:
    - Uma variável do tipo Peca já preenchida
*/
Peca gerarPeca(int id) {
    Peca p;

    /*
        Vetor com os tipos possíveis de peças do Tetris.
        A escolha será feita de forma aleatória.
    */
    char tipos[] = {'I', 'O', 'T', 'L'};

    /*
        Escolhe um tipo de peça aleatoriamente
        usando o operador módulo (%) para limitar o índice.
    */
    p.nome = tipos[rand() % 4];

    /*
        Atribui o identificador único à peça.
    */
    p.id = id;

    return p;
}

/*
    Função: mostrarFila
    Objetivo:
    Exibir no terminal o estado atual da fila de peças.

    Parâmetros:
    - fila[] : vetor que representa a fila de peças
    - total  : quantidade atual de peças na fila
*/
void mostrarFila(Peca fila[], int total) {

    printf("\nFila de pecas:\n");

    /*
        Percorre a fila do início ao fim
        exibindo o tipo e o id de cada peça.
    */
    for (int i = 0; i < total; i++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
    }

    printf("\n");
}

int main() {

    /*
        Vetor que representa a fila de peças.
        A posição 0 é sempre a frente da fila.
    */
    Peca fila[MAX];

    /*
        Variável que controla quantas peças existem
        atualmente na fila.
    */
    int total = 0;

    /*
        Controla o próximo identificador único
        que será atribuído a uma nova peça.
    */
    int proximoId = 0;

    /*
        Variável usada para armazenar a opção escolhida
        pelo usuário no menu.
    */
    int opcao;

    /*
        Inicialização da fila com uma quantidade fixa
        de peças, conforme solicitado no enunciado.
    */
    for (int i = 0; i < INICIAL; i++) {
        fila[total] = gerarPeca(proximoId);
        total++;
        proximoId++;
    }

    /*
        Laço principal do programa.
        O menu continuará sendo exibido até o usuário
        escolher a opção de saída.
    */
    do {

        /*
            Exibe a fila atual antes de cada ação,
            permitindo ao usuário visualizar o estado do jogo.
        */
        mostrarFila(fila, total);

        printf("\nMenu:\n");
        printf("1 - Jogar peca (remover da fila)\n");
        printf("2 - Adicionar nova peca\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        /*
            Opção 1: Jogar uma peça
            Essa operação corresponde ao DEQUEUE da fila,
            ou seja, remove o elemento da frente.
        */
        if (opcao == 1) {

            if (total == 0) {
                /*
                    Verifica se a fila está vazia antes
                    de tentar remover uma peça.
                */
                printf("Fila vazia!\n");
            } else {

                /*
                    Mostra qual peça está sendo jogada,
                    ou seja, removida da frente da fila.
                */
                printf("Peca jogada: [%c %d]\n",
                       fila[0].nome, fila[0].id);

                /*
                    Desloca todas as peças uma posição
                    para a esquerda, simulando a remoção
                    da primeira posição da fila.
                */
                for (int i = 0; i < total - 1; i++) {
                    fila[i] = fila[i + 1];
                }

                /*
                    Reduz o total de elementos da fila.
                */
                total--;
            }

        }
        /*
            Opção 2: Adicionar nova peça
            Essa operação corresponde ao ENQUEUE da fila,
            inserindo um elemento no final.
        */
        else if (opcao == 2) {

            if (total >= MAX) {
                /*
                    Verifica se a fila já atingiu
                    seu tamanho máximo.
                */
                printf("Fila cheia!\n");
            } else {

                /*
                    Gera uma nova peça automaticamente
                    e a adiciona ao final da fila.
                */
                fila[total] = gerarPeca(proximoId);
                total++;
                proximoId++;

                printf("Nova peca adicionada!\n");
            }
        }

    } while (opcao != 0);

    /*
        Finalização do programa.
    */
    return 0;
}
