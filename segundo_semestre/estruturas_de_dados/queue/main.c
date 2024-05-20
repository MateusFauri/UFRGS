#include <stdio.h>
#include "Queue.h"

int main(void)
{
    DescritorQueue *descritor;
    descritor = inicializaQueue();

    push(descritor, 1);
    push(descritor, 2);
    push(descritor, 3);

    imprimeQueue(descritor);

    pop(descritor);
    printf("%d \n", consulta(descritor->inicial));


    return 0;
}