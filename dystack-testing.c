#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//스택 반복 코드.
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct _StackType {
    element *data; //동적으로 계속 변하게되는 스택 배열의 크기.
    int capacity; //스택의 크기
    int top;
} StackType;

void init_stack(StackType *s){
    s -> top = -1;
    s -> capacity = 1;
    s -> data = (element *)malloc(s -> capacity * sizeof(element)); //동적 메모리 할당
    //자료형 element(int) 4byte형식사이즈만큼 늘어나도록 할당.
}

int is_empty(StackType *s) {
    return s -> top == -1;
}

int is_full(StackType *s) {
    return (s -> top == (s -> capacity -1));
}

void push(StackType *s, element item) {
    if(is_full(s)){
        s -> capacity *= 2;   
    }
}

element pop(StackType *s) {
    if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    return s -> data[(s -> top)--];
}

int main(void) {

    return 0;
}