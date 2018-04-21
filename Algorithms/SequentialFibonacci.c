#include <stdio.h>

int main(){
    int n;
    int i = 0;
    int Fn,Fn1,Fn2;
    Fn1 = 1;
    Fn2 = 1;
    printf(" digite o numero da sequencia de fibonacci : " );
    scanf("%d" , &n);
    printf("%d %d", Fn1, Fn2);
    while(i<n){
        Fn = Fn1+Fn2;
        printf(" %d " , Fn);
        Fn2 = Fn1;
        Fn1 = Fn;
        i++;

    }
}
