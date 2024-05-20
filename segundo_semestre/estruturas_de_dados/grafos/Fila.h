#include <stdio.h>
#include <stdlib.h>

typedef int TipoInfo;
typedef struct s_TipoDFila TipoDFila;


TipoDFila* InicializaFila (TipoDFila *PtDFila);
TipoInfo ConsultaFila (TipoDFila *PtDFila);
void ImprimirFila (TipoDFila *PtDFila);
int InserirFila(TipoDFila **PtDFila, TipoInfo Dado);
int RemoverFila(TipoDFila **PtDFila, TipoInfo *Dado);
void DestroiFila (TipoDFila **PtDFila);
int VaziaFila(TipoDFila *PtDFila);
