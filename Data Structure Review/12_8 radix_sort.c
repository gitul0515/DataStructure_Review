//��� ���� ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//---------����ť �ڵ� ����---------
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//���� ó�� �Լ� 
void error_handling(char* message)
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
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error_handling("��ȭ ���� ����");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error_handling("���� ���� ����");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//��ũ �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error_handling("���� ���� ����");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//---------����ť �ڵ� ��---------
//---------��� ���� �ڵ� ����---------
#define NUM_SIZE 10      //����Ʈ�� ��� ����
#define BUCKET 10        //ť�� ����
#define DIGIT 4          //õ�� �ڸ����� �˻�

void radix_sort(int* list, int num)
{
	int i, j, k;
	int digit = 1;
	QueueType queue[BUCKET];        //�� ���� ť�� �迭�� ����

	for (i = 0; i < BUCKET; i++)
		init_queue(&queue[i]);      //������ ť�� �ʱ�ȭ

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < num; j++)   //�ڸ����� �´� ť�� ����
			enqueue(&queue[(list[j] / digit) % 10], list[j]);

		k = 0;
		for (j = 0; j < BUCKET; j++)  //ť���� ������ ����Ʈ�� ����
			while (!is_empty(&queue[j]))
				list[k++] = dequeue(&queue[j]);
		digit *= 10;
	}
}

int main()
{
	int i;
	int num = NUM_SIZE;
	int list[NUM_SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = rand() % 100;

	radix_sort(list, num);       //��� ���� ȣ��

	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}