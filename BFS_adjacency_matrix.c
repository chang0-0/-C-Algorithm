#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct QueueType { //큐 구조체 타입.
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr,"%s\n",message);
}

//공백 상태 검출 함수
void queue_init(QueueType *q) {
    q -> front = q -> rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q) {
    return (q -> front == q -> rear);
}

//포화 상태 검출 함수
int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입함수
void enqueue (QueueType *q, element item) {
    if(is_full(q)) {
        error("쿠가 포화 상태입니다.");
    }
    q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
    q -> queue[q -> rear] = item;
}

//삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공백상태입니다.");
    }
    q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
    return q -> queue[q -> front];
}

#define MAX_VERTICES 50
typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

//그래프 초기화
void graph_init(GraphType *g) {
    int r, c;
    g->n = 0;
    for(r = 0; r<MAX_VERTICES; r++) {
        for(c = 0; c<MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

//정점 삽입 연삼
void insert_vertex(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프 : 정점의 개수 초과");
        return;
    }
    g -> n++;
}

//간선 삽입 연산
void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }

    g -> adj_mat[start][end] = 1;
    g -> adj_mat[end][start] = 1;
}

void bfs_mat(GraphType *g, int v) {
    int w;
    QueueType q;

    queue_init(&q);     //큐 초기화
    visited[v] = TRUE;  //정점 v 방문 표시
    printf("%d 방문 -> ",v);
    enqueue(&q, v);     //시작 정점을 큐에 저장
    while(!is_empty(&q)) {
        v = dequeue(&q) ; //큐에 정점 추출
            for(w = 0; w<g->n; w++) { //정점의 갯수만큼 반복.

                //v는 시작점이 므로 0,w로 계속 반복됨
                //다음은 반복되면서 증가되는 w가 증가하면서 TRUE처리해서
                //방문 했다는 표시를 해준다.
                if(g->adj_mat[v][w] && !visited[w]) {
                    visited[w] = TRUE;
                    printf("%d 방문 -> ",w);
                    enqueue(&q, w);
                }
            }
    }
}   

int main(void) {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);
    for(int i=0; i<6; i++) {
        insert_vertex(g,i);
    }

    insert_edge(g, 0, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 0, 4);
    insert_edge(g, 4, 5);
    insert_edge(g, 1, 5);

    printf("너비 우선 탐색(행렬) \n");
    bfs_mat(g, 0);
    printf("\n");

    free(g);
    return 0;
}