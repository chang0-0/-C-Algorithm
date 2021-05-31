#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _element{ //단어 삽입 이므로 char 타입
    char name[100]; //element를 구조체로 만들어서 단어이름으로 구분지금.
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
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));

    newnode -> data = value; //(2)
    newnode -> link = head; //헤드 포인터의 값을 복사(3)
    head = newnode; //헤드 포인터 변경 (4)

    return head;
}

void print_list(ListNode *head) {
    ListNode *p;
    for(p = head; p != NULL; p = p -> link) {
        printf("%s ->",p -> data.name);
    }
    printf("NULL \n");
}


int main(void) {
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}