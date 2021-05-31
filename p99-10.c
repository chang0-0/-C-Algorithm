#include <stdio.h>
#include <string.h>

void delete(int array[100], int loc) {
    int temp = 0;   

    //배열안의 원소 길이.
    int items = strlen(array);
    
    for(int i = loc; i<10; i++) {
        temp = array[i+1];
        array[i] = temp;
        array[i+1] = 0;
    }
    array[10] = 0;

    //결과
    for(int i = 0; i<10; i++) {
        printf("%d \n", array[i]);
    }
}

int main(void) {
    int data[10];

    //배열 숫자 삽입
    for(int i=0; i<sizeof(data); i++) {
        data[i] = i;
    }

    //함수 실행
    // delete(data[],5);

    return 0;
}