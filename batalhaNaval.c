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

int main()
{

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tamanhoDoNavio = 2;
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal[3] = {3, 3, 3};

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
    // LOOP FOR INSERINDO OS NAVIOS VERTICALMENTE E HORIZONTALMENTE

    /*DESCOMENTE ESSE TRECHO DE CÓDIGO PARA VISUALIZAR A INSERÇÃO DE VALORES
    NA HORIZONTAL,VERTICAL E DIAGONAL*/

    /* for (int i = 0; i <= tamanhoDoNavio; i++)
     {

         //a linha permanece a mesma e a coluna acrescenta o numero 3
         tabuleiro[1][1+i] = navioHorizontal[i];
         //a coluna permanece a mesma e a linha continua inserindo o 3
         tabuleiro[1+i][5] = navioVertical[i];
         //tanto linhas como colunas parte do mesmo ponto e acrescentam + 1
         tabuleiro[3+i][3+i] = navioDiagonal[i];
         tabuleiro[2+i][7+i] = navioDiagonal[i];
         // diagonal inversa, o for acrescenta mais uma linha, mas a coluna diminui, retrocede.
         tabuleiro[7 + i][8-i] = navioVertical[i];

     } */

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // CONE
    int linhaOrigemCone = 0;
    int colunaOrigemCone = 2;

    for (int i = 0; i <= tamanhoDoNavio; i++)
    {
        for (int j = colunaOrigemCone - i; j <= colunaOrigemCone + i; j++)
        {
            tabuleiro[linhaOrigemCone + i][j] = navioDiagonal[i];
        }
    }

    // CRUZ
    int linhaOrigemCruz = 4;
    int colunaOrigemCruz = 7;
    int tamanhoCruz = 3;

    for (int i = -tamanhoCruz + 1; i <= tamanhoCruz - 1; i++)
    {
        int indiceArrayPositivo = abs(i);
        tabuleiro[linhaOrigemCruz][colunaOrigemCruz + i] = navioHorizontal[indiceArrayPositivo];
        tabuleiro[linhaOrigemCruz + i][colunaOrigemCruz] = navioVertical[indiceArrayPositivo];
    }

    // OCTAEDRO

    int tamanhoOctaedro = 2;  // Altura/largura do "meio" do octaedro
    int linhaOrigemOcta = 7;  // Linha 7
    int colunaOrigemOcta = 2; // Coluna 2

    // Desenhar o octaedro
    for (int i = -tamanhoOctaedro; i <= tamanhoOctaedro; i++)
    {
        int alcance = tamanhoOctaedro - abs(i);
        for (int j = -alcance; j <= alcance; j++)
        {
            int linha = linhaOrigemOcta + i;
            int coluna = colunaOrigemOcta + j;

            // Garantir que não vamos sair da matriz
            if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
            {
                tabuleiro[linha][coluna] = 3;
            }
        }
    }

    // PONTO DE HABILIDADE
    // DEFINE O CENTRO DA CRUZ.
    int linhaHabilidade = 3;
    int colunaHabilidade = 3;
    int tamanhoHabilidade = 1; // define o "alcance" da cruz

    for (int i = -tamanhoHabilidade; i <= tamanhoHabilidade; i++)
    {
        // Parte horizontal da cruz
        if (colunaHabilidade + i >= 0 && colunaHabilidade + i < colunas)
            tabuleiro[linhaHabilidade][colunaHabilidade + i] = 5;

        // Parte vertical da cruz
        if (linhaHabilidade + i >= 0 && linhaHabilidade + i < linhas)
            tabuleiro[linhaHabilidade + i][colunaHabilidade] = 5;
    }

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

    // CHAMADA DA FUNÇÃO PARA IMPRESSÃO ATUALIZADA DA MATRIZ
    imprimirMatriz(10, 10, tabuleiro);

    printf("\n\n\n");

    return 0;
}
