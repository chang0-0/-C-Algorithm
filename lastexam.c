#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//인접리스트 버전의 깊이 우선 탐색 프로그램
//스택 구조(후입선출을 활용) 똑바로 나와야됨. 
//출력 결과를 스택에 저장하면될듯. 
 
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10

typedef int element; 

typedef struct {
	element data[MAX_VERTICES];
	int top;
} StackType;


void init_stack(StackType *s) {
	s -> top = -1;
} 

int is_empty(StackType *s) {
	return (s ->top == -1);
}

int is_full(StackType *s) {
	return (s -> top == (MAX_VERTICES - 1));
}

void push(StackType *s,element item) {
	if(is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return; 
	}
	else s -> data[++(s->top)] = item;
} 

element pop(StackType *s) {
	if(is_empty(s)) {
		fprintf(stderr,"스택 공백 에러\n");
		exit(1); 
	}
	else return s -> data[(s->top)--];
}

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
void init(GraphType *g) {
	int v;
	g -> n = 0;
	for(v = 0; v<MAX_VERTICES; v++) {
		g -> adj_list[v] = NULL;
	}
} 

void insert_vertex(GraphType *g, int v) {
	if(((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g -> n++;
}

void insert_edge(GraphType *g, int u, int v) {
	GraphNode *node;
	if(u >= g->n || v >= g->n) {
		fprintf(stderr,"그래프: 정점 번호 오류");
		return; 
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node -> vertex = v;
	node -> link = g -> adj_list[u];
	g -> adj_list[u] = node;
}

void dfs_list(StackType *s, GraphType *g, int v) {
	GraphNode *w;
    
    //첫번째 push는 vertex의 초기 매개변수값 0 삽입
    push(s,v);

    //지나간 adj_list TRUE 처리.
	visited[v] = TRUE;

    //원래 깊이우선탐색 list출력.
	printf("정점 %d -> ", v);
	
	for(w = g -> adj_list[v]; w; w = w -> link) {
		
        //노드를 방문했는지 안했는지 검사
        //visited[w - vertex] = TRUE || FALSE
		if(!visited[w -> vertex]) {
			dfs_list(s,g, w -> vertex);	
            // push(g, w -> vertex);
		}   
	}	

	for(int i = 0; i<4; i++) {
		printf("정점 %d -> ",pop(s));
	}
}


int main(void) {
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
    StackType *s;
	init_stack(s);

	init(g);
	for(int i = 0; i<4; i++) {
		insert_vertex(g, i);
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
	
	printf("깊이 우선 탐색\n");
	dfs_list(s, g, 0);
	printf("\n");
	
	free(g);
	
	return 0;
}