#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

void error(char *message) {
	fprintf(stderr,"%s \n",message);
	exit(1);
}

ListNode* insert_first(ListNode *head, int value) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p -> data = value;
	p -> link = head;
	head = p;
	
	return head;
}

void print_list(ListNode *head) {
	for(ListNode *p = head; p != NULL; p = p->link) {
		printf("(%d)->",p->data);
	}
	printf(" NULL \n");
}

int find_max(ListNode *head) {
	ListNode *p = NULL;
	p = head;
	int result = 0;
	int temp = 0;

	while(p != NULL) {
		result = p -> data;
		if(temp < result) {
			temp = result;
		}
		else {
			temp;
		}
		p = p -> link;
	}
	
	return temp;
}

int find_min(ListNode *head) {
	ListNode *p = NULL;
	p = head;
	int result = 0;
	int temp = 0;
	
	temp = p -> data; 
	while(p != NULL) {
		result = p -> data;
		if(temp > result) {
			temp = result;
		}
		else {
			temp;
		}
		p = p -> link;
	}
	
	return temp;
}

int main(void) {
	int a;
	ListNode *head = NULL;
	
	head = insert_first(head, 4);
	head = insert_first(head, 5);
	head = insert_first(head, 6);
    head = insert_first(head, 2);
    head = insert_first(head, 16);
    head = insert_first(head, 0);

	print_list(head);
	
	a = find_max(head);	
	printf("max = %d , ",a);
	
	int b = find_min(head);	
	printf("min = %d",b);
	
	return 0;
}