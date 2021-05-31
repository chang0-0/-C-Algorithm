#include <stdio.h>

#define ROWS 3
#define COLS 3

//행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS]) {
    //A행렬을 B행렬로 전치함.
    
    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            B[c][r] = A[r][c];
        }
    }
}

void matrix_print(int A[ROWS][COLS]) {
    printf("========================= \n");
    for(int r = 0; r<ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            printf("%d ",A[r][c]);
        }
        printf("\n");
    }
    printf("======================== \n");
}

int main(void) {

    //전치할 행렬 생성
    int array1 [ROWS][COLS] = {{ 2,3,0 },
                               { 8,9,1 },
                               { 7,0,5 } };

    int array2 [ROWS][COLS]; //전치된 행렬을 받을 곳 array2
    //행과 열의 위치 상수값은 변하지 않음

    matrix_transpose(array1, array2);
    matrix_print(array1);
    matrix_print(array2);

    return 0;
}