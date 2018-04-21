#include<stdio.h>

int BuscaBin(float* p,float key,int n);
int insertionsort(float* p, int n);

int main(){
    float v[] = {6,5,4,3,2,1};
    int i;
    int wrong_index, right_index;
    wrong_index = BuscaBin(v,2,6);
    insertionsort(v,6);
    for(i=0;i<6;i++){
        printf("v[%d] = %f\n", i+1,v[i]);
    }
    right_index = BuscaBin(v,2,6);
    printf("wrong_index = %d\n", wrong_index);
    printf("right_index = %d\n", right_index);
}

int BuscaBin(float* P,float key,int n){
    int i=0;
    int index = -1;
    int middle;
    int R=n;
    int L=0;
    while(L<=R){
        middle = (R+L)/2;
        if(P[middle]==key){
            index = middle;
        }
    int index = -1;
        if(P[middle]<key){
            L = middle + 1;
        }else{
            R = middle-1;
        }
    }
    return index;
}

int insertionsort(float* p, int n){
    int aux,i,j;
    for(i=0;i<n;i++){
        j = i;
        while((j>0)&&(p[j]<p[j-1])){
            aux = p[j];
            p[j] = p[j-1];
            p[j-1] = aux;
            j--;
        }
    }
}
