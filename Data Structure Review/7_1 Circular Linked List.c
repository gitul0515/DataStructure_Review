//원형 연결리스트 프로그램 
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;          //데이터 영역
	struct ListNode* link;  //링크 영역
}ListNode;

//전위 삽입 함수
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
//후위 삽입 함수
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
//출력 함수
void print_list(ListNode* head)
{
	if (head == NULL)
		return;
	ListNode* p;
	for (p = head->link; p != head; p = p->link)
		printf("%d->", p->data);
	printf("%d->\n", p->data);     //마지막 노드 출력
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