#include <stdio.h>

int LinearSearch(float* P,float key,int n);

int main(){
    float v[] = {1,2,3,4,5};
    float key = 6;
    int index = LinearSearch(&v, key, 5);
    printf("%d", index);
}

int LinearSeach(float* P, float key, int n){
    int  i=0;
    int index=-1;
    while(i<n){
        if(P[i]==key){
            index = i;
        }
        i++;
    }
    return index;
}
