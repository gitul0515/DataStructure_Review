//�ݺ��� ����� ���� ��ȸ ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
// ==== ���� �ڵ��� ���� ====
#define STACK_MAX_SIZE 100
typedef int element;
typedef struct
{
	element data[STACK_MAX_SIZE];
	int top;
}Stacktype;

//�ʱ�ȭ �Լ� 
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//���� ���� ���� �Լ� 
int is_empty(Stacktype* s)
{
	return s->top == -1;
}

//��ȭ ���� ���� �Լ� 
int is_full(Stacktype* s)
{
	return s->top >= STACK_MAX_SIZE - 1;
}

//���� �Լ� 
void push(Stacktype* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "��ȭ ���� ���� \n");
		return;
	}
	s->data[++(s->top)] = item;
}

//���� �Լ� 
element pop(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	return s->data[(s->top)--];
}

//��ũ �Լ� 
element peek(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	return s->data[s->top];
}
// ==== ���� �ڵ��� �� ====
typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

void inorder(Stacktype* s, TreeNode* root)
{



}

int main()
{
	//���� �޸𸮸� �Ҵ�
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* root = n6;

	/*����Ʈ�� ����
			 15
		  4 	 20
		1    16     25
	*/
	n1->data = 1; n1->llink = NULL; n1->rlink = NULL;
	n2->data = 4; n2->llink = n1; n2->rlink = NULL;
	n3->data = 16; n3->llink = NULL; n3->rlink = NULL;
	n4->data = 25; n4->llink = NULL; n4->rlink = NULL;
	n5->data = 20; n5->llink = n3; n5->rlink = n4;
	n6->data = 15; n6->llink = n2; n6->rlink = n5;

	inorder(root);

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	return 0;
}