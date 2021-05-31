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
// TreeNode n1 = { 1, NULL, NULL };
// TreeNode n2 = { 4, &n1, NULL };
// TreeNode n3 = { 16, NULL, NULL };
// TreeNode n4 = { 25, NULL, NULL };
// TreeNode n5 = { 20, &n3, &n4 };
// TreeNode n6 = { 15, &n2, &n5 };
// TreeNode *root = &n6;

//교재 순회 테스트
TreeNode n11 = {9, NULL, NULL}; 
TreeNode n10 = {5, NULL, NULL};
TreeNode n9 = {7, NULL, NULL};
TreeNode n8 = {6, NULL, NULL};
TreeNode n7 = {12,NULL, NULL};
TreeNode n6 = {11, NULL, NULL};
TreeNode n5 = {6, &n10, &n11};
TreeNode n4 = {4, &n8, &n9 };
TreeNode n3 = {10, &n6, &n7 };
TreeNode n2 = {2, &n4, &n5 };
TreeNode n1 = {1, &n2, &n3 };

TreeNode *root = &n1;
int sum = 0;


//root를 멤버 포인터 변수로 줄때 트리는 거꾸로 뒤집어서 표현해야됨. 
//그래야 링크가 연결됨
//트리전체를 root로 볼수있고 root는 전역 포인터 변수

//중위 순회
int inorder(TreeNode *root) {

    if(root != NULL) {
        sum += root -> data;
        inorder(root -> left);  //왼쪽 서브트리 순회
        printf("[%d] ", root -> data); //노드 방문
        inorder(root -> right); //오른쪽 서브트리 순회
    }

    return sum;
}

//전위 순회
void preorder(TreeNode *root) {
    if(root != NULL) {
        printf("[%d] ", root -> data); //노드 방문
        preorder(root -> left);         //왼쪽 서브트리 순회
        preorder(root -> right);        //오른쪽 서브트리 순회
    }
}

//후위 순회
void postorder(TreeNode *root) {
    if(root != NULL) {
       postorder(root -> left);       // 왼쪽 서브트리 순회
       postorder(root -> right);      // 오른쪽 서브트리 순회
       printf("[%d] ", root -> data); //노드 방문

    }

}

int main(void) {
    printf("중위 순회=");
    int sum = inorder(root);
    printf("\n");

    printf("전위 순회=");
    preorder(root);
    printf("\n");

    printf("후위 순회=");
    postorder(root);
    printf("\n트리전체 합 = %d", sum);
    printf("\n");

    return 0;
}