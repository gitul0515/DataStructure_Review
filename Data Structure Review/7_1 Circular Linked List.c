//원형 연결리스트 프로그램
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode
{
	element data;           //데이터 영역
	struct ListNode* link;  //링크 영역
}ListNode;

//전위 삽입 함수 
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = data;
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
//후위 삽입 함수 
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = data;
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
//출력 함수 
void print_list(ListNode* head)
{
	if (head == NULL)
		return;

	ListNode* p;
	for (p = head->link; p != head; p = p->link)
		printf("%d->", p->data);
	printf("%d->\n", p->data);
}
//전위 삭제 함수 
ListNode* delete_first(ListNode* head)
{
	ListNode* rm;
	if (head == NULL);
	else
	{
		rm = head->link;
		head->link = rm->link;
		if (head == rm)
			head = NULL;
		free(rm);
	}
	return head;
}

int main()
{
	ListNode* head = NULL;

	head = insert_last(head, 1);
	head = insert_last(head, 2);
	head = insert_last(head, 3);
	print_list(head);

	while (head != NULL)
	{
		print_list(head);
		head = delete_first(head);
	}
	return 0;
}