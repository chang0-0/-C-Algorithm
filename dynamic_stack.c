#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

//type????
typedef int element;
typedef struct _stacktype{
    element data[MAX_STACK_SIZE];
    int top;
}stackType;

//???? ???? ???
void init_stack(stackType *s){
    s -> top = -1;
}

//???? ???? ???? ???
int is_empty(stackType *s){
    return (s -> top == -1);
}

//??? ???? ???? ???
int is_full(stackType *s){
    return (s -> top == (MAX_STACK_SIZE -1));
}

//???? ???
void push(stackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "???? ??? ????\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

//???? ???
element pop(stackType *s){
    if(is_empty(s)){
        fprintf(stderr, "???? ???? ???? \n");
        exit(1);
    }
    else{
        return s->data[(s->top)--];
    }
}

//??? ???
element peek(stackType *s){
    if(is_empty(s)) {
        fprintf(stderr,"???? ???? ????\n");
        exit(1);
    }
    else {
        return s->data[s->top];
    }
}

int main(void){
    stackType *s = NULL;
    s = (stackType *)malloc(sizeof(stackType));

    init_stack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));   
    printf("%d\n",pop(s));

    free(s);

    return 0;
}
