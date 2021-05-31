#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
}element;

typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows; //행의갯수 
    int cols; //열의갯수	 
    int terms; //항의갯수 
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a){ 
    SparseMatrix b;

    int bindex;
    b.rows = a.rows;
    b.cols = a.cols;
    b.terms = a.terms;

    if(a.terms > 0) { //a.terms가 0보다크다는 의미는 0인 원소의 갯수가 한개 이상 있을때를 의미 
        bindex = 0;
        int c;
        for(c=0; c < a.cols; c++){ //열의 갯수만큼 반복함 
            int i;
            for(i=0; i<a.terms; i++){
                if(a.data[i].col == c){ 
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++;
                }
            }
            
        }
    }
    return b;
}

void matrix_print(SparseMatrix a) {
    printf("===================\n");
    int i;
    for(i=0; i<a.terms; i++){
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
    } 
    printf("==================\n");
}

int main(void) {
    SparseMatrix m = { {{0,3,7},
                        {1,0,9},
                        {1,5,8},
                        {3,0,6},
                        {3,1,5},   
                        {4,5,1},
                        {5,2,2}},
                        6, //COLS
                        6, //ROWS
                        7  //TERMS 에 0을 제외한 값들의 갯수 
	};
    SparseMatrix result;

    result = matrix_transpose2(m);
    matrix_print(result);
    return 0;
}