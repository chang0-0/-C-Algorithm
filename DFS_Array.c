#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50 

typedef struct GraphType{
    int n;//정점의 갯수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

//그래프 초기화
void init(GraphType *g) {
    int r, c;
    g -> n = 0;
    for(r = 0; r<MAX_VERTICES; r++) {
        for(c = 0; c<MAX_VERTICES; c++) {
            g -> adj_mat[r][c] = 0;
        }
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

//간선 삽입 연산
//간선 삽입 연산
void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) {
        fprintf(stderr, "그래프: 정점 번호 오류");
        return;
    }
    g -> adj_mat[start][end] = 1;
    g -> adj_mat[end][start] = 1;
}

//인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType *g, int v) {
    int w;
    visited[v] = TRUE;
    printf("정점 %d -> ", v);
    for(w = 0; w<g->n; w++) {
        if(g->adj_mat[v][w] && !visited[w]) {
            dfs_mat(g, w); //정점 w에서 DFS 새로 시작
        }
    }
}

int main(void) {
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    init(g);
    //G의 그래프에 4개의 정점을 생성함.
    for(int i=0; i<4; i++) {
        insert_vertext(g, i);
    }
    insert_edge(g, 0 ,1);
    insert_edge(g, 0, 2);
    insert_edge(g, 0 ,3);
    insert_edge(g, 1 ,2);
    insert_edge(g, 2 ,3);

    // insert_edge(g, 0, 1);
    // insert_edge(g, 0, 2);
    // insert_edge(g, 0, 3);
    // insert_edge(g, 1, 2);
    // insert_edge(g, 1, 4);
    // insert_edge(g, 2, 3);
    // insert_edge(g, 2, 5);
    // insert_edge(g, 3, 5);
    // insert_edge(g, 4, 5);
    // insert_edge(g, 5, 6);

    printf("깊이 우선 탐색 \n");
    dfs_mat(g ,0);
    printf("\n");
    free(g);
    return 0;
}