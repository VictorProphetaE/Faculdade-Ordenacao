////////////////////////////////////////////////////////////////////////
//  Ordenaçao pelo Método MergeSort
//
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include "MergeSort.h"
int comparacoesM=0;

void Merge(int vetor_base[], int tamanho)
{
    int pivo;
    int i, j, k;
    int* tmp;

    tmp = new int[tamanho];

    if (tmp == NULL)
    {
        exit(1);
    }

    pivo = tamanho / 2;

    i = 0;
    j = pivo;
    k = 0;
    while (i < pivo && j < tamanho)
    {
        if (vetor_base[i] < vetor_base[j])
        {
            tmp[k] = vetor_base[i];
            ++i;
        }
        else
        {
            tmp[k] = vetor_base[j];
            ++j;
        }
        ++k;

        comparacoesM = comparacoesM+2; // contagem comparaçoes
    }

    if (i == pivo)
    {
        while (j < tamanho)
        {
            tmp[k] = vetor_base[j];
            ++j;
            ++k;
        }
    }
    else
    {
        while (i < pivo)
        {
            tmp[k] = vetor_base[i];
            ++i;
            ++k;
        }
    }

    comparacoesM = comparacoesM+2; // contagem comparaçoes

    for (i = 0; i < tamanho; ++i)
    {
        vetor_base[i] = tmp[i];
    }

    delete []tmp;
}

void Merge_Sort(int vetor_base[], int tamanho)
{
    int pivo;

    if (tamanho > 1)
    {
        pivo = tamanho / 2;
        Merge_Sort(vetor_base, pivo);
        Merge_Sort(vetor_base + pivo, tamanho - pivo);
        Merge(vetor_base, tamanho);
    }
    comparacoesM = comparacoesM+1; // contagem comparaçoes
}

void MergeSort(int vetor_base[], int tamanho_vetor, int comparacoesMp[])
{
    comparacoesM=0;
    Merge_Sort(vetor_base, tamanho_vetor);
    comparacoesMp[0]=comparacoesM;
}
