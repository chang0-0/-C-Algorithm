#include <stdio.h>
#include <stdlib.h>

int swapNumber(int *first, int *second) {
    int temp = 70;

    printf("--초기상태의 값 확인-- \n");
    printf("temp의 주소값 = %d \n", &temp);
    printf("first 주소값 = %d \n", &first);
    printf("second 주소값 = %d \n\n", &second);

    int *th = &temp;

    //역참조로 값을 가져옴
    temp = *first;
    *first = *second;
    *second = temp;
    
    //first의 주소값을 temp에 대입.
    //second와 first의 주소값이 같아짐.
    //temp의 주소값을 second에 삽입.
    //..결론 first의 주소값은 second가 되고 second의 주소값은 first가 된다.

    printf("temp값 확인 : %d\n", temp); 
    printf("&temp값 확인 : %d\n", &temp);

    printf("\n");

    printf("second값 확인 : %d\n", second); //???
    printf("&second 확인 : %d\n", &second); //first 의 주소값이 들어감.
    printf("*second 확인 : %d\n", *second); // = 20 역참조 활용

    printf("\n");

    printf("first의값 확인 : %d\n", first); //(first포인터 변수에 들어있는값의 주소. -> second의 주소값.)
    printf("&first값 확인 : %d\n", &first); //(first라는 포인터 변수가 있는곳. 즉, 자가자신의 주소)
    printf("*first값 확인 : %d\n", *first); // = 40 역참조 활용 second의 값.

    printf("\n");

    printf("th의값 확인 : %d\n", th); //값이 들어간 temp의 주소값.
    printf("*th의값 확인 : %d\n", *th); //대입값 없을경우 오류발생(segmentation fault).
                                        //th안에 들어있는 주소에 있는 최종 값.
    printf("&th의값 확인 : %d\n", &th); //th의 주소값.

    if(th == &temp){
        printf("동일");
    }
}

int main(void) {
    int first = 20;
    int second = 40;

    swapNumber(&first, &second);

    return 0;
}