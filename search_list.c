#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

typedef struct Count {
    element result;
    element count;
} Count;

ListNode *insert_first(ListNode *head, element data) {
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));

    p -> data = data;
    p -> link = head;
    head = p;

    return head;
}

Count search_list(ListNode *head, element value) {
    element result;
    ListNode *p = head;
    element count = 0;
    Count c1;

    while(p != NULL) {  
        count ++;
        if(p->data == value){
            c1.result = value;
            c1.count = count;

            return c1;
        }
        p = p -> link;
    }

    return c1 = NULL;
}

void print_list(ListNode *head) {
    ListNode *p;

    for(p = head; p != NULL; p = p -> link) {
        printf("%d -> ",p -> data);
    }
    printf("NULL \n");
}

int main(void) {
    ListNode *head = NULL;
    int a = 0;
    int result = 0;
    Count c2;

    head = insert_first(head, 30);
    head = insert_first(head, 20);
    head = insert_first(head, 10);
    print_list(head);

    printf("찾을 숫자를 입력하세요 : ");
    scanf("%d",&a);  n

    c2 = search_list(head,a);

    printf("찾은 값 %d 는 %d 번째에 있음", c2.result, c2.count);

    free(head);

    return 0;
}