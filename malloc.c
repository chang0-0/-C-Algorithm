//MALLOC.C: malloc을 이용하여 정수10을 저장할수 있는 동적 메모리
//할당하고 free를 이용하여 메모리를 반납합니다.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main(void){
    int *p;

    p = (int *)malloc(SIZE * sizeof(int));
    if(p == NULL){
        fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.");
        exit(1);
        //exit(0) = 정상종료
        //exit(1) = 에러메시지를 종료하라는 의미
    }

    int i;
    for(i = 0; i<SIZE; i++){
            p[i] = i;
    }
    for(i = 0; i<SIZE; i++){
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}