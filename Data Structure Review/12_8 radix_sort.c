//��� ���� ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//-------------����ť �ڵ� ����------------
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//���� ó�� �Լ� 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//�ʱ�ȭ �Լ� 
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//���� ���� ���� �Լ� 
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}
//��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}
//���� �Լ� 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("��ȭ ���� ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//���� �Լ� 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("���� ���� ����");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//��ũ �Լ� 
element peek(QueueType* q)
{
	if (is_empty(q))
		error("���� ���� ����");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//-------------����ť �ڵ� ����---------
//------------��� ���� �ڵ� ����-----------
#define BUCKETS 10
#define DIGITS 4
#define SIZE 10

void radix_sort(int* list, int num)
{
	QueueType bucket[BUCKETS];     //10���� ť ����
	int i, j, digit;
	digit = 1;                     //���� �ڸ����� ����

	for (i = 0; i < BUCKETS; i++)
		init_queue(&bucket[i]);    //ť���� �ʱ�ȭ

	while (digit <= 10)            //���� �ڸ����� ����
	{
		for (i = 0; i < num; i++)
			enqueue(&bucket[(list[i] / digit) % 10], list[i]);

		i = 0;
		for (j = 0; j < BUCKETS; j++)
			while (!is_empty(&bucket[j]))
				list[i++] = dequeue(&bucket[j]);
		digit *= 10;
	}
}

int main()
{
	int i;
	int num = SIZE;
	int list[SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = rand() % 100;
	radix_sort(list, num);

	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}
