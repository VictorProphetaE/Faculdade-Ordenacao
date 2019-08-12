////////////////////////////////////////////////////////////////////////
// Preenche vetor de tamanho variavel com numeros randomicos
// de 0 a 1000
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "time.h"
#include "Randomico.h"

void NumeroRandomico(int* dados, int tamanho)
{
    srand(time(NULL));
    for (int i = 0; i < tamanho; i ++)
    {
        dados[i] = rand() % 1000; // numeros aleatorios de 0 a 1000
    }
}
