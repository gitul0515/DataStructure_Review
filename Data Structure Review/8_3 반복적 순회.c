//반복을 사용한 중위 순회 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
// ==== 스택 코드의 시작 ====
#define STACK_MAX_SIZE 100
typedef int element;
typedef struct
{
	element data[STACK_MAX_SIZE];
	int top;
}Stacktype;

//초기화 함수 
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//공백 상태 검출 함수 
int is_empty(Stacktype* s)
{
	return s->top == -1;
}

//포화 상태 검출 함수 
int is_full(Stacktype* s)
{
	return s->top >= STACK_MAX_SIZE - 1;
}

//삽입 함수 
void push(Stacktype* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화 상태 에러 \n");
		return;
	}
	s->data[++(s->top)] = item;
}

//삭제 함수 
element pop(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 상태 에러 \n");
		exit(1);
	}
	return s->data[(s->top)--];
}

//피크 함수 
element peek(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 상태 에러 \n");
		exit(1);
	}
	return s->data[s->top];
}
// ==== 스택 코드의 끝 ====
typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;

void inorder(Stacktype* s, TreeNode* root)
{



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
	TreeNode* root = n6;

	/*이진트리 생성
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