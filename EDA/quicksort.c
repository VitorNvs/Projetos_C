/*
  Implementação do algoritmo Quicksort
  Vitor Neves
*/
#include <stdio.h>

int particiona(int A[],int inicio, int fim){
    int pivot = inicio;
    int aux;
    for(int i = pivot+1; i < fim; i++){
        if(A[i] < A[inicio]){
            pivot++;
            aux = A[pivot];
            A[pivot] = A[i];
            A[i] = aux;
        }
    }
    aux = A[pivot];
    A[pivot] = A[inicio];
    A[inicio] = aux;
    return pivot;
}

void quick(int A[], int inicio, int fim){
    if(inicio < fim){
        int pivot = particiona(A,inicio, fim);
        quick(A,inicio,pivot-1);
        quick(A,pivot+1,fim);
    }
}

int main()
{
    int A[] = {7, 4, 0, 13, 5, 2, 8};
    
    quick(A, 0, 6);
    
    for(int i = 0; i < 7; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
