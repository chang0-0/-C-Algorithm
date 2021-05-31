#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode { //리스트를 구성하는 노드들이 어떻게 구성되있는지 부터 생각해야됨.
    int coef; // 계수
    int expon; //지수
    struct ListNode *link; //자기참조구조체
}ListNode;

//다음 리스트자체의 타입구조를생각한다.
//1.리스트 자체의 사이즈 2.리스트 노드의 첫번째인 head 3.리스트 노드의 마지막인 tail
//head와 tail은 구조체를 쓰기위해 포인터를 사용
typedef struct _ListType {
    int size;
    ListNode *head;
    ListNode *tail;
}ListType;

//오류함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//다항식 계산을 하기위해 다항식을 넣을 리스트를 생성하는 함수
//반환형식은 list형식을 가지기위해 ListType 구조체를 지정.
ListType* create(){
    ListType *plist = (ListType *)malloc(sizeof(ListType)); 
    //동적으로 크기를 변화하는 리스트를 생성한다.
    plist -> size = 0;
    plist -> head = plist -> tail = NULL; //새로 비어있는 리스트이므로
    //헤드와 꼬리의 값이 빈 NULL값으로 지정한다.

    return plist;
}

void insert_last(ListType *plist, int coef, int expon) { //리스트의 노드에 값을 넣는 함수
    //노드를 담을 리스트의 주소를 가진 포인터 변수와, 노드에들어갈 계수와 지수
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));

    if(temp == NULL) { //temp가 비어있을경우.
        error("메모리 할당 에러");
    }

    temp -> coef = coef;
    temp -> expon = expon;
    temp -> link = NULL;

    if(plist -> tail == NULL) {
        plist -> head = plist -> tail = temp;
    }
    else {
        plist -> tail -> link = temp;
        plist -> tail = temp;
    }
    plist -> size ++;
}

//다항식 연산을 실행함.
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
    ListNode* a = plist1 -> head;
    ListNode* b = plist2 -> head;
    int sum;

    /*다항식 덧셈을 하는 단계
    1.지수가 같은 계수끼리 덧셈을 실행하므로 일단, 2식의 지수가 어떤 관계인지를 파악해야됨.
    2.지수가 같을 경우 바로 계수끼리 덧셈을 진행하고, 덧셈의 값이 0이 아닐경우 plist3의 노드에 값을 추가시킨다.
    3.또는 지수의 크기가 서로다를경우 비교를 진행해서 지수가 큰쪽을 먼저 plist3에 넣어준다.
    4.마지막으로 두 다항식의 길이가 다를경우 남아있는 한쪽의 식을 차례대로 plist3에 넣어준다.
    다항식 덧셈 완성.
    */

    while(a && b) { //a와 b가 모두 참이어야하므로 a b 다항식을 길이가 같은부분까지만 반복실행.
        if(a -> expon == b -> expon) {
            sum = a -> coef + b -> coef;
            if(sum != 0) {
                insert_last(plist3, sum, a -> expon);
            }
            a = a -> link;
            b = b -> link;
        }
        else if(a -> expon > b -> expon) {
            insert_last(plist3, a -> coef, a -> expon);
            a = a -> link;
        }
        else {
            insert_last(plist3, b -> coef, b -> expon);
            b = b -> link;
        }
    }
    

    for(; a!=  NULL; a = a -> link) {
        insert_last(plist3, a->coef, a -> expon);
    }
    for(; b!= NULL; b = b -> link) {
        insert_last(plist3, b -> coef, b -> expon);
    }
}

void poly_print(ListType* plist) {
    ListNode* p = plist -> head;

    printf("polynomail = ");
    for(; p;p = p -> link) {
        printf("%d^%d + ", p -> coef, p -> expon);
    }
    printf("\n");

    // while(p!=0) {
    //     printf("%d^%d + ", p -> coef, p -> expon);
    //     p -> link;
    // }
    // printf("\n");
}

int main(void) {
    ListType *list1, *list2, *list3;

    //연결 리스트 헤더 생성
    list1 = create();
    list2 = create();
    list3 = create();

    //다항식 1을 생성
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    //다항식 2를 생성
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    //다항식3 = 다항식1 + 다항식 2
    poly_add(list1, list2, list3);
    poly_print(list3);

    free(list1); 
    free(list2);
    free(list3);

    return 0;
}