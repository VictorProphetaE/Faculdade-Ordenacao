////////////////////////////////////////////////////////////////////////
//  Ordenaçao pelo Método QuickSort
//
////////////////////////////////////////////////////////////////////////
#include "QuickSort.h"
#include "Troca.h"
int trocasQ=0,comparacoesQ=0;

int particao(int vetor_base[], int esquerda, int direita)
{
    int i, j;

    i = esquerda;
    for (j = esquerda + 1; j <= direita; ++j)
    {
        if (vetor_base[j] < vetor_base[esquerda])
        {
            ++i;
            Troca(&vetor_base[i], &vetor_base[j]);

            trocasQ = trocasQ + 1; // contagem trocas

        }
        comparacoesQ = comparacoesQ + 1; // contagem comparações
    }
    Troca(&vetor_base[esquerda], &vetor_base[i]);

    trocasQ = trocasQ + 1; // contagem trocas

    return i;
}

void Quick(int vetor_base[], int esquerda, int direita)
{
    int r;

    if (direita > esquerda)
    {
        r = particao(vetor_base, esquerda, direita);
        Quick(vetor_base, esquerda, r - 1);
        Quick(vetor_base, r + 1, direita);
    }
    comparacoesQ = comparacoesQ + 1; // contagem comparações
}

void QuickSort(int* vetor_base, int tamanho, int trocasQp[], int comparacoesQp[])
{
    trocasQ=0;comparacoesQ=0;
    Quick(vetor_base, 0, tamanho - 1);
    trocasQp[0]=trocasQ; comparacoesQp[0]=comparacoesQ;
}
