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

int eval(char exp[]) {
    stackType s;
    int op1, op2 ,value, i;
    char ch;
    int len = strlen(exp);

    init_stack(&s);
    for(i=0; i<len; i++) {
        ch = exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            value = ch - '0'; //atoi함수 ascii코드로 문자를 정수로 형태를 변환해줌.
            push(&s,value);
        }
        else {
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
    return pop(&s); //최종 결과 값.
}

int main(void) {
    int result;
    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);

    return 0;
}