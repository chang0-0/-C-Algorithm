#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

//문자열 char
typedef char element;
typedef struct _stacktype{
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

typedef char string;

//스택 초기화 함수
void init_stack(StackType *s){
    s -> top = -1;
}

//공백 상태 검사 함수
int is_empty(StackType *s){
    return (s -> top == -1);
}

//포화 상태 검사
int is_full(StackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

//삭제 함수
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

//피크 함수
element peek(StackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if(num1 < num2) {
        return -1;
    }

    if(num1 > num2) {
        return 1;
    }

    return 0;
}

//스택 삭제 함수 생성.
void delete(StackType *s) {
    int in[MAX_STACK_SIZE];
    StackType *new;
    init(new);

    printf("정수를 입력하세요 :");
    scanf("%s",in); //정수는 입력안되서 문자열로 받아야됨.
    int len = strlen(in);

    qsort(in,len,sizeof(char), compare);
    
    for(int i=len; i<=0; i--) {
        push(s,in[i]); //배열을 거꾸로 뒤집어서 스택에 삽입한다.
    }

    

}


int main(void) {
    StackType *s;
    init_stack(s);

    delete(s);

    return 0;
}