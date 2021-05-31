#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 20
typedef char element;
//덱 구조 예제
typedef struct _DequeType{
    element data[MAX_QUEUE_SIZE];
    int front, rear;
}DequeType;

//오류함수
void error(char *message) {
    fprintf(stderr,"%s\n", message);
    exit(1);
}

//초기화
void init_deque(DequeType *q){
    q -> front = q -> rear = 0;
}

//공백 상태 검출 함수
int is_empty(DequeType *q){
    return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(DequeType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q -> front);
}

//원현큐 출력 함수.
void deque_print(DequeType *q) {
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if(!is_empty(q)){
        int i = q -> front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if(i == q -> rear) {
                break;
            }
        } while (i != q->front);
    }
    printf("\n");
}

//삽입 함수
void add_rear(DequeType *q, element item) {
    if(is_full(q)){
        error("큐가 포화상태입니다");
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

//삭제 함수
element delete_front(DequeType *q){
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q -> data[q->front];
}

//삭제 함수
element get_front(DequeType *q) {
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


void add_front(DequeType *q, element val){
    if(is_full(q)){
        error("큐가 포화상태입니다.");
    }
    q->data[q->front] = val;
    q->front = (q->front -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q) {
    int prev = q ->rear;
        if(is_empty(q)){
            error("큐가 공백상태입니다.");
        }
        q->rear = (q->rear -1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        return q->data[prev];
}

element get_rear(DequeType *q) {
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
    }
    return q->data[q->rear];
}

int palindrome(DequeType *q) {
    int len = strlen(q -> data);

    DequeType new;
    DequeType new2;
    init_deque(&new);
    init_deque(&new2);

    for(int i = 0; i<len; i++) {

        element c = q -> data[i];
        add_front(new.data[i],c);
        add_rear(new2.data[i],c);

        while(len != 0) {
            char c1 = new.data[i];
            char c2 = new2.data[i];
            if(c1 != c2) {
                return 1;
            }
            len --;
        }
    }
    return 0;
}



int main(void) {
    int result = 0;
    
    DequeType q;

    init_deque(&q);
    printf("문자열을 입력하세요 : ");
    scanf("%s",q.data);

    result = palindrome(&q);

    if(result == 0) {
        printf("회문입니다.");
    }
    else {
        printf("회문이 아닙니다.");
    }

    return 0;
}