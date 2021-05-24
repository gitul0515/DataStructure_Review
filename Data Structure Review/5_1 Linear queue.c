//����ť 
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

//ť �ʱ�ȭ �Լ� 
void init_queue(QueueType* q)
{
	q->front = -1;
	q->rear = -1;
}
//���� �Լ� 
void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}
//���� ���� ���� �Լ� 
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}
//��ȭ ���� ���� �Լ� 
int is_full(QueueType* q)
{
	return q->rear == MAX_QUEUE_SIZE - 1;
}
//���� �Լ� 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[++(q->rear)] = item;
}
//���� �Լ� 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[++(q->front)];
}
//��ũ �Լ� 
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->front + 1];
}
//ť ��� �Լ� 
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