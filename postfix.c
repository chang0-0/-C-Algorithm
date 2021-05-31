#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;
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

int eval(char exp[]){
    int op1, op2, value;
    int len = strlen(exp);
    char ch;
    stackType s;

    init_stack(&s);
    for(int i=0; i<len; i++){
        ch = exp[i];
        if(ch != '+' && ch!= '-' && ch!= '*' && ch!= '/') { //토큰의 문자가 연산자가 아닐 경우
            value = ch - '0'; //문자를 정수로 처리하기위헤 '0'을 빼준다.
            push(&s, value);
        }
        else { //연산자이면 피연산자를 스택에서 제거
            op2 = pop(&s);
            op1 = pop(&s);
            switch (ch) {
                case '+' : push(&s, op1 + op2); break;
                case '-' : push(&s, op1 - op2); break;
                case '*' : push(&s, op1 * op2); break;
                case '/' : push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void){
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
    
    return 0;
};