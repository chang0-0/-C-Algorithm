#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16

int list[MAX_SIZE] = {8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40};

int seq_search(int key, int low, int high) {
    int i;

    for(i = low; i <= high; i++) {
        if(list[i] == key) {
            return i;   //탐색에 성공하면 키 값의 인덱스 변환
        }
    }

    return -1;  //탐색에 실패하면 -1 반환
}

int seq_search2(int key, int low, int high) {
    int i;

    list[high + 1] = key;
    for(i = low; list[i] != key; i++) { //키값을 찾으면 종료
        ;
    }
    
    if(i = (high + 1)) {
        return -1;          //탐색 실패
    }
    else {
        return i;           //탐색 성공
    }
}

int main(void) {
    int result;
    int find;

    printf("찾을 값을 입력하세요 : ");
    scanf(" %d",&find);
    
    result = seq_search(find, 0, MAX_SIZE);

    if(result == -1) {
        printf("탐색 실패");
    }
    else {
        printf("%d 번째에 있습니다. ", result);
    }

    return 0;
}