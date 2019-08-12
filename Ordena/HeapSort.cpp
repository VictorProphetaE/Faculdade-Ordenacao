////////////////////////////////////////////////////////////////////////
//  Ordenaçao pelo Método HeapSort
//
////////////////////////////////////////////////////////////////////////
#include "HeapSort.h"
#include "Troca.h"

int trocasH=0, comparacoesH=0;

void refazHeap(int vetor_base[], int i, int tamanho)
{
    int esquerda, direita, maior;
    esquerda = 2*i;
    direita = 2*i+1;
    if (esquerda <= tamanho && vetor_base[esquerda] > vetor_base[i])
    {
        maior = esquerda;
    }
    else
    {
        maior = i;
    }
    if (direita <= tamanho && vetor_base[direita] > vetor_base[maior])
    {
        maior = direita;
    }
    if (maior != i)
    {
        Troca(&vetor_base[i],&vetor_base[maior]);

        trocasH = trocasH + 1; // contagem trocas

        refazHeap(vetor_base,maior,tamanho);
    }
    comparacoesH = comparacoesH + 4; // contagem comparaçoes
}

void constroiHeap(int vetor_base[], int tamanho)
{
    int i;
    for (i=tamanho/2; i>=1; i--)
    {
        refazHeap(vetor_base,i,tamanho);
    }
}

void HeapSort(int vetor_base[], int tamanho, int trocasHp[], int comparacoesHp[])
{
    int i; trocasH=0; comparacoesH=0;
    constroiHeap(vetor_base,tamanho);
    for (i=tamanho; i>1; i--)
    {
        Troca(&vetor_base[1],&vetor_base[i]);

        trocasH = trocasH + 1; // contagem trocas

        refazHeap(vetor_base,1,i-1);
    }
    trocasHp[0]=trocasH; comparacoesHp[0]=comparacoesH;
}
