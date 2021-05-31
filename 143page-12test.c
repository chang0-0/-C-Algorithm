#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void run_length(stackType *s) {
    char in[MAX_STACK_SIZE];
    char newin[MAX_STACK_SIZE];

    printf("문자열을 입력하세요 : ");
    scanf("%s",in);
    
    int len = strlen(in);
    for(int i=0; i<len; i++) {
        newin[i] = tolower(in[i]);

        newin[i] 

    }


    



}

int main(void) {
    stackType *s;
    init_stack(s);

    run_length(s);

    return 0;
}