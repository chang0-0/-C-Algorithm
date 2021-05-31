#include <stdio.h>

int main(void){
    
    //일반 변수
    int num = 40;

    //포인터 변수 선언과 초기화(포인터의 선언과 초기화는 항상 NULL로 실행)
    int* numPointer = NULL;

    numPointer = &num;

    //일반 변수 num의 값 출력
    printf("num = %d \n", num);

    //num의 주소 값 출력
    printf("&num = %x \n", &num);
    printf("numPointer = %x \n", numPointer);

    //numPointer가 가지고 있는 주소의 데이터 값
    printf("*numPointer = %d\n", *numPointer);

    //numPointer의 주소
    printf("&numPointer = %x\n", &numPointer);
    
    //numPointer의 주소의 값의 값
    printf("**&numPointer = %d\n", **&numPointer);

    return 0;
}