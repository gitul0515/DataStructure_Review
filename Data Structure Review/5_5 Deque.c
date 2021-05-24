//���� �� ���α׷� 
#include<stdio.h>
#include<stdlib.h>

#define MAX_DEQUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
}DequeType;

//���� ó�� �Լ� 
void deque_error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}

//�� �ʱ�ȭ �Լ� 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}
//���� ���� �˻� �Լ� 
int is_empty(DequeType* q)
{
	return q->rear == q->front;
}
//��ȭ ���� �˻� �Լ� 
int is_full(DequeType* q)
{
	return (q->rear + 1) % MAX_DEQUE_SIZE == q->front;
}
//�� ��� �Լ� 
void deque_print(DequeType* q)
{
	printf("DEQUE(front = %d, rear = %d): ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_DEQUE_SIZE;
			printf("%d|", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//���� ���� �Լ�(enqueue)
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		deque_error("��ȭ ���� ����");
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}
//���� ���� �Լ�(dequeue, pop)
element delete_front(DequeType* q)
{
	if (is_empty(q))
		deque_error("���� ���� ����");
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	return q->data[q->front];
}
//���� Ȯ�� �Լ�(peek)
element get_front(DequeType* q)
{
	if (is_empty(q))
		deque_error("���� ���� ����");
	return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}
//���� ���� �Լ�(push)
void add_front(DequeType* q, element item)
{
	if (is_full(q))
		deque_error("��ȭ ���� ����");
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}
//���� ���� �Լ�
element delete_rear(DequeType* q)
{
	if (is_empty(q))
		deque_error("���� ���� ����");
	element item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return item;
}
//���� Ȯ�� �Լ�
element get_rear(DequeType* q)
{
	if (is_empty(q))
		deque_error("���� ���� ����");
	return q->data[q->rear];
}

int main()
{
	DequeType queue;
	init_deque(&queue);
	int i;

	for (i = 0; i < 3; i++)
	{
		add_front(&queue, i + 1);
		deque_print(&queue);
	}
	for (i = 0; i < 3; i++)
	{
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0; 
}