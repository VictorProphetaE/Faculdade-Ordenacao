////////////////////////////////////////////////////////////////////////
//  Ordenaçao pelo Método BubbleSort
//
////////////////////////////////////////////////////////////////////////
#include "BubbleSort.h"
#include "Troca.h"

void BubbleSort(int vetor_base[], int tamanho, int trocasB[], int comparacoesB[])
{
    int i,j;

    for ( j = 0; j < tamanho; j++ )
    {
        for ( i = 0; i < tamanho - 1; i++ )
        {
            if ( vetor_base[i] > vetor_base[i+1] )
            {
                Troca(&vetor_base[i], &vetor_base[i + 1]);

                trocasB[0]=trocasB[0]+1; // contagem trocas
            }
            comparacoesB[0]=comparacoesB[0]+1; // contagem comparaçoes
        }
    }

}
