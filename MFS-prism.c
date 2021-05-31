#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
    int n;  //정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

//전역변수
int selected[MAX_VERTICES];
int distance[MAX_VERTICES]; 
//현재까지 알려진, 신장 트리 정점 집합에서 각 정점까지의 거리를 가지고 있다.

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
    int v, i;
    for(i = 0; i < n; i++) {
        if(selected[i] == FALSE) {
            v = i;
            break;
        }
    }

    for(i = 0; i < n; i++) {
        if(selected[i] == FALSE && (distance[i] < distance[v])) {
            v = i;
        }
    }
    return (v);
}

void prism(GraphType *g, int s) {
    int i, u, v;

    for(u = 0; u<g->n; u++) {
        distance[u] = INF;
    }

    distance[s] = 0;

    for(i=0; i<g->n; i++) {
        u = get_min_vertex(g->n);
        selected[u] = TRUE;

        if(distance[u] == INF) {
            return;
        }
        printf("정점 %d 추가\n", u);

        for(v=0; v<g->n; v++) {
            if(g->weight[u][v] != INF) {

                if(selected[v] == FALSE && g->weight[u][v] < distance[v]) {
                    distance[v] = g -> weight[u][v];
                }
            }
        }
    }
}

int main(void) {
    // GraphType g = { 7,
    // {{0, 29, INF, INF, INF, 10 , INF},
    // {29, 0, 16, INF, INF, INF, 15},
    // {INF, 16, 0, 12, INF, INF, INF},
    // {INF, INF, 12, 0 ,22, INF, 18},
    // {INF, INF, INF, 22, 0, 27, 25},
    // {10, INF, INF, INF, 27, 0, INF},
    // {INF, 15, INF, 18, 25, INF, 0}}
    // };

    GraphType g = { 7,
    {{0, 7, INF, 5, INF, INF , INF},
    {7, 0, 8, 9, 7, INF, INF},
    {INF, 8, 0, INF, 5, INF, INF},
    {5, 9, INF, 0 ,15, 6, INF},
    {INF, 7, 5, 15, 0, 8, 9},
    {INF, INF, INF, 6, 8, 0, 11},
    {INF, INF, INF, INF, 9, 11, 0}}
    };


    prism(&g, 0);
    return 0;
}