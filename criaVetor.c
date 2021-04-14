#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int criaVetor(int tamVetor);
void main(){
    
    int a[] = criaVetor(10);
    for(int i = 0; i<10; i++){
        printf(a[i]);
    }

    return;    
}

criaVetor(int tamVetor){
    int vetor[tamVetor];
    srand(time(NULL));
    for(int i = 0; i < tamVetor; i++){
        vetor[i] = rand() % 100;
    }
    return(vetor);
}