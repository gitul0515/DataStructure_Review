//단순 연결리스트 프로그램 
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;           //데이터 영역
	struct ListNode* link;  //링크 영역
}ListNode;

//오류 처리 함수 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//전위 삽입 함수 
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
//삽입 함수 
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
//후위 삽입 함수 
ListNode* insert_last(ListNode* head, element data)
{
	//첫 노드일 경우 
	if (head == NULL)
		return insert_first(head, data);

	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	ListNode* pre;
	new->data = data;
	for (pre = head; pre->link != NULL; pre = pre->link);
	new->link = pre->link;
	pre->link = new;
	return head;
}
//전위 삭제 함수 
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
//삭제 함수 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
//후위 삭제 함수 
ListNode* delete_last(ListNode* head)
{
	if (head == NULL)
		return NULL;
	else if (head->link == NULL)        //첫 노드일 경우
		return delete_first(head);

	ListNode* rm, * pre;
	for (pre = head; (pre->link)->link != NULL; pre = pre->link);
	rm = pre->link;
	pre->link = rm->link;
	free(rm);
	return head;
}
//출력 함수 
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int main()
{
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	return 0; 
}