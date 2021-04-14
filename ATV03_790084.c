//MARIA ANITA DE MOURA - RA_790084
#include <stdio.h>
void polegada(int qtdTracos, int totalTracos, int n);
void regua(int qtdTracos, int n);
void tracejado(int qtdTracos, int quebraLinha);

int main(int argc, char const *argv[])
{
    int tamanhoRegua, qtdTracos;
    scanf("%i", &tamanhoRegua); // recebe o tamanho da polegada
    scanf("%i", &qtdTracos); // recebe a qtdd de tracos
    regua(qtdTracos, tamanhoRegua);

    return 0;
}

void polegada(int qtdTracos, int totalTracos, int n){ // qtdTracos 'e alterado a cada chamada, enquanto o totalTracos nao, para saber o fim e o comeco de um polegada
   if(n==0){  //se tamanho da regua for zero
        tracejado(qtdTracos,1);
        printf(" %i\n",n);
        return;
    }
   else if(qtdTracos==1){   
        if(totalTracos == 1){ // se total de tracos for 1, altera se apenas o n recursivamente
            polegada(1,1,n-1);
            
            tracejado(1,1);
            printf(" %i\n",n);
                                  
            return;
        }else{  // caso base de tracos
            tracejado(1,0);
        }        
    }   
    
    else if(qtdTracos == totalTracos){ //quando for marcar um numero
        if(n==1){  //primeira marcao de polegada
            tracejado(totalTracos,1);
            printf(" 0\n");
        }
        polegada(qtdTracos-1,totalTracos, n); // demais marcacoes de polegadas
        tracejado(totalTracos,1);
        printf(" %i\n", n);
        return;
    }
    else{     
        polegada(qtdTracos-1,totalTracos,n);
        tracejado(qtdTracos,0); 
        qtdTracos==2 ? tracejado(1,0) : polegada(qtdTracos-1,totalTracos,n); // se forem 2 tracos, printa 1 em seguida, se nao refaz a recursao
        return;   
    }
    

}
void regua(int qtdTracos, int n){       //cria a regua
    
    if (n==1 || n==0 || qtdTracos == 1){  // caso base para o tamanho da regua (e se qtdTracos for 1 para nao ocorrer erro)
        polegada(qtdTracos,qtdTracos, n);
        return;
    }else{
        regua(qtdTracos, n-1);          //recursao
        polegada(qtdTracos, qtdTracos, n);   // desenha uma polegadae suas fracoes
        return;
    } 
}


void tracejado(int qtdTracos, int quebraLinha){  // recebe o numero de tracos(qtdTracos), 
    for (int i = 0; i < qtdTracos; i++) // imprime a qtd de tracos desejada
    {
        printf("-");
    }
    if(quebraLinha==0){ // para fazer uma quebra de linha o segundo argumento recebe 0, se nao 1
        printf("\n");
    }
    return;
}
