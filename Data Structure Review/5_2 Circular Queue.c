//원형큐 프로그램
#include <stdio.h>
#include <stdlib.h>

//============= 원형큐 코드 시작 =============
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//큐 초기화 함수 
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//오류 처리 함수
void queue_error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}
//공백 상태 검사 함수 
int is_empty(QueueType* q)
{
	return q->rear == q->front;
}
//포화 상태 검사 함수 
int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//삽입 함수 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		queue_error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//삭제 함수 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		queue_error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//피크 함수 
element peek(QueueType* q)
{
	if (is_empty(q))
		queue_error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//큐 출력 함수 
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
//============= 원형큐 코드 종료 =============

int main()
{
	QueueType queue;
	init_queue(&queue);
	element item;

	//큐에 정수를 삽입
	while (!is_full(&queue))
	{
		printf("정수 입력: ");
		scanf("%d", &item);
		enqueue(&queue, item);
		queue_print(&queue);
	}
	printf("\n");
	//모두 꺼내어 출력
	while (!is_empty(&queue))
	{
		printf("꺼낸 정수: %d\n", dequeue(&queue));
		queue_print(&queue);
	}
	return 0;
}