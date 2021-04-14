//MARIA ANITA DE MOURA - 790084
#include <stdio.h>
void polegada(int q, int total, int n);
void numero(int q, int t);
void traco(int q, int l);

int main(int argc, char const *argv[])
{
    int t, qtd;
    scanf("%i", &t); // recebe o tamanho da regua
    scanf("%i", &qtd); // recebe a qtdd de tracos
    numero(qtd, t);

    return 0;
}

void polegada(int q, int total, int n){ 
    
    if(q == total){
        if(n==1){
            traco(total,1);
            printf(" 0\n");
        }
        polegada(q-1,total, n);
        traco(total,1);
        printf(" %i\n", n);
    }else if(q==1){
        traco(1,0);
    }
    else{     
        polegada(q-1,total,n);
        traco(q,0); 
        q==2 ? traco(1,0) : polegada(q-1,total,n);    
    }
    

}
void numero(int q, int t){
    if(q==1){
        for (int i = 0; i <= t; i++)
        {
            traco(1,1);
            printf("%i\n", i);
        }
        
    }
    else{
         if (t==1){
        polegada(q,q, 1);
    }else{
        numero(q, t-1);
        polegada(q, q, t);
    }
    }
     
    
}


void traco(int q, int l){
    for (int i = 0; i < q; i++)
    {
        printf("-");
    }
    if(l==0){
        printf("\n");
    }
    return;
}
