#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct _stacktype{
    element data[MAX_STACK_SIZE];
    int top;
}stackType;

//스택 초기화 함수
void init_stack(stackType *s){
    s -> top = -1;
}

//공백 상태 검사 함수
int is_empty(stackType *s){
    return (s -> top == -1);
}

//포화 상태 검사
int is_full(stackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(stackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

//삭제 함수
element pop(stackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

//피크 함수
element peek(stackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

//정수배열을 뒤집는 함수.
void range(stackType *s) {
    //배열 정리 함수.
    int array[6];
    int result[6];
    int i;
    //1.6개의 숫자를 입력받아서 배열을 완성.
    //2.배열을 그대로 넣은뒤 스택에서 꺼내면 됨 반대로 나옴.

    printf("정수를 입력하세요(6개) : ");
    for(i = 0; i<6; i++){
        scanf("%d", &array[i]); //배열완성(6개)

        push(s,array[i]);
    }

    printf("반전된 정수 배열: ");
    for(i=0; i<6; i++){
        result[i] = pop(s);

        printf("%d ", result[i]);
    }
}

int main(void){
    //배열에 숫자를 입력받고 입력받은 배열의 내용을
    //스택에 순서대로 넣은뒤 스택 내에서 값을 비교하고 비교한값을 
    //순서대로 배열에 다시 저장.
    stackType s;
    init_stack(&s);
    int *result[6];

    range(&s);

    return 0;
}