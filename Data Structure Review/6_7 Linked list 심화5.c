//���� ���� �Լ�, Ư���� ���� �����ϴ� �Լ� �߰�
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;           //������ ����
	struct ListNode* link;  //��ũ ����
}ListNode;

//���� ó�� �Լ� 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//���� ���� �Լ� 
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//���� �Լ� 
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
//���� ���� �Լ� 
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* p;
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	if (head == NULL)
	{
		new_node->link = head;
		head = new_node;
	}
	else
	{
		for (p = head; p->link != NULL; p = p->link);
		new_node->link = p->link;
		p->link = new_node;
	}
	return head;
}
//���� ���� �Լ� 
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL)
		return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
//���� �Լ� 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
//��� �Լ� 
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//Ư���� ���� �����ϴ� �Լ� 
ListNode* delete_node(ListNode* head, element data)
{
	ListNode* p, * pre;
	if (head == NULL)              //���� ����
		return NULL;
	p = head;
	do
	{
		if (head->data == data)    //ù ��带 ����
		{
			ListNode* rm = head;
			head = rm->link;
			free(rm);
			p = head;
		}
		else if (p->data == data)  //ù �̿��� ��带 ����
		{
			ListNode* rm = p;
			pre->link = rm->link;
			p = rm->link;
			free(rm);
		}
		else
		{
			pre = p;
			p = p->link;
		}
	} while (p != NULL);
	return head;
}


int main()
{
	ListNode* head = NULL;
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	print_list(head);

	head = delete_node(head, 2);
	print_list(head);

	return 0;
}