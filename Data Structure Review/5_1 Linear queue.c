//선형큐 
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct queuetype
{
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//큐 초기화 함수 
void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;
}
//오류 함수 
void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}
//공백 상태 검출 함수 
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}
//포화 상태 검출 함수 
int is_full(QueueType* q)
{
	return q->rear == MAX_QUEUE_SIZE - 1;
}
//삽입 함수 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[++(q->rear)] = item;
}
//삭제 함수 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[++(q->front)];
}
//피크 함수 
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->front + 1];
}
//큐 출력 함수 
void queue_print(QueueType* q)
{
	int i; 
	for (i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)
			printf("  |");
		else
			printf("%d|", q->data[i]);
	}
	printf("\n");
}

int main()
{
	int item = 0;
	QueueType q;

	init_queue(&q); 
	
	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	peek(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);
	dequeue(&q); queue_print(&q);

	return 0; 
}