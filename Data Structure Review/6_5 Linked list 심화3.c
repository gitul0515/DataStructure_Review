//�� ���� ����Ʈ�� �ϳ��� �����ϴ� �Լ�
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
//��� �Լ� 
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//���� �Լ�
ListNode* concat_list(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	ListNode* p;
	for (p = head1; p->link != NULL; p = p->link);
	p->link = head2;
	return head1;
}

int main()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	//head1 ����Ʈ ����
	head1 = insert_first(head1, 30);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 10);
	print_list(head1);

	//head2 ����Ʈ ����
	head2 = insert_first(head2, 50);
	head2 = insert_first(head2, 40);
	print_list(head2);

	//�� ����Ʈ ����
	ListNode* total_head = concat_list(head1, head2);
	print_list(total_head);
	return 0;
}