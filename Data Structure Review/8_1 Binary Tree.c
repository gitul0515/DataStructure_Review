//연결리스트로 구현한 이진트리
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

int main()
{
	TreeNode* p;
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->llink = n2;
	n1->rlink = n3;
	n2->data = 20;
	n2->llink = NULL;
	n2->rlink = NULL;
	n3->data = 30;
	n3->llink = NULL;
	n3->rlink = NULL;

	free(n1); free(n2); free(n3);
}