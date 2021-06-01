//이중 연결리스트 프로그램
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

//초기화 함수 
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
//출력 함수 
void print_list(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n");
}
//삽입 함수 
void dinsert(DListNode* before, element data)
{
	DListNode* new = (DListNode*)malloc(sizeof(DListNode));
	new->data = data;
	new->llink = before;
	new->rlink = before->rlink;
	before->rlink->llink = new;
	before->rlink = new;
}
//삭제 함수 
void ddelete(DListNode* head, DListNode* rm)
{
	if (rm == head) return;
	rm->llink->rlink = rm->rlink;
	rm->rlink->llink = rm->llink;
	free(rm);
}

int main()
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);	
	//추가 단계 
	for (int i = 0; i < 5; i++)
	{
		//헤드 노드의 오른쪽에 삽입
		dinsert(head, i);
		print_list(head);
	}
	//삭제	
	for (int i = 0; i < 5; i++)
	{
		//헤드 노드의 오른쪽을 삭제
		print_list(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0; 
}