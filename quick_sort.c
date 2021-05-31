#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE];
int n;

/* 퀵 정렬에서 가장 중요한 함수 partition 함수.
    partition함수는 데이터가 들어있는 비열 list의 left부터 right까지의 리스트를,
    피봇 기준으로 2개의 부분리스트로 나눈다.
*/



int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do {
            low++;  //배열의 0번째가 아닌 1번째 값부터 비교하기위해 ++를 해줌.
        }while(list[low] < pivot);

        do {
            high--;
        }while (list[high] > pivot);

        if(low<high) {
            SWAP(list[low], list[high], temp);
        }
    }
    while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}

int j=0;
void quick_sort(int list[], int left, int right) {
    int i;
    
    if(left < right) {
        j++;
        int q = partition(list, left, right);
        /*★★★★ partition 함수 : <정렬할 범위가 2개 이상의 데이터면> ★★★★
        partition 함수를 호출하여 피벗을 기준으로 2개의 리스트로 분할한다.
        partition함수의 반환값은 pivot의 위치가 된다.
        left에서 피봇 위치 바로 앞까지를 대상으로 순환호출한다.(피봇은 제외)
        피봇 위치 바로 다음부터 right까지를 대상으로 순환호출한다(피봇은 제외)*/
        printf("%d 번째 정렬 \n", j);
        printf("pivot의 위치는 %d int left는 %d, int right는 %d \n", q, left, right);
        for(i = 0; i<n; i++) {
            printf("%d ", list[i]);
        }
        printf("\n");
        
        quick_sort(list, left,  q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    // srand(time(NULL));
    // for(i = 0; i<n; i++) {
    //     list[i] = rand() % 100;
    // }

    int list[8] = {5, 7, 4, 9, 8, 5, 6, 3};

    quick_sort(list, 0 ,n-1);
    for(i = 0; i<n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}