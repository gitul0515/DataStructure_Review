//Ư���� ���� Ž���ϴ� �Լ�
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
//Ž�� �Լ� 
ListNode* explore(ListNode* head, element item)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		if (p->data == item)
			return p;
	}
	return NULL;
}
//��� �Լ� 
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main()
{
	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	if (explore(head, 40))
		printf("����Ʈ���� 40�� ã�ҽ��ϴ�.\n");
	else
		printf("����Ʈ���� 40�� ã�� ���߽��ϴ�.\n");
	return 0;
}