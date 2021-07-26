//기수 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//-------------원형큐 코드 시작------------
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

//오류 처리 함수 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수 
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//공백 상태 검출 함수 
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}
//포화 상태 검출 함수
int is_full(QueueType* q)
{
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}
//삽입 함수 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("포화 상태 오류");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//삭제 함수 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("공백 상태 오류");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//피크 함수 
element peek(QueueType* q)
{
	if (is_empty(q))
		error("공백 상태 오류");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//-------------원형큐 코드 종료---------
//------------기수 정렬 코드 시작-----------
#define BUCKETS 10
#define DIGITS 4
#define SIZE 10

void radix_sort(int* list, int num)
{
	QueueType bucket[BUCKETS];     //10개의 큐 생성
	int i, j, digit;
	digit = 1;                     //일의 자리부터 정렬

	for (i = 0; i < BUCKETS; i++)
		init_queue(&bucket[i]);    //큐들의 초기화

	while (digit <= 10)            //십의 자리까지 정렬
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
