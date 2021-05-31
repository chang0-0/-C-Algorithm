#include <stdio.h>

int main(void){
    int a,result,i;
    
    i = 1;

    printf("숫자를 입력하세요 : ");
    scanf("%d",&a);

    printf("-- %d단 --\n",a);
    while(i<10){
        result = a * i;
        printf("%d x %d = %d \n",a,i,result);
        i++;
    }

    //for문으로도 생성 가능함.

    return 0;
}