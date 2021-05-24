//����ť ���α׷�
#include <stdio.h>
#include <stdlib.h>

//============= ����ť �ڵ� ���� =============
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//ť �ʱ�ȭ �Լ� 
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//���� ó�� �Լ�
void queue_error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}
//���� ���� �˻� �Լ� 
int is_empty(QueueType* q)
{
	return q->rear == q->front;
}
//��ȭ ���� �˻� �Լ� 
int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//���� �Լ� 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		queue_error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//���� �Լ� 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		queue_error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//��ũ �Լ� 
element peek(QueueType* q)
{
	if (is_empty(q))
		queue_error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//ť ��� �Լ� 
void queue_print(QueueType* q)
{
	printf("Queue(front = %d, rear = %d): ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//============= ����ť �ڵ� ���� =============

int main()
{
	QueueType queue;
	init_queue(&queue);
	element item;

	//ť�� ������ ����
	while (!is_full(&queue))
	{
		printf("���� �Է�: ");
		scanf("%d", &item);
		enqueue(&queue, item);
		queue_print(&queue);
	}
	printf("\n");
	//��� ������ ���
	while (!is_empty(&queue))
	{
		printf("���� ����: %d\n", dequeue(&queue));
		queue_print(&queue);
	}
	return 0;
}