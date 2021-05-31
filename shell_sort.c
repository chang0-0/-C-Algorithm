#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 7 //10
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

//각 부분 리스트에 대하여 일정한 간격으로 떨어져 있는 요소들을 삽입 정렬 하는 함수
void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j ,key;
    for(i = first + gap; i <= last; i = i + gap) { 
                                    //i는 간격만큼 증가 3씩증가.
        key = list[i];
        for(j = i - gap; j >= first && key<list[j]; j = j - gap) {
                    //조건: j값이 first 이상이고, key값이 list[j]값보다 작으면. TRUE
            list[j + gap] = list[j];
        }
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n) {
    int i, gap;
    
    for(gap = n / 2; gap > 0; gap = gap / 2) {
        printf("\n gap은 %d 입니다. \n",gap);
        if((gap % 2) == 0) { //만약 간격이 짝수이면 1을 더하는 것이 좋음.
            gap ++;
        }
        for(i=0; i<gap; i++) {
            inc_insertion_sort(list, i, n - 1, gap);
        }
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));

    printf("정렬 전: ");
    for(i=0; i<n; i++) {
        list[i] = rand() % 10;  //100
        printf("%d ", list[i]);
    }
    printf("\n");
    

    printf("정렬 후: ");
    shell_sort(list, n);
    for(i = 0; i<n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
    return 0;
}