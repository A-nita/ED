//MARIA ANITA DE MOURA - 790084
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM 100000 // Valor maximo dos numeros dentro do vetor
#define TAM 80 // Tamanho do vetor

void ordenar(int *vetor, int *compare, int *change);
void printArray(int *vetor);
void preencheVetor(int *vetor);


void main(){
    clock_t tempo; // variavel para armazenar o tempo de execucao
    int compare = 0;
    int change = 0;
    int vetor[TAM];

    
    preencheVetor(vetor);

    //printf("Vetor desordenado: ");
    //printArray(vetor);
    tempo = clock(); // comecamos a contagem de tempo
    ordenar(vetor, &compare, &change);//funcao para ordenar o vetor
    tempo = clock() - tempo; // encerramos a contagem
    //printf("Vetor ordenado: ");
    //printArray(vetor);

    printf("Quantidade de comparacoes: %d \n", compare);
    printf("Quantidade de trocas:%d \n", change);
    printf("tempo de execucao: %lf milissegundos\n",((double)tempo)/((CLOCKS_PER_SEC/1000))); //conversao prar double
    

    return;    
}

void ordenar(int *vetor, int *compare, int *change){
    int i = 0;
    while(i < TAM){
        (*compare)++;
        for(int j = 0; j <= i ; j++){            
            if(vetor[i] < vetor[j]){
                (*compare)++;
                int aux = vetor[j];
                (*change)++;
                vetor[j] = vetor[i];
                (*change)++;
                vetor[i] = aux;
                (*change)++;
            }           
        }        
        i++;
    }
    return;
}

void printArray(int *vetor){
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return;
}



void preencheVetor(int *vetor){
    srand(time(NULL)); // aleatoriza o valor inicial para a funcao rand(), usando o horario
    for(int i = 0; i < TAM; i++){ //cria o vetor
        vetor[i] = rand() % MAX_NUM; // rand() serve para "criar" numeros aleatorios    
    }
}

