//���ڿ� ���Ḯ��Ʈ ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[100];
}element;

typedef struct ListNode
{
	element data;			//������ ���� 
	struct ListNode* link;  //��ũ ����
}ListNode;

//���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//���� ���� �Լ� 
ListNode* insert_first(ListNode* head, element item)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
//���� �Լ� 
ListNode* insert(ListNode* head, ListNode* pre, element item)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
//���� ���� �Լ� 
ListNode* delete_first(ListNode* head)
{
	if (head == NULL)
		return NULL;
	ListNode* rm;
	rm = head;
	head = rm->link;
	free(rm);
	return head;
}
//���� �Լ� 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* rm;
	rm = pre->link;
	pre->link = rm->link;
	free(rm);
	return head;
}
//��� �Լ�
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL\n");
}

int main()
{
	ListNode* head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	while (head != NULL)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}