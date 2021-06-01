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
//전위 삭제 함수 
ListNode* delete_first(ListNode* head)
{
	ListNode* rm;
	if (head == NULL);                //노드가 0개일 때
	else                              //노드가 2개 이상
	{
		rm = head->link;
		head->link = rm->link;
		if (head == rm)               //노드가 1개일 때
			head = NULL;
		free(rm);
	}
	return head;
}

//노드의 개수를 세는 함수 
int count_node(ListNode* head)
{
	int cnt = 0;
	ListNode* p;
	
	if (head == NULL)
		return cnt;
	p = head->link;
	do
	{
		cnt++;
		p = p->link;
	} while (p != head->link);
	return cnt;
}

int main()
{
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	printf("노드의 개수: %d\n", count_node(head));
	return 0;
}