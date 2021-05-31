#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;


/* 그래프에 존재하는 정점의 개수 n이 필요하다
 각 정점마다 하나의 연결 리스트가 필요하다. 따라서 정점의 개수만큼의
 포인터 배열이 필요하다. 포인터 배열의 이름을 adj_list라고 하고,
 연결 리스트 하나의 노드르 GraphNode 라는 구조체를 이용하여 나타내보자.
*/ 
typedef struct GraphType {
    int n; //정점의 갯수
    GraphNode *adj_list[MAX_VERTICES];
} GraphType;

//그래프 초기화
void init(GraphType *g) {
    int v;
    g->n = 0;
    for(v = 0; v<MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}

//정점 삽입 연산
void insert_vertext(GraphType *g, int v) {
    if(((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 갯수 초과");
        return;
    }
    g->n++;
}

//간선 삽입 연산, v를 u의 인접리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v) {
        GraphNode *node;
        if(u >= g->n || v >= g->n) {
            fprintf(stderr, "그래프: 정점 번호 오류");
            return;
        }
        node  = (GraphNode *)malloc(sizeof(GraphNode));
        node -> vertex = v;
        node -> link = g -> adj_list[u]; //헤더 노드의 링크 연결
        g -> adj_list[u] = node;
}

void print_adj_list(GraphType *g) {
    for(int i = 0; i<g->n; i++) {
        GraphNode *p = g->adj_list[i];
        printf("정점 %d의 인접 리스트 ", i);
        while (p != NULL) {
            printf("-> %d ", p -> vertex);
            p = p -> link;
        }
        printf("\n");
    }
}

int main(void) {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    for(int i=0; i<4; i++) {
        insert_vertext(g, i);
    }    

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);

    print_adj_list(g);
    free(g);

    return 0;
}