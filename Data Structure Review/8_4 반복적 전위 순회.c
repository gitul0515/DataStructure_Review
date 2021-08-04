//반복적 전위 순회 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

#define MAX_SIZE 100
int top = -1;
TreeNode* stack[MAX_SIZE];

void push(TreeNode* p)
{
	if (top < MAX_SIZE - 1)
		stack[++top] = p;
}
TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}
void preorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->llink)
		{
			printf("[%d] ", root->data);
			push(root);
		}
		root = pop();
		if (!root) break;
		root = root->rlink;
	}
}
int main()
{
	//동적 메모리를 할당
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n7 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n8 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n9 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* root = n6;

	n1->data = 1; n1->llink = NULL; n1->rlink = NULL;
	n2->data = 4; n2->llink = n1; n2->rlink = n7;
	n3->data = 16; n3->llink = NULL; n3->rlink = NULL;
	n4->data = 25; n4->llink = NULL; n4->rlink = NULL;
	n5->data = 20; n5->llink = n3; n5->rlink = n4;
	n6->data = 15; n6->llink = n2; n6->rlink = n5;
	n7->data = 2; n7->llink = n8; n7->rlink = NULL;
	n8->data = 7; n8->llink = n9; n8->rlink = NULL;
	n9->data = 9; n9->llink = NULL; n9->rlink = NULL;

	printf("전위 순회=");
	preorder_iter(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	free(n7); free(n8); free(n9);
	return 0;
}