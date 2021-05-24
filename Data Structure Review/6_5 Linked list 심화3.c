//두 개의 리스트를 하나로 결합하는 함수
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
//출력 함수 
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
//결합 함수
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

	//head1 리스트 생성
	head1 = insert_first(head1, 30);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 10);
	print_list(head1);

	//head2 리스트 생성
	head2 = insert_first(head2, 50);
	head2 = insert_first(head2, 40);
	print_list(head2);

	//두 리스트 결합
	ListNode* total_head = concat_list(head1, head2);
	print_list(total_head);
	return 0;
}