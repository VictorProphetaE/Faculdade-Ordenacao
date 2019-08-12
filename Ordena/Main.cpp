////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
HINSTANCE hInst;

#include <stdio.h>
#include <stdlib.h>

#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

#include "Buscas.h"
#include "Randomico.h"

typedef struct
{
    int comparacoesQ[2] ,comparacoesM[2], comparacoesH[2], comparacoesB[2];
    int trocasQ[2], trocasM[2], trocasH[2], trocasB[2];
    int bb_comp[2], bs_comp[2];
} BenchMark;


int interface_nv1();
int interface_nv2();
int interface_nv21();
int interface_nv22();
int interface_nv23();
void operacoes();
void mostra_vetor(int *vetor_base, int tamanho_vetor);
void executar_todos_algoritmos(int *vetor_base, int tamanho_vetor, BenchMark bench[]);

void mostra_vetor(int *vetor_base, int tamanho_vetor)
{
    for (int i = 0; i < tamanho_vetor; i++)
    {
        if (i%16==0) // posicionamento dos numeros na tela
        {
            printf("\n");
        }
        printf("%u ", vetor_base[i]);
    }
    printf("\n\n");
}

void executar_todos_algoritmos(int *vetor_base, int tamanho_vetor, BenchMark bench[])
{
    delete []vetor_base;
    int indice=0, v[0], valor=0;
    NumeroRandomico(v, 0);
    valor=v[0];

////////////////////////////////////////////////////////////////////////////
    vetor_base = new int[tamanho_vetor];
    NumeroRandomico(vetor_base, tamanho_vetor);

    indice=BuscaSequencial(valor, vetor_base, tamanho_vetor, bench->bs_comp)+1;
    BubbleSort(vetor_base, tamanho_vetor,bench->trocasB, bench->comparacoesB);
    indice=BuscaBinaria(valor, vetor_base, tamanho_vetor, bench->bb_comp)+1;

    delete []vetor_base;
////////////////////////////////////////////////////////////////////////////
    vetor_base = new int[tamanho_vetor];
    NumeroRandomico(vetor_base, tamanho_vetor);

    indice=BuscaSequencial(valor, vetor_base, tamanho_vetor, bench->bs_comp)+1;
    QuickSort(vetor_base, tamanho_vetor, bench->trocasQ, bench->comparacoesQ);
    indice=BuscaBinaria(valor, vetor_base, tamanho_vetor, bench->bb_comp)+1;

    delete []vetor_base;
////////////////////////////////////////////////////////////////////////////
    vetor_base = new int[tamanho_vetor];
    NumeroRandomico(vetor_base, tamanho_vetor);

    indice=BuscaSequencial(valor, vetor_base, tamanho_vetor, bench->bs_comp)+1;
    MergeSort(vetor_base, tamanho_vetor, bench->comparacoesM);
    indice=BuscaBinaria(valor, vetor_base, tamanho_vetor, bench->bb_comp)+1;

    delete []vetor_base;
////////////////////////////////////////////////////////////////////////////
    vetor_base = new int[tamanho_vetor];
    NumeroRandomico(vetor_base, tamanho_vetor);

    indice=BuscaSequencial(valor, vetor_base, tamanho_vetor, bench->bs_comp)+1;
    HeapSort(vetor_base, tamanho_vetor, bench->trocasH, bench->comparacoesH);
    indice=BuscaBinaria(valor, vetor_base, tamanho_vetor, bench->bb_comp)+1;

    delete []vetor_base;
////////////////////////////////////////////////////////////////////////////
}

int interface_nv1()
{
    int opt;
    printf("Algoritmos de ordenacao");
    printf("\n Escolha o tamanho do vetor a ser criado\n");
    printf("\n(1) Vetor de 512 unidades\n");
    printf("\n(2) Vetor de 1024 unidades\n");
    printf("\n(3) Vetor de 4096 unidades\n");
    printf("\n(4) Sair\n");
    scanf("%d",&opt);

    return opt+10;
}
int interface_nv2()
{
    int opt;
    printf("Algoritmos de ordenacao");
    printf("\n(1) Ordenar vetor base\n");
    printf("\n(2) Consular elemento no vetor base\n");
    printf("\n(3) Executar todos algotimos de ordenacao 30 vezes em vetor base\n");
    printf("\n(4) Criar novo vetor base\n");
    printf("\n(5) Sair\n");
    scanf("%d",&opt);

    return opt+20;
}
int interface_nv21()
{
    int opt;
    printf("Algoritmos de ordenacao");
    printf("\n Ordenar vetor existente com:\n");
    printf("\n(1) BubbleSort\n");
    printf("\n(2) QuickSort\n");
    printf("\n(3) MergeSort\n");
    printf("\n(4) HeapSort\n");
    printf("\n(5) Sair\n");
    scanf("%d",&opt);

    return opt+30;
}
int interface_nv22()
{
    int opt;
    printf("Algoritmos de ordenacao");
    printf("\n Consular elemento no vetor existente\n");
    printf("\n  Digite elemento a ser buscado:\n");
    scanf("%d",&opt);

    return opt;
}
int interface_nv23()
{
    int opt;
    printf("Algoritmos de ordenacao");
    printf("\n Executar ordenacoes 30 vezes\n");
    printf("\n  :\n");
    scanf("%d",&opt);
    return opt+50;
}
void operacoes()
{
    int opt=0, opt2=0, ordenado=0;
    int	nv1=0,nv2=0;
    int tamanho_vetor=0;
    int* vetor_base=NULL;
    int indice=0, valor=0;
    BenchMark bench[0];

    do
    {
        fflush (stdin);
        fflush (stdout);
        // Gerenciamento dos menus
        if (nv1==0)
        {
            opt = interface_nv1();
        }
        else
        {
            opt = interface_nv2();
        }

        switch (opt)
        {
////////////////////////////////////////////////////////////////////////

        case 11: // interface_nv1-opcao1
            //system("CLS");
            nv1=1;
            tamanho_vetor=512;

            vetor_base = new int[tamanho_vetor];
            NumeroRandomico(vetor_base, tamanho_vetor);

            mostra_vetor(vetor_base, tamanho_vetor);

            break;

        case 12: // interface_nv1-opcao2
            //system("CLS");
            nv1=1;
            tamanho_vetor=1024;

            vetor_base = new int[tamanho_vetor];
            NumeroRandomico(vetor_base, tamanho_vetor);

            mostra_vetor(vetor_base, tamanho_vetor);

            break;

        case 13: // interface_nv1-opcao3
            //system("CLS");
            nv1=1;
            tamanho_vetor=4096;

            vetor_base = new int[tamanho_vetor];
            NumeroRandomico(vetor_base, tamanho_vetor);

            mostra_vetor(vetor_base, tamanho_vetor);

            break;

////////////////////////////////////////////////////////////////////////

        case 21: // interface_nv2-opcao1
            //system("CLS");
            nv2=1;
            if (ordenado == 0)
            {
                opt2=interface_nv21();
                switch (opt2)
                {
                case 31:
                    // bubblesort
                    bench->trocasB[1]=0;
                    bench->comparacoesB[0]=0;
                    BubbleSort(vetor_base, tamanho_vetor,bench->trocasB, bench->comparacoesB);
                    mostra_vetor(vetor_base, tamanho_vetor);
                    printf("\nForam feitas %d comparacoes, e %d trocas\n\n", bench->comparacoesB[0], bench->trocasB[0]);
                    ordenado=1;
                    break;
                case 32:
                    // quicksort
                    bench->trocasQ[0]=0;
                    bench->comparacoesQ[0]=0;
                    QuickSort(vetor_base, tamanho_vetor, bench->trocasQ, bench->comparacoesQ);
                    mostra_vetor(vetor_base, tamanho_vetor);
                    printf("\nForam feitas %d comparacoes, e %d trocas\n\n", bench->comparacoesQ[0], bench->trocasQ[0]);
                    ordenado=1;
                    break;
                case 33:
                    // mergesort
                    bench->trocasM[0]=0;
                    bench->comparacoesM[0]=0;
                    MergeSort(vetor_base, tamanho_vetor, bench->comparacoesM);
                    mostra_vetor(vetor_base, tamanho_vetor);
                    printf("\nForam feitas %d comparacoes, e %d trocas\n\n", bench->comparacoesM[0], bench->trocasM[0]);
                    ordenado=1;
                    break;
                case 34:
                    // heapsort
                    bench->trocasH[0]=0;
                    bench->comparacoesH[0]=0;
                    HeapSort(vetor_base, tamanho_vetor, bench->trocasH, bench->comparacoesH);
                    mostra_vetor(vetor_base, tamanho_vetor);
                    printf("\nForam feitas %d comparacoes, e %d trocas\n\n", bench->comparacoesH[0], bench->trocasH[0]);
                    ordenado=1;
                    break;
                case 35:
                    opt=5;
                    break;
                }
            }
            break;

        case 22: // interface_nv2-opcao2
            //system("CLS");
            nv2=1;
            bench->bb_comp[0]=bench->bs_comp[0]=0;
            valor=interface_nv22();
            if (ordenado==1)
            {
                indice = BuscaBinaria(valor, vetor_base, tamanho_vetor, bench->bb_comp)+1;
                printf("\nO valor  %u  buscado esta no indice  %u, foram feitas %u comparacoes\n\n", valor, indice, bench->bb_comp[0]);
            }
            else
            {
                indice = BuscaSequencial(valor, vetor_base, tamanho_vetor, bench->bs_comp)+1;
                printf("\nO valor  %u  buscado esta no indice  %u, foram feitas %u comparacoes\n\n", valor, indice, bench->bs_comp[0]);
            }
            break;

        case 23: // interface_nv2-opcao3
            //system("CLS");
            nv2=1;
            bench->comparacoesQ[0]=bench->comparacoesM[0]=bench->comparacoesH[0]=bench->comparacoesB[0]=0;
            bench->trocasQ[0]=bench->trocasM[0]=bench->trocasH[0]=bench->trocasB[0]=0;
            bench->bb_comp[0]=bench->bs_comp[0]=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            tamanho_vetor=512;
            for (int i = 0; i < 29; i++)
            {
                executar_todos_algoritmos(vetor_base, tamanho_vetor, bench);
                if (i>0)
                {
                    bench->comparacoesB[0] = bench->comparacoesB[0]/2; bench->trocasB[0] = bench->trocasB[0]/2;
                    bench->comparacoesQ[0] = bench->comparacoesQ[0]/2; bench->trocasQ[0] = bench->trocasQ[0]/2;
                    bench->comparacoesM[0] = bench->comparacoesM[0]/2; //bench->trocasM[0] = bench->trocasM[0]/2;
                    bench->comparacoesH[0] = bench->comparacoesH[0]/2; bench->trocasH[0] = bench->trocasH[0]/2;
                    bench->bb_comp[0] = bench->bb_comp[0]/2;
                    bench->bs_comp[0] = bench->bs_comp[0]/2;
                }
            }

            printf("\n\nVetor de 512 unidades\n");
            printf("\n[Bubble] Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesB[0], bench->trocasB[0]);
            printf("\n[Quick]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesQ[0], bench->trocasQ[0]);
            printf("\n[Merge]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesM[0], bench->trocasM[0]);
            printf("\n[Heap]   Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesH[0], bench->trocasH[0]);
            printf("\n[Busca Binaria]    Foram feitas uma media de %u comparacoes", bench->bb_comp[0]);
            printf("\n[Busca Sequencial] Foram feitas uma media de %u comparacoes", bench->bs_comp[0]);

            bench->comparacoesQ[0]=bench->comparacoesM[0]=bench->comparacoesH[0]=bench->comparacoesB[0]=0;
            bench->trocasQ[0]=bench->trocasM[0]=bench->trocasH[0]=bench->trocasB[0]=0;
            bench->bb_comp[0]=bench->bs_comp[0]=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            tamanho_vetor=1024;
            for (int i = 0; i < 29; i++)
            {
                executar_todos_algoritmos(vetor_base, tamanho_vetor, bench);
                if (i>0)
                {
                    bench->comparacoesB[0] = bench->comparacoesB[0]/2; bench->trocasB[0] = bench->trocasB[0]/2;
                    bench->comparacoesQ[0] = bench->comparacoesQ[0]/2; bench->trocasQ[0] = bench->trocasQ[0]/2;
                    bench->comparacoesM[0] = bench->comparacoesM[0]/2; //bench->trocasM[0] = bench->trocasM[0]/2;
                    bench->comparacoesH[0] = bench->comparacoesH[0]/2; bench->trocasH[0] = bench->trocasH[0]/2;
                    bench->bb_comp[0] = bench->bb_comp[0]/2;
                    bench->bs_comp[0] = bench->bs_comp[0]/2;
                }
            }

            printf("\n\nVetor de 1024 unidades\n");
            printf("\n[Bubble] Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesB[0], bench->trocasB[0]);
            printf("\n[Quick]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesQ[0], bench->trocasQ[0]);
            printf("\n[Merge]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesM[0], bench->trocasM[0]);
            printf("\n[Heap]   Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesH[0], bench->trocasH[0]);
            printf("\n[Busca Binaria]    Foram feitas uma media de %u comparacoes", bench->bb_comp[0]);
            printf("\n[Busca Sequencial] Foram feitas uma media de %u comparacoes", bench->bs_comp[0]);

            bench->comparacoesQ[0]=bench->comparacoesM[0]=bench->comparacoesH[0]=bench->comparacoesB[0]=0;
            bench->trocasQ[0]=bench->trocasM[0]=bench->trocasH[0]=bench->trocasB[0]=0;
            bench->bb_comp[0]=bench->bs_comp[0]=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            tamanho_vetor=4096;
            for (int i = 0; i < 29; i++)
            {
                executar_todos_algoritmos(vetor_base, tamanho_vetor, bench);
                if (i>0)
                {
                    bench->comparacoesB[0] = bench->comparacoesB[0]/2; bench->trocasB[0] = bench->trocasB[0]/2;
                    bench->comparacoesQ[0] = bench->comparacoesQ[0]/2; bench->trocasQ[0] = bench->trocasQ[0]/2;
                    bench->comparacoesM[0] = bench->comparacoesM[0]/2; //bench->trocasM[0] = bench->trocasM[0]/2;
                    bench->comparacoesH[0] = bench->comparacoesH[0]/2; bench->trocasH[0] = bench->trocasH[0]/2;
                    bench->bb_comp[0] = bench->bb_comp[0]/2;
                    bench->bs_comp[0] = bench->bs_comp[0]/2;
                }
            }

            printf("\n\nVetor de 4096 unidades\n");
            printf("\n[Bubble] Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesB[0], bench->trocasB[0]);
            printf("\n[Quick]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesQ[0], bench->trocasQ[0]);
            printf("\n[Merge]  Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesM[0], bench->trocasM[0]);
            printf("\n[Heap]   Foram feitas uma media de %d comparacoes, e %d trocas", bench->comparacoesH[0], bench->trocasH[0]);
            printf("\n[Busca Binaria]    Foram feitas uma media de %u comparacoes", bench->bb_comp[0]);
            printf("\n[Busca Sequencial] Foram feitas uma media de %u comparacoes", bench->bs_comp[0]);

            bench->comparacoesQ[0]=bench->comparacoesM[0]=bench->comparacoesH[0]=bench->comparacoesB[0]=0;
            bench->trocasQ[0]=bench->trocasM[0]=bench->trocasH[0]=bench->trocasB[0]=0;
            bench->bb_comp[0]=bench->bs_comp[0]=0;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            printf ("\n\nLog gravado!!\n\n");

            break;

        case 24: // interface_nv2-opcao4
            //system("CLS");
            nv1=nv2=0;
            ordenado=0;
            valor=indice=0;

            bench->comparacoesQ[0]=bench->comparacoesM[0]=bench->comparacoesH[0]=bench->comparacoesB[0]=0;
            bench->trocasQ[0]=bench->trocasM[0]=bench->trocasH[0]=bench->trocasB[0]=0;
            bench->bb_comp[0]=bench->bs_comp[0]=0;

            delete []vetor_base;
            break;

////////////////////////////////////////////////////////////////////////

        case 14:
        case 25:
        case 45:
            opt=5; // finaliza loop
            break;

        default:
            //system("CLS");
            printf("Opcao Errada, digite novamente\n");
            //system("PAUSE");
            //system("CLS");
            break;
        }
    }
    while ( opt != 5 );
    delete []vetor_base;
}

////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst = hInstance;

    operacoes();

    return 0;
}
