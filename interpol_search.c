#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16

int list[MAX_SIZE] = {8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40};

int interpol_search(int key, int n) {
    int low, high, j;

    low = 0;
    high = n - 1;

    while((list[high] >= key) && (key > list[low])) {
        j = ((float)(key - list[low]) / (list[high] - list[low]) * (high - low) + low);
        printf("중간 값 = %d \n",j);
        
        if (key > list[j]) {
            low = j + 1;
        }
        else if(key < list[j]) {
            high = j - 1;
        }
        else {
            low = j;
        }
    }

    if(list[low] == key) {
        return(low);
    }
    else {
        return -1;
    }

    printf("중간 값은 = %d");
}


int main(void) {
    int result;
    int find;

    printf("찾을 값을 입력하세요 : ");
    scanf(" %d",&find);
    
    result = interpol_search(find, MAX_SIZE);

    if(result == -1) {
        printf("탐색 실패");
    }
    else {
        printf("%d 번째에 있습니다. ", result);
    }

    return 0;
}