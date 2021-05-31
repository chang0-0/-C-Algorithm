#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct _QueueType{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
}QueueType;


//오류출력 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q -> rear = -1;
    q -> front = -1;
}

void queue_print(QueueType *q) {
    for(int i=0; i<MAX_QUEUE_SIZE; i++) {
        if(i<=q->front || i>q->rear){
            printf("   | ");
        }
        else {
            printf("%d | ", q->data[i]);
        }
    }
    printf("\n");
}

int is_full(QueueType *q){
    if(q -> rear == MAX_QUEUE_SIZE -1) { // 5크기의 큐에서 rear가 4일경우 포화상태를 의미 
        return 1; //is_full True일시
    }
    else {
        return 0; //is_full False의 경우.
    }
}

int is_empty(QueueType *q) {
    if(q->front == q->rear) { //5크기의 큐에서 front와 rear가 같아지면 공백을 의미.
        return 1;
    }
    else {
        return 0; //is_empty False의 경우
    }
}

//삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q)) {
        error("큐가 포화상태 입니다.");
        return ;
    }
    q -> data[++(q->rear)] = item;
}

//삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}
 
int main(void) {
    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    return 0;
}