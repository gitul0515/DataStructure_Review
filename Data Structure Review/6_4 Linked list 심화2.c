//특정한 값을 탐색하는 함수
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
//탐색 함수 
ListNode* explore(ListNode* head, element item)
{
	for (ListNode* p = head; p != NULL; p = p->link)
	{
		if (p->data == item)
			return p;
	}
	return NULL;
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

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	if (explore(head, 40))
		printf("리스트에서 40을 찾았습니다.\n");
	else
		printf("리스트에서 40을 찾지 못했습니다.\n");
	return 0;
}