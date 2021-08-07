//���Ḯ��Ʈ�� ������ ť
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

//�ʱ�ȭ �Լ�
void init_queue(QueueListType* q)
{
	q->front = 0;
	q->rear = 0;
}
//���� ���� ���� �Լ� 
int is_empty(QueueListType* q)
{
	return q->front == NULL;
}
//��ȭ ���� ���� �Լ� 
int is_full(QueueListType* q)
{
	return 0;
}
//���� �Լ� 
void enqueue(QueueListType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q))     //������ ���
	{
		q->front = temp;
		q->rear = temp;
	}
	else                 //������ �ƴ� ���
	{
		q->rear->link = temp;
		q->rear = temp;
	}
}
//���� �Լ� 
element dequeue(QueueListType* q)
{
	if (is_empty(q))
	{
		fprintf(stderr, "ť�� ��������Դϴ�.\n");
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
//��� �Լ� 
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