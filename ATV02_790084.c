//MARIA ANITA DE MOURA - 790084
#include <stdio.h>

 long long int add( int  v[],  int  n){
    if (n == 1){    // caso base, se o vetor tiver tamanho 1, retornar o unico valor no vetor
        return v[0];
    }
    else{
        return add(v, n-1) + v[n-1]; // somar o valor do indice atual do vetor, com a soma dos demais valores anteriores       
    }
}

 int biggest( int  *v,  int  n){

    if(n == 1){        // caso base, se o vetor tiver tamanho 1, retornar o unico valor no vetor
        return v[0];
    }
    else{
         int  maior = biggest(v,n-1); //copiar o retorno da funcao em uma variavel para nao virar big O (2^n)
        if(v[n-1] >= maior){  // se o valor da posicao atual for maior do que o maior numero que havia em indices menore, esse passa a ser o maior valor
            return v[n-1];
        }else{
            return maior; // se nao o antigo maior valor continua sendo o maior valor
        }
    }
}

 int  least( int  *v,  int  n){          

    if(n == 1){                     
        return v[0];
    }
    else{
         int  menor = least(v,n-1);
        if(v[n-1] <= menor){
            return v[n-1];
        }else{
            return menor;
        }
    }
}
 int  growing( int  *v,  int  n){ 
    if(n==1){
        return 0;
    }        
    if(n==2 && v[1] > v[0]){   // caso base, se o tamanho do veotor for 2,e o segundo valor for maio que o primeirio retornar verdadeiro(1)
        return 1;
    }
    else if(n==2){ // caso base, se for um vetor de tamanho 2, mas nao for crescente retorna falso
        return 0;
    }
    else{
        if(v[n-1] > v[n-2] && growing(v,n-1)){  //se a funcao for verdadira pra o inicio do vetor e a as duas posicoes forem crescentes, retorna verdadeiro
            return 1;
        }
        else{
            return 0;
        }
    }
}
 int  decreasing( int  *v,  int  n){
     if(n==1){
        return 0;
    }  
    if(n==2 && v[1] < v[0]){
        return 1;
    }
    else if(n==2){
        return 0;
    }
    else{
        if(v[n-1] < v[n-2] && decreasing(v,n-1)){
            return 1;
        }
        else{
            return 0;
        }
    }
}
 int  mirrored( int  *v,  int  n,  int  z){
    
    if (n==1 || (n==2 && v[z]==v[n-1])){            // caso base: o meio do vetor ser espelhado, n==z se impar n = z+1 se par
        return 1;
    }else if(n==2 && v[z]!=v[n-1]){
        return 0;
    }else if(v[z]==v[n-1] && mirrored(v, n-1, z+1)){
        return 1;
    }else{
        return 0;
    }
}

int  main( int  argc, char const *argv[])
{
     int  tamV;
    scanf("%i", &tamV);//tamanho do vetor
     int  v[tamV];

    for ( int  i = 0; i < tamV; i++) //preencher o vetor com o numeros inseridos
    {
        scanf("%i", &v[i]);
    }

    long long int soma = add(v, tamV);
    int maior = biggest(v, tamV);
    int menor = least(v, tamV);
    printf("Soma: %lli\n", soma);
    printf("Maior: %i\n", maior);
    printf("Menor: %i\n", menor);
   
    growing(v,tamV) ? printf("Crescente: sim\n") : printf("Crescente: nao\n");
    decreasing(v,tamV) ? printf("Decrescente: sim\n") : printf("Decrescente: nao\n"); // se a funcao tiver retorno 0, nao eh verdadeira a afirmacao
    mirrored(v,tamV,0) ? printf("Espelhada: sim\n") : printf("Espelhada: nao\n");

    return 0;
}

