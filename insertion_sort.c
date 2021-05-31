#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void insertion_sort(int list[], int n) {
    int i, j, key;
    for(i=1; i<n; i++) {
        key = list[i];
        for(j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
        }

        list[j + 1] = key;
    }
    /*첫번째 순환부분 예시 배열 {5, 3, 8, 1, 2, 7}
    처음 돌면 i = 1 이고 j = 0이 된다 따라서 key 값은 3이된다
    이렇게 반복문이 실행되면 list[j]와 key를 비교했을때 
    list[j] > key는 TRUE 이므로 교환을 해줘야된다
    여기서 list[j]는 5이고 key는 3이므로 다음단계에서
    list[j + 1] = list[j] 으로 list[1] = 5가 되고
    list[0] 도 5가 된다
    이렇게 둘다 5가 되고나서 j--로 for문으로 돌리니 j=-1이 되어서 for문을 빠져나감
    ★★여기서 핵심인게 for문을 빠져나갈때 j = -1로 빠져나감★★
    ★이렇기 때문에 다음에서 list[j+1] = j+1자체가 0이됨
    그래서 교환이 성립됨.
    */

}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand((unsigned)time(NULL)); //난수 발생
    for(i=0; i<n; i++) {
        list[i] = rand() % 100;
    }

    insertion_sort(list, n);
    for(i = 0; i<n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");
    return 0;
}