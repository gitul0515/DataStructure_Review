//���� Ʈ��
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

int main()
{
	TreeNode* n1, * n2, * n3, * n4;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10;
	n1->llink = NULL;
	n1->rlink = n2;
	n2->data = 20;
	n2->llink = NULL;
	n2->rlink = n3;
	n3->data = 30;
	n3->llink = n4;
	n3->rlink = NULL;
	n4->data = 25;
	n4->llink = NULL;
	n4->rlink = NULL;
	free(n1); free(n2); free(n3); free(n4);
	return 0; 
}