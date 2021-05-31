#include <stdio.h>
#include <stdlib.h>

int fib_iter(int n);

int fib_iter(int n){

    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }

    int pp = 0;
    int p = 1;
    int result = 0;

    for(int i = 2; i <= n; i++){
        result = p + pp;
        pp = p;
        p = result;
    }

    return result;
}

int main(void){
    int i,n;
    printf("구하려고 하는 피보나치 수열의 갯수 : ");
    scanf("%d", &n);    
    printf("피보나치 수열 : ");

    for(int i=1; i<=n; i++){
        printf("%2d",fib_iter(i));
    }

     printf("\n");

     return 0;
}