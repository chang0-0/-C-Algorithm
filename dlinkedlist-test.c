#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DLisNode { //이중연결 노드 타입
    element data;
    struct DLisNode *llink;
    struct DLisNode *rlink;
} DLisNode;

void init(DLisNode *phead) { 
    phead -> llink = phead;
    phead -> rlink = phead;
}



int main(void) {


    return 0;
}