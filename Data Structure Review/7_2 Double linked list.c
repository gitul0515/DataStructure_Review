//���� ���Ḯ��Ʈ ���α׷�
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DListNode
{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

//�ʱ�ȭ �Լ� 
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}
//��� �Լ� 
void print_list(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n");
}
//���� �Լ� 
void dinsert(DListNode* before, element data)
{
	DListNode* new = (DListNode*)malloc(sizeof(DListNode));
	new->data = data;
	new->llink = before;
	new->rlink = before->rlink;
	before->rlink->llink = new;
	before->rlink = new;
}
//���� �Լ� 
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
	//�߰� �ܰ� 
	for (int i = 0; i < 5; i++)
	{
		//��� ����� �����ʿ� ����
		dinsert(head, i);
		print_list(head);
	}
	//����	
	for (int i = 0; i < 5; i++)
	{
		//��� ����� �������� ����
		print_list(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0; 
}