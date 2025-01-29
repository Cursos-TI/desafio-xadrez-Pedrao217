#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops co
}#include <stdio.h>

#define BOARD_SIZE 8

void moveBishop(int board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int moveX, int moveY) {
    int newX = startX;
    int newY = startY;
    int steps = 0;

    while (steps < 5) {
        newX += moveX;
        newY += moveY;
        steps++;

        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            board[startX][startY] = 0; // Remove o bispo da posição inicial
            board[newX][newY] = 1; // Coloca o bispo na nova posição
            startX = newX;
            startY = newY;
        } else {
            printf("Movimento inválido para o bispo!\n");
            break;
        }
    }
}

void moveRook(int board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int moveX, int moveY) {
    int newX = startX;
    int newY = startY;
    int steps = 0;

    while (steps < 5) {
        newY += moveY;
        steps++;

        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            board[startX][startY] = 0; // Remove a torre da posição inicial
            board[newX][newY] = 2; // Coloca a torre na nova posição
            startY = newY;
        } else {
            printf("Movimento inválido para a torre!\n");
            break;
        }
    }
}

void moveQueen(int board[BOARD_SIZE][BOARD_SIZE], int startX, int startY, int moveX, int moveY) {
    int newX = startX;
    int newY = startY;
    int steps = 0;

    while (steps < 8) {
        newY += moveY;
        steps++;

        if (newX >= 0 && newX < BOARD_SIZE && newY >= 0 && newY < BOARD_SIZE) {
            board[startX][startY] = 0; // Remove a rainha da posição inicial
            board[newX][newY] = 3; // Coloca a rainha na nova posição
            startY = newY;
        } else {
            printf("Movimento inválido para a rainha!\n");
            break;
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // Posições iniciais
    int bishopX = 2, bishopY = 2;
    int rookX = 3, rookY = 3;
    int queenX = 4, queenY = 4;

    // Coloca as peças nas posições iniciais
    board[bishopX][bishopY] = 1; // Bispo
    board[rookX][rookY] = 2; // Torre
    board[queenX][queenY] = 3; // Rainha

    // Movimenta as peças
    moveBishop(board, bishopX, bishopY, -1, 1); // Bispo 5 casas diagonalmente para cima
    moveRook(board, rookX, rookY, 0, 1); // Torre 5 casas para a direita
    moveQueen(board, queenX, queenY, 0, -1); // Rainha 8 casas para a esquerda

    // Imprime o tabuleiro
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
