//레벨 순회 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;
//============= 원형큐 코드 시작 =============
#define MAX_QUEUE_SIZE 10
typedef TreeNode* element;
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
//레벨 순회 함수
void level_order(TreeNode* root)
{
	QueueType queue;
	init_queue(&queue);

	if (root == NULL)
		return;
	enqueue(&queue, root);
	while (!is_empty(&queue))
	{
		element p = dequeue(&queue);
		printf("[%d] ", p->data);
		if (p->llink)
			enqueue(&queue, p->llink);
		if (p->rlink)
			enqueue(&queue, p->rlink);
	}
}

int main()
{
	//동적 메모리를 할당
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));

	/*이진트리 생성
			 15
		  4 	 20
		1    16     25
	*/
	n1->data = 1; n1->llink = NULL; n1->rlink = NULL;
	n2->data = 4; n2->llink = n1; n2->rlink = NULL;
	n3->data = 16; n3->llink = NULL; n3->rlink = NULL;
	n4->data = 25; n4->llink = NULL; n4->rlink = NULL;
	n5->data = 20; n5->llink = n3; n5->rlink = n4;
	n6->data = 15; n6->llink = n2; n6->rlink = n5;
	TreeNode* root = n6;

	printf("레벨 순회: ");
	level_order(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	return 0;
}