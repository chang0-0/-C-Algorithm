#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef int element;
typedef struct Array {
    int data[MAX_SIZE];
} Array;

void insert(Array array1, int loc, int item) {
    int temp;
    int items = (sizeof(array1.data)/sizeof(array1.data[0]));

    printf("배열의 길이는 = %d \n",items);
    for(int i = items -1; i>=loc; i--) {
        array1.data[i+1] = array1.data[i];
    }
    array1.data[loc] = item;
    items ++;
    //내가 원하는 배열까지위치만 반대로 뒤에서부터 밀면서 넣어주면됨
    

    for(int i = 0; i <= items; i++) {
        printf("|  %d  |",array1.data[i]);
    }
    
}

int main(void) {
    Array array1 = {{1,2,3,4,5,6}};

    //배열에 숫자 삽입.
    insert(array1,4,100);


    return 0;
}