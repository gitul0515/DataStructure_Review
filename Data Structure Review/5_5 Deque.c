//원형 덱 프로그램 
#include<stdio.h>
#include<stdlib.h>

#define MAX_DEQUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_DEQUE_SIZE];
	int front, rear;
}DequeType;

//오류 처리 함수 
void deque_error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}

//덱 초기화 함수 
void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}
//공백 상태 검사 함수 
int is_empty(DequeType* q)
{
	return q->rear == q->front;
}
//포화 상태 검사 함수 
int is_full(DequeType* q)
{
	return (q->rear + 1) % MAX_DEQUE_SIZE == q->front;
}
//덱 출력 함수 
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
//후위 삽입 함수(enqueue)
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		deque_error("포화 상태 에러");
	q->rear = (q->rear + 1) % MAX_DEQUE_SIZE;
	q->data[q->rear] = item;
}
//전위 삭제 함수(dequeue, pop)
element delete_front(DequeType* q)
{
	if (is_empty(q))
		deque_error("공백 상태 에러");
	q->front = (q->front + 1) % MAX_DEQUE_SIZE;
	return q->data[q->front];
}
//전위 확인 함수(peek)
element get_front(DequeType* q)
{
	if (is_empty(q))
		deque_error("공백 상태 에러");
	return q->data[(q->front + 1) % MAX_DEQUE_SIZE];
}
//전위 삽입 함수(push)
void add_front(DequeType* q, element item)
{
	if (is_full(q))
		deque_error("포화 상태 에러");
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}
//후위 삭제 함수
element delete_rear(DequeType* q)
{
	if (is_empty(q))
		deque_error("공백 상태 에러");
	element item = q->data[q->rear];
	q->rear = (q->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
	return item;
}
//후위 확인 함수
element get_rear(DequeType* q)
{
	if (is_empty(q))
		deque_error("공백 상태 에러");
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