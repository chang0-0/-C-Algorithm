#include <stdio.h>

double power(double x, int n){
    if(n==0){
        return 1;
    }
    else if((n%2)==0){ //n이 짝수일때
        return power(x*x, n/2);
    }
    else {
        return x * power(x*x, (n-1)/2);
    }
}

int main(void){
    double base;
    int exp;
    double pow;

    printf("밑수:");
    scanf("%lf", &base);

    printf("지수:");
    scanf("%d", &exp);

    pow = power(base, exp);
    //return값 반환.

    printf("%.0f의 %d제곱은 %.0f이다. \n", base,exp,pow);
}