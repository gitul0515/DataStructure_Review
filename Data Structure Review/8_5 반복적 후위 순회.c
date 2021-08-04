#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
	int p_cnt;       //스택에서 꺼내어 검사한 횟수
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
TreeNode* peek()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top];
	return p;
}

void postorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->llink)
			push(root);
		root = peek();
		if (!root) break;
		if (root->rlink && root->p_cnt == 0)
		{
			root->p_cnt += 1;
			root = root->rlink;
		}
		else
		{
			root = pop();
			printf("[%d] ", root->data);
			root = NULL;
		}
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
	TreeNode* root = n6;

	n1->data = 1; n1->llink = NULL; n1->rlink = NULL; n1->p_cnt = 0;
	n2->data = 4; n2->llink = n1; n2->rlink = n7; n2->p_cnt = 0;
	n3->data = 16; n3->llink = NULL; n3->rlink = NULL; n3->p_cnt = 0;
	n4->data = 25; n4->llink = NULL; n4->rlink = NULL; n4->p_cnt = 0;
	n5->data = 20; n5->llink = n3; n5->rlink = n4; n5->p_cnt = 0;
	n6->data = 15; n6->llink = n2; n6->rlink = n5; n6->p_cnt = 0;
	n7->data = 2; n7->llink = NULL; n7->rlink = NULL; n7->p_cnt = 0;

	printf("후위 순회=");
	postorder_iter(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6); free(n7);
	return 0;
}