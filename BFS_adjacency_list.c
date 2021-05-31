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

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];                              

//그래프 초기화
void graph_init(GraphType *g) {
    int v;
    g->n = 0;
    for(v=0; v<MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
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

//간선 삽입 연산 (insert_edge)
/* 이 코드에서는 간선을 삽입한다는 자료구조의 모습을 보이지만 실제로는 
헤더 노드를 만드는 함수입니다.
 예시 insert_edge(g, 0, 2); 의 경우.
 u = 0, v = 2;
1. 동적 메모리를 할당받는 node를 생성합니다.
2. node -> vertex = v의 값을 넣는다 v = 2;
3. node -> link = g -> adj_list[u] 에서 u는 0 이므로
adj_list[0]이됨 근데 adj_list[0]은 초기화 과정에서 아직 NULL 값이므로
node -> link = NULL의 값을 가짐 
adj_list[0]의 주소를 node -> link에 줌 (NULL 값)
4. 그리고 g -> adj_list[0]에 node의 주소를 전해줌
 결국에 node 는 헤더노드가 되고 adj_list[0]은 node의 정보를 가지게 됨.
*/
void insert_edge(GraphType *g, int u, int v) {
    GraphNode *Newnode;
    if(u >= g->n || v >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    Newnode = (GraphNode *)malloc(sizeof(GraphNode));
    Newnode -> vertex = v;
    Newnode -> link = g -> adj_list[u];
    g -> adj_list[u] = Newnode;

    printf("vertex는 %d ", g -> adj_list[u] -> vertex);
}

void bfs_list(GraphType *g, int v) {
    GraphNode *w;
    QueueType q;

    queue_init(&q);           //큐 초기화
    visited[v] = TRUE;  //정점 v 방문 표시
    printf("%d 방문 -> ", v); 
    enqueue(&q, v);
    while(!is_empty(&q)) {
        v = dequeue(&q);
        for(w = g->adj_list[v]; w; w = w->link) {
            if(!visited[w->vertex]) {
                visited[w->vertex] = TRUE;
                printf("%d 방문 -> ",w->vertex);
                enqueue(&q, w->vertex);
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

    printf("너비 우선 탐색(리스트) \n");
    bfs_list(g, 0);
    printf("\n");

    free(g);
    return 0;
}

/* ★추가 부연 설명
    너비우선탐색 인접리스트는 행렬과 결과값이 뒤집어져서 나오는데
    리스트 특성상 앞에서부터 삽입되서 나올때 늦게 들어간게 먼저 나와서 그럼
    뒤에서부터 출력하는 형식으로 바꾸면 정상적으로 출력될수있음.
*/
