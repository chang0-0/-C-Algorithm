#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//      15
//  4        20
//1       16     25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode *root = &n6;

void postorder(TreeNode *root) {
    if(root != NULL) {
       postorder(root -> left);       // 왼쪽 서브트리 순회
       postorder(root -> right);      // 오른쪽 서브트리 순회
       printf("[%d] ", root -> data); //노드 방문
    }f
}

int main(void) {
    printf("중위 순회 : ");
    

    return 0;
}