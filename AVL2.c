#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

#define MAX(a,b) ((a>b)?a:b)
#define MAX_SIZE 500

int list[MAX_SIZE];
int n;

typedef int element;

typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *LL_rotate(treeNode *parent) {
    treeNode *child = parent -> left;
    parent -> left = child -> right;
    child -> right = parent;

    return child;
}

treeNode *RR_rotate(treeNode *parent) {
    treeNode *child = parent -> right;
    parent -> right = child -> left;
    child -> left = parent;

    return child;
}

treeNode *LR_rotate(treeNode *parent) {
    treeNode *child = parent -> left;
    parent -> left = RR_rotate(child);

    return LL_rotate(parent);
}

treeNode *RL_rotate(treeNode *parent) {
    treeNode *child = parent -> right;
    parent -> right = LL_rotate(child);

    return RR_rotate(parent);
}

//서브 트리의 높이를 구하는 연산
int getHeight(treeNode *p) {
    int height = 0;
    if(p != NULL) {
        height = MAX(getHeight(p -> left), getHeight(p -> right)) + 1;
    }
    printf("높이는 = %d \n",height);
    return height;
}

//서브 트리의 높이를 이용해 균현 인수 BF를 구하는 연산
int  getBF(treeNode *p) {
    if(p == NULL) {
        return 0;
    }

    return getHeight(p -> left) - getHeight(p -> right);
}

//BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출
treeNode *rebalance(treeNode **p) {
    int BF = getBF(*p);
    if(BF > 1) {
        if(getBF((*p) -> left) > 0) {
            *p = LL_rotate(*p);
        }
        else {
            *p = LR_rotate(*p);
        }
    }
    else if(BF < -1) {
        if(getBF((*p) -> right) < 0) {
            *p = RR_rotate(*p);
        }
        else {
            *p = RL_rotate(*p);
        }
    }

    return *p;
}

//AVL 트리에 노드를 삽입하는 연산: 이진 탐색 연산처럼 삽입한 후에, rebalance()
treeNode *insert_AVL_Node(treeNode** root, element x) {
    if(*root == NULL) {
        *root = (treeNode*)malloc(sizeof(treeNode));
        (*root) -> key = x;
        (*root) -> left = NULL;
        (*root) -> right = NULL;
    }
    else if(x < (*root) -> key) {
        (*root) -> left = insert_AVL_Node(&((*root) -> left), x);
        *root = rebalance(root);
    }
    else if(x >(*root) -> key) {
        (*root) -> right = insert_AVL_Node(&((*root) -> right), x);
        *root = rebalance(root);
    }
    else {
        printf("\n 이미 같은 키가 있습니다! \n");
        exit(1);
    }

    return *root;
}

//이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode *root) {
    if(root) {
        displayInorder(root -> left);
        printf("_%d ", root -> key);
        displayInorder(root -> right);
    }
}

int main(void) {
    treeNode *root_AVL = NULL;
    //treeNode *root_BST = NULL;

    int i;
    n = MAX_SIZE;
    srand(time(NULL));

    for(i=0; i<n; i++) {
        list[i] = rand() % 10000;  //100
        printf("%d ", list[i]);
    }



    root_AVL = insert_AVL_Node(&root_AVL, list[0]);

    for(i = 1; i<n; i++) {
        insert_AVL_Node(&root_AVL, list[i]);
    }

    // insert_AVL_Node(&root_AVL, 20);
    // insert_AVL_Node(&root_AVL, 30);
    // insert_AVL_Node(&root_AVL, 40);
    // insert_AVL_Node(&root_AVL, 50);
    // insert_AVL_Node(&root_AVL, 60);
    // insert_AVL_Node(&root_AVL, 70);
    // insert_AVL_Node(&root_AVL, 90);
    // insert_AVL_Node(&root_AVL, 80);
    //insert_AVL_Node(&root_AVL, 29);

    printf("\n **************** AVL 트리 출력 **************** \n\n");
    displayInorder(root_AVL);

    getchar();

    return 0;
} 