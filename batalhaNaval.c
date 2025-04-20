#include <stdio.h>


// FUNÇÃO CRIADA PARA IMPRIMIR A MATRIZ
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
    printf("  ");
    for (char letra = 'A'; letra <= 'J'; letra++)
    {
        printf("%2c", letra);
    }
    printf("\n");

    for (int i = 0; i < linhas; i++)
    {
        printf("%2d", i + 1);
        for (int j = 0; j < colunas; j++)
        {
            printf("%2d", matriz[i][j]);
        }
        printf("\n");
    }
}
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    int tabuleiro[10][10];

    // CONVERSÃO PARA DESCOBRIR O TAMANHO DA MATRIZ E NÃO CHUMBAR VALORES NOS LOOPS.
    int linhas = sizeof(tabuleiro) / sizeof(tabuleiro[0]);
    int colunas = sizeof(tabuleiro[0]) / sizeof(tabuleiro[0][0]);

    // LOOP FOR INSERINDO VALOR NA MATRIZ
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // LOOP FOR INSERINDO OS NAVIOS VERTICALMENTE E HORIZONTALMENTE
    for (int i = 0; i <= 2; i++)
    {
        tabuleiro[2][i + 5] = navio1[i];
        tabuleiro[3 + i][1] = navio2[i];
    }

    // CHAMADA DA FUNÇÃO PARA IMPRESSÃO ATUALIZADA DA MATRIZ
    imprimirMatriz(10, 10, tabuleiro);

    printf("\n\n\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.



    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
