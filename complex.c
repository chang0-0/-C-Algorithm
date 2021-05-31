#include <stdio.h>
#include <math.h>
#include <string.h>

//복소수 구조체
typedef struct Complex{
    double real;
    double image;
}complex;

//복수수합을 구하는 함수.
complex complex_add(complex c1, complex c2){
    complex sum;
    sum.real = c1.real + c2.real;
    sum.image = c1.image + c2.image;

    return sum;
}

//메인함수
int main(void){
    complex c1, c2, sum;

    printf("첫번째 복소수 입력 (실수, 허수) : ");
    scanf("%lf%lf", &c1.real, &c1.image);
    // c1.real = 4.0;
    // c1.image = 8.0;

    printf("두번째 복소수 입력 (실수, 허수) : ");
    scanf("%lf%lf", &c2.real, &c2.image);
    // c2.real = 2.0;
    // c2.image = 1.0;
    
    sum = complex_add(c1, c2);

    printf("두 복소수의 합은 : %lf + (%lf)*i 입니다.", sum.real, sum.image);

    return 0;
}