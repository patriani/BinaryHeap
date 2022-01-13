/*Heap{
    .Shape Property? Penúltimo nível completo e 
    último deve estar preenchido da esquerda para
    direita caso não seja completa.
    .MaxHeap (árvore de cima pra baixo): todo nó eh maior q seus filhos;
    .MinHeap: todo nó eh menor q seus filhos;
};
Fila de Prioridade (máxima e mínima);
Arvore AVL;
Treap;*/

/*
.Condição em questão: pai maior ou igual a filho;
.Pai é o teto do índice do filho por dois;

10 5 7 8 2 1 6 3 5 9 [INCORRETO]

10 5 7 
10 8 7 5
10 8 7 5 2 1 6 3 5 
10 9 7 5 8 1 6 3 5 2 [CORRETO]
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int* corrige(int* vet, int n){ // void para int*
    bool in_order = true;
    int i = 1; //indice do vetor começando em 1;

    while(true){
                
        if( (2*i+1) <= n ){ // se o índice consta no vetor então será analisado;
                                        // vet[i-1]: PAI , vet[(2*i)]: filho direita.
            if( vet[i-1] < vet[(2*i)] ){// condição MaxHeap.
                int temp1 = vet[i-1];   // invertendo pai com filho.
                int temp2 = vet[2*i];
                vet[i-1] = temp2;
                vet[2*i] = temp1;
                in_order = false;
            }
        }
        if( (2*i) <= n ){
            if( vet[i-1] < vet[(2*i-1)] ){ 
                int temp1 = vet[i-1];
                int temp2 = vet[2*i-1];
                vet[i-1] = temp2;
                vet[2*i-1] = temp1;
                in_order = false;
            }
        }
        if((2*i) == n || (2*i+1) == n ){
            if(in_order){
                return(vet); // para a execução e retorna vetor verificado
            }else{
                in_order = true;
                i = 1;
            }
        }
        i++;
    }
}

int main(){
    int* vet = NULL;
    int n = 0; // tamanho vetor
    int cont = 0;
    
    int* recebe_vet = NULL;

    printf("\ninsira tamanho entrada:\n");
    scanf("%d",&n);

    vet =(int*)malloc(n*sizeof(int));

    while(cont < n){
        int temp = 0;
        scanf("%d",&temp);
        vet[cont] = temp;
        cont++;
    }

    recebe_vet = corrige(vet,n);
    cont = 0;

    while(cont < n){
        printf("vet[%d] = %d\n",cont,recebe_vet[cont]);
        cont++;
    }

    return 0;

}