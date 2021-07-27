//기수 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//---------원형큐 코드 시작---------
#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//오류 처리 함수 
void error_handling(char* message)
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
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error_handling("포화 상태 오류");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error_handling("공백 상태 오류");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//피크 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error_handling("공백 상태 오류");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//---------원형큐 코드 끝---------
//---------기수 정렬 코드 시작---------
#define NUM_SIZE 10      //리스트의 요소 개수
#define BUCKET 10        //큐의 개수
#define DIGIT 4          //천의 자리까지 검사

void radix_sort(int* list, int num)
{
	int i, j, k;
	int digit = 1;
	QueueType queue[BUCKET];        //열 개의 큐를 배열로 생성

	for (i = 0; i < BUCKET; i++)
		init_queue(&queue[i]);      //각각의 큐를 초기화

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < num; j++)   //자릿수에 맞는 큐에 삽입
			enqueue(&queue[(list[j] / digit) % 10], list[j]);

		k = 0;
		for (j = 0; j < BUCKET; j++)  //큐에서 꺼내어 리스트에 정렬
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

	radix_sort(list, num);       //기수 정렬 호출

	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}