//���� ���Ḯ��Ʈ ���α׷� 
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;          //������ ����
	struct ListNode* link;  //��ũ ����
}ListNode;

//���� ���� �Լ�
ListNode* insert_first(ListNode* head, element item)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = item;
	if (head == NULL)
	{
		head = new;
		new->link = head;
	}
	else
	{
		new->link = head->link;
		head->link = new;
	}
	return head;
}
//���� ���� �Լ�
ListNode* insert_last(ListNode* head, element item)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = item;
	if (head == NULL)
	{
		head = new;
		new->link = head;
	}
	else
	{
		new->link = head->link;
		head->link = new;
		head = new;
	}
	return head;
}
//��� �Լ�
void print_list(ListNode* head)
{
	if (head == NULL)
		return;
	ListNode* p;
	for (p = head->link; p != head; p = p->link)
		printf("%d->", p->data);
	printf("%d->\n", p->data);     //������ ��� ���
}

int main()
{
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}