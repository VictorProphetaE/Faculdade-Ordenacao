////////////////////////////////////////////////////////////////////////
// Retorna -1 caso não encontre valor buscado,
// ou a posição do valor buscado caso encontre.
////////////////////////////////////////////////////////////////////////
#include "Buscas.h"

int BuscaSequencial(int valor, int vetor_base[], int tamanho_vetor, int bs_comp[])
{
    int i;
    for (i = 0; i < tamanho_vetor; i++)
    {
        bs_comp[0] = bs_comp[0] + 1; // contagem comparaçoes
        if (vetor_base[i] == valor)
        {
            return i;
        }
    }
    return -1; // não encontrado
}

int BuscaBinaria(int valor, int vetor_base[], int tamanho_vetor, int bb_comp[])
{
    int inferior = 0; //Limite inferiorerior (o primeiro elemento do vetor em C é zero)
    int superior = tamanho_vetor-1; //Limite superiorerior (termina em um número a menos 0 à 9 são 10 numeros)
    int meio;
    while (inferior <= superior)
    {
        meio = (inferior+superior)/2;
        bb_comp[0] = bb_comp[0] + 3; // contagem comparaçoes
        if (valor == vetor_base[meio])
        {
            return meio;
        }
        else if (valor < vetor_base[meio])
        {
            superior = meio-1;
        }
        else
        {
            inferior = meio+1;
        }
    }
    return -1; // não encontrado
}
