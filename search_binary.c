#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15

int list[MAX_SIZE] = {8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40};

int search_binary(int key, int low, int high) {
    int middle;

    if(low <= high) {
        middle = (low + high) / 2;
        printf("중간값 초기 : %d \n", list[middle]);
        if(key == list[middle]) {   //탐색 성공
            return middle;
        }
        else if(key < list[middle]) {   //왼쪽 부분리스트 탐색
            return search_binary(key, low, middle - 1);
        }
        else {  //오른쪽 부분리스트 탐색
            return search_binary(key, middle + 1, high);
        }
    }

    return -1;  //탐색 실패
}


int main(void) {
    int result;
    int find;

    printf("찾을 값을 입력하세요 : ");
    scanf(" %d",&find);
    
    result = search_binary(find, 0, MAX_SIZE);

    if(result == -1) {
        printf("탐색 실패");
    }
    else {
        printf("%d 번째에 있습니다. ", result);
    }

    return 0;
}