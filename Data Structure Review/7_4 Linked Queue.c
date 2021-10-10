//���Ḯ��Ʈ�� ������ ť
#include<stdio.h>
#include<stdlib.h>

typedef int element;         //����� Ÿ��
typedef struct QueueNode {   //ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {             //ť�� ADT ����
	QueueNode* front, * rear;
}LinkedQueueType;

//ť �ʱ�ȭ �Լ� 
void init(LinkedQueueType* q)
{
	q->front = q->rear = 0;
}
//���� ���� ���� �Լ� 
int is_empty(LinkedQueueType* q)
{
	return q->front == NULL;
}
//��ȭ ���� ���� �Լ� 
int is_full(LinkedQueueType* q)
{
	return 0;
}
//���� �Լ� 
void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q))       //ť�� �����̸�
	{
		q->front = temp;
		q->rear = temp;
	}
	else                   //ť�� ������ �ƴϸ�
	{
		q->rear->link = temp;
		q->rear = temp;
	}
}
//���� �Լ�
element dequeue(LinkedQueueType* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "ť�� ��������Դϴ�.");
		exit(1);
	}
	QueueNode* rm = q->front;
	element data = rm->data;
	q->front = q->front->link;     
	if (q->front == NULL)		 //���� ����
		q->rear = NULL;
	free(rm);
	return data;
}
//ť ��� �Լ� 
void print_queue(LinkedQueueType* q)
{
	for (QueueNode* p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

//����� ť �׽�Ʈ �Լ�
int main() {
	LinkedQueueType queue;

	init(&queue);   //ť �ʱ�ȭ

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	return 0; 
}