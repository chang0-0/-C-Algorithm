#include<stdio.h>
#include<stdlib.h>

typedef int element; //정수형태도 동일.
typedef struct DlistNode {
	element data;
	struct DlistNode* llink; //일반 이중 연결 리스트와 타입 동일.
	struct DlistNode* rlink;
}DlistNode;

void dinsert_node(DlistNode* before, DlistNode* new_node) {  //이중연결 리스트에 데이터를 삽입.
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) {
	if (removed == phead_node)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
}

void reverse_display(DlistNode* phead) {   //
	DlistNode* p;
	for (p = phead->llink; p != phead; p = p->llink) {
		printf("%d ", p->data);
	}
	printf("\n");
	return;
}

void init(DlistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void display(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("%d ", p->data);
	}
	printf("\n");
	return;
}

int main(void) {
	DlistNode list1 = {}; //배열만듬.
	DlistNode* p[10] = {};
	init(&list1);

	for (int i = 1; i <= 5; i++) {
		p[i] = (DlistNode*)malloc(sizeof(DlistNode));
		p[i]->data = i;
		dinsert_node(&list1, p[i]);
	}
	display(&list1);
	reverse_display(&list1);
}