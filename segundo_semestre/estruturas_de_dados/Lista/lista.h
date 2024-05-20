#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define NOME 40
#define TAMANHO 10

typedef struct
{
    int codigo;
    char nome[NOME];
    float preco;
}Produto;

typedef struct
{
    int inicio;
    int fim;
    int tamanho;
}Descritor;

void inicializa(Produto produtos[], Descritor *descritor);

int consulta(Produto produtos[], Descritor *descritor, int posicao);

int remover(Produto produtos[], Descritor *descritor, int posicao);

int insere(Produto produtos[],Descritor *descritor, int posicao);

void destroi(Produto produtos[], Descritor *descritor);


#endif // LISTA_H_INCLUDED
