//후위 삽입 함수, 특정한 값을 삭제하는 함수 추가
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
	ListNode* p;
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = data;
	if (head == NULL)
	{
		new_node->link = head;
		head = new_node;
	}
	else
	{
		for (p = head; p->link != NULL; p = p->link);
		new_node->link = p->link;
		p->link = new_node;
	}
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
//특정한 값을 삭제하는 함수 
ListNode* delete_node(ListNode* head, element data)
{
	ListNode* p, * pre;
	if (head == NULL)              //공백 상태
		return NULL;
	p = head;
	do
	{
		if (head->data == data)    //첫 노드를 삭제
		{
			ListNode* rm = head;
			head = rm->link;
			free(rm);
			p = head;
		}
		else if (p->data == data)  //첫 이외의 노드를 삭제
		{
			ListNode* rm = p;
			pre->link = rm->link;
			p = rm->link;
			free(rm);
		}
		else
		{
			pre = p;
			p = p->link;
		}
	} while (p != NULL);
	return head;
}


int main()
{
	ListNode* head = NULL;
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	print_list(head);

	head = delete_node(head, 2);
	print_list(head);

	return 0;
}