#include <stdio.h>
#include <stdlib.h>

void createheap(int* a,int n);
void max_heapify(int* a,int i, int heapsize);
void heapsort(int* a, int n);
void troca(int* a,int i,int j);
void printavetor(int n, int*p);

int main(){
    int A[5] = {5,4,3,2,1};
    printavetor(5,A);
    heapsort(A,5);
    printavetor(5,A);

}


void troca(int* a,int i,int j){
    int aux=a[j];
    a[j]=a[i];
    a[i]=aux;
}

void createheap(int* a, int n){
    int i = 0;
    for(i=0;i<n;i++){
        max_heapify(a,i,n);
    }
}

void max_heapify(int* a, int i, int heapsize){
    int l = 2*i + 1;
    int r = 2*(i+1);
    int largest = 0;
    if((l<=heapsize)&&a[l] > a[i]){
        largest = l;
    }else{
        largest = i;
    }if((r <= heapsize) && a[largest] < a[r]){
        largest = r;
    }if(largest != i){
        troca(a,largest,i);
        max_heapify(a,largest,heapsize);
    }
}

void heapsort(int* a, int n){
    int heapsize = n;
    int i;
    for(i=n;i>1;i--){
        troca(a,0,i);
        heapsize--;
        max_heapify(a,1,heapsize);
    }

}

void printavetor(int n, int*p){
    int i;
    for(i=0;i<n;i++){
        printf("Resposta %d = %d\n", i+1, p[i]);
    }
}


