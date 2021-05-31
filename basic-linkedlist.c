#include <stdio.h>
#include <stdlib.h>

typedef struct _element{ //단어 삽입 이므로 char 타입
    int len; //element를 구조체로 만들어서 단어이름으로 구분지금.
} element;

typedef struct _ListNode { //노드 타입
    element data;
    struct ListNode *link;
} ListNode;

//오류처리함수
void error(char *message) {
    fprintf(stderr,"%s\n",message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    p -> data = value; //(2)
    p -> link = head; //헤드 포인터의 값을 복사(3)
    head = p; //헤드 포인터 변경 (4)

    return head;
}

ListNode* create_node(element data) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(new_node));
	new_node->data = data;
	new_node->link = NULL;
	return new_node;
}

void print_list(ListNode *head) {
    ListNode *p;
    for(p = head; p != NULL; p = p -> link) {
        printf("%d -> ",p -> data);
    }
    printf("NULL \n");
}

ListNode *insert_last(ListNode *head,element item) {
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    ListNode *p;
    if(temp == NULL) {
        printf("메모리 할당 에러");
    }
    temp -> data = item;
    temp -> link = NULL;
    if(head == NULL) {
        head = temp;
    }
    else {
        p = head;
        while(p != NULL) {
            p = p -> link;
        }
        p -> link = temp;
    }

    return head;
}

int main(void) {
    ListNode *head = NULL;
    element data;
    int in;
    int t;
    printf("노드의 갯수 : ");
    scanf("%d", &in);

    element a;
    for(int i=0; i<in; i++) {
        printf("노드 #%d 데이터 :",i+1);
        scanf("%d",&a);
        head = insert_last(head, a);
    }

    print_list(head);
    return 0;
}