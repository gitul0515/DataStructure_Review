//연결리스트로 구현한 큐
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef int element;
typedef struct QueueNode{
	element data;
	struct QueueNode* link;
}QueueNode;
typedef struct {
	QueueNode* front;
	QueueNode* rear;
}QueueListType;

//초기화 함수
void init_queue(QueueListType* q)
{
	q->front = 0;
	q->rear = 0;
}
//공백 상태 검출 함수 
int is_empty(QueueListType* q)
{
	return q->front == NULL;
}
//포화 상태 검출 함수 
int is_full(QueueListType* q)
{
	return 0;
}
//삽입 함수 
void enqueue(QueueListType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q))     //공백일 경우
	{
		q->front = temp;
		q->rear = temp;
	}
	else                 //공백이 아닐 경우
	{
		q->rear->link = temp;
		q->rear = temp;
	}
}
//삭제 함수 
element dequeue(QueueListType* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "큐가 공백상태입니다.\n");
		exit(1);
	}

	QueueNode* rm = (QueueNode*)malloc(sizeof(QueueNode));
	element data = rm->data;
	q->front = q->front->link;
	if (q->front == NULL)
		q->rear = NULL;
	free(rm);
	return data;
}
//출력 함수 
void print_queue(QueueListType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	QueueListType queue;

	init_queue(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	return 0; 
}