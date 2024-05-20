#include <stdio.h>
#include "Fila.h"

#define LIGACOES 18

void dfs(int **matrizAdjacente, int vertice, int vertices, int *visitados, int *cores);
void bfs(int **matrizAdjacente, int vertice, int vertices);
void imprime(int **matrizAdjacencia, int vertices);

int main()
{
    int vertices, linhas, colunas, contador, ligacao, vertice;
    int **matrizAdjacencia;
    int cores[]={0,0,0,0,0,0};
    int visitados[]= {0,0,0,0,0,0};
    int ligacoes[LIGACOES][2] = {
                        {1,2},
                        {1,6},
                        {2,1},
                        {2,3},
                        {2,4},
                        {3,2},
                        {3,4},
                        {3,5},
                        {4,2},
                        {4,3},
                        {4,5},
                        {4,6},
                        {5,3},
                        {5,4},
                        {5,6},
                        {6,1},
                        {6,4},
                        {6,5}};

    vertices = 6;

    matrizAdjacencia = malloc(vertices * sizeof(int));

    for(linhas = 0; linhas < vertices; linhas++)
        matrizAdjacencia[linhas] = malloc(vertices * sizeof(int));

    for(linhas = 0; linhas < vertices; linhas++)
        for(colunas = 0; colunas < vertices; colunas++)
        {
            ligacao = 0;
            for(contador = 0; contador < LIGACOES; contador++)
                if((ligacoes[contador][0] == linhas + 1) && (ligacoes[contador][1] == colunas + 1))
                {
                    matrizAdjacencia[linhas][colunas] = 1;
                    ligacao = 1;
                }
            if(!ligacao)
                matrizAdjacencia[linhas][colunas] = 0;
        }

    imprime(matrizAdjacencia, vertices);
    printf("Qual vertice começar o depth frist search: ");
    scanf("%d", &vertice);
    printf("Começando DFS....\n");
    dfs(matrizAdjacencia, vertice, vertices, visitados, cores);


    printf("Qual vertice começar o depth frist search: ");
    scanf("%d", &vertice);
    printf("Começando BFS....\n");
    bfs(matrizAdjacencia, vertice, vertices);

    
    return 0;
}

void dfs(int **matrizAdjacente, int vertice, int vertices, int *visitados, int *cores)
{
    int colunas;

    visitados[vertice] = 1;
    cores[vertice] = 1;

    printf("Visitado: %d - ", vertice + 1);

    for(colunas = 0; colunas < vertices; colunas++)
        if(matrizAdjacente[vertice][colunas] == 1)
            if(cores[vertice] == cores[colunas])
            {
                cores[vertice] += 1;
                colunas = 0;
            }

    printf("Cor: %d \n", cores[vertice]);
    
    for(colunas = 0; colunas < vertices; colunas++)
        if(matrizAdjacente[vertice][colunas] == 1)
            if(visitados[colunas] == 0)
                dfs(matrizAdjacente, colunas, vertices, visitados, cores);
}

void bfs(int **matrizAdjacente, int vertice, int vertices)
{
    TipoDFila *fila;
    int verificados[] = {0,0,0,0,0,0,0,0};
    int cores[] = {0,0,0,0,0,0};
    int colunas, numeroFila;

    fila = InicializaFila(fila);
    verificados[vertice] = 1;
    cores[vertice] = 1;
    InserirFila(&fila, vertice);

    while(!VaziaFila(fila))
    {
        RemoverFila(&fila, &vertice);
        printf("Visitado: %d - ", vertice + 1);
        for(colunas = 0; colunas < vertices; colunas++)
            if(matrizAdjacente[vertice][colunas] == 1)
                if(cores[vertice] == cores[colunas])
                {
                    cores[vertice] += 1;
                    colunas = 0;
                }
        
        printf("Cor: %d \n", cores[vertice]);

        for(colunas = 0; colunas < vertices; colunas++)
            if(matrizAdjacente[vertice][colunas] == 1)
                if(verificados[colunas] == 0)
                {
                    InserirFila(&fila, colunas);
                    verificados[colunas] = 1;
                    cores[colunas] = 1;
                }
    }
}

void imprime(int **matrizAdjacencia, int vertices)
{
    int linhas, colunas;

    for(linhas = 0; linhas < vertices; linhas++)
    {
        for(colunas = 0; colunas < vertices; colunas++)
            printf("%d ", matrizAdjacencia[linhas][colunas]);
        
        printf("\n");
    }
}