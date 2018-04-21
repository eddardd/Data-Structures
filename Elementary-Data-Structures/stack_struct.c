#include <stdio.h>
#include <stdlib.h>


struct node{
    int x;
    struct node* prox;
};
typedef struct node elemento;

elemento* CriaElemento(void);
elemento* CriaPilha(void);

int main(){

}

elemento* CriaElemento(void){
    elemento* novo = (elemento*)calloc(1,sizeof(elemento));
    int x;
    printf("Digite x :");
    scanf("%d",&x);
    novo->x = x;
    novo->prox = NULL;
    return novo;
}

elemento* CriaPilha(void){
    elemento* Pilha = (elemento*)calloc(1,sizeof(elemento));
    Pilha->prox = NULL;
}
