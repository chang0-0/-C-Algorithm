#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//큐 크기 상수 설정.
#define MAX_QUEUE_SIZE 5

//큐 헝태의 구조체 형성.
typedef int element;
typedef struct _Queue {
    element data[MAX_QUEUE_SIZE];
    int rear;
    int front;
}Queue;

void error(char *message) {
    fprintf(stderr,"%s\n", message);
    exit(1);
}

void init_queue(Queue *q) {
    q -> rear = -1;
    q -> front = -1;
}

void queue_print(Queue *q) {
    //큐의 전체크기만큼 반복함. 큐의 전체를 표현하기 위해.
    for(int i=0; i<MAX_QUEUE_SIZE; i++){
        if(i<=q->front || i>q->rear){
            printf("    |");
        }
        else {
            printf("%d  |", q->data[i]);
        }
    }
    printf("\n");
}

int is_full(Queue *q) {
    if(q -> rear == MAX_QUEUE_SIZE -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_empty(Queue *q) {
    if(q -> front == q -> rear){
        return 1;
    }
    else {
        return 0;
    }
}

//큐 삽입함수.
void enqueue(Queue *q, element item) {
    if(is_full(q)) {
        error("큐가 포화상태 입니다.");
        return;
    }
    q -> data[++(q->rear)] = item;
}

//큐 삭제함수.
element dequeue(Queue *q) {
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
  }
  int item = q -> data[++(q->front)];
  return item;
}

int main(void) {
    int item = 0;
    Queue q;

    init_queue(&q);
    //큐 생성 및 초기화.

    enqueue(&q, 10); queue_print(&q); //FIFO형식으로 순서대로 data가 삭제됨.
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    enqueue(&q, 40); queue_print(&q);
    enqueue(&q, 50); queue_print(&q);

    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q);

    return 0;
}

