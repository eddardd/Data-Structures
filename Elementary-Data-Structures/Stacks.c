#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

int* create_stack(void);
void push(int x, int* stack);
int pop(int* stack);
void printStack(int* stack);

int main(){
    int* stk = create_stack();
    int i;
    for(i=0;i<100;i++){
        push(i+1,stk);
    }
    printStack(stk);
}

int* create_stack(void){
    /*Cria um vetor com (MAX+1) posições para ser usado como pilha
      a última posição é usada como controle do topo da pilha.
    */
    int* stack = (int*)calloc(STACKSIZE+1,sizeof(int));
    return stack;
}

void push(int x, int* stack){
    /*
    Função de push: adiciona um elemento no topo da pilha
    */
    int atual;
    if(stack[STACKSIZE] >= STACKSIZE){
        printf("**ERROR: STACK_OVERFLOW**\n");
        exit(0);
    }else{
        atual = stack[STACKSIZE];
        stack[atual] = x;
        stack[STACKSIZE]++;
    }
}

int pop(int* stack){
    /*
    Função de pop: remove o elemento do topo da pilha
    */
    int atual;
    if(stack[STACKSIZE] == 0){
        printf("**ERROR: STACK_UNDERFLOW**\n");
        exit(0);
    }else{
        atual = stack[STACKSIZE];
        stack[STACKSIZE]--;
        return stack[atual];
    }
}

void printStack(int* stack){
    /*
    Função de print: printa os elementos presentes na pilha
    */
    int nElements = stack[STACKSIZE];
    int i;
    if(nElements == 0){
        printf("**EMPTY STACK**\n");
    }else{
        for(i=0;i<nElements;i++){
            printf("%d  ", stack[i]);
        }
    }
}
