//문자열 연결리스트 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char name[100];
}element;

typedef struct ListNode
{
	element data;			//데이터 영역 
	struct ListNode* link;  //링크 영역
}ListNode;

//오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//전위 삽입 함수 
ListNode* insert_first(ListNode* head, element item)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = head;
	head = p;
	return head;
}
//삽입 함수 
ListNode* insert(ListNode* head, ListNode* pre, element item)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = item;
	p->link = pre->link;
	pre->link = p;
	return head;
}
//전위 삭제 함수 
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
//삭제 함수 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* rm;
	rm = pre->link;
	pre->link = rm->link;
	free(rm);
	return head;
}
//출력 함수
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