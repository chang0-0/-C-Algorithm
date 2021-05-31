#include <stdio.h>

int recursive(int n){
    printf("%d\n", n);

    if(n<1){
        return -1;
    }
    else {
        return (recursive(n-2)+1);
    }
}

int main(void){
    int result;

    result = recursive(10);

    printf("결과값 = %d", result);
}