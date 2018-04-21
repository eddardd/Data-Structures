#include <stdio.h>
#include <math.h>

int fib(int n);
int fibform(int n);

int main(){
    printf("%f\n" , fibform(10));
    printf("%d", fib(10));

}

int fib(int n){
    if(n == 1 || n == 0){
        return 1;
    }else{
        return fib(n-1)+fib(n-2);
    }
}

float fibform(int n){
    float c1 = 3/2 - sqrt(5)/10;
    float c2 = sqrt(5)/10 - 1/2;
    float r1 = (1+sqrt(5))/2;
    float r2 = (1-sqrt(5))/2;
    float fib = c1*pow(r1,n)+c2*pow(r2,n);
    return fib;
}
