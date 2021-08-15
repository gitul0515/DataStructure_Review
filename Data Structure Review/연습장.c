//���� ��ȸ ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* llink, * rlink;
}TreeNode;
//============= ����ť �ڵ� ���� =============
#define MAX_QUEUE_SIZE 10
typedef TreeNode* element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}QueueType;

//ť �ʱ�ȭ �Լ� 
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
//���� ó�� �Լ�
void queue_error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
}
//���� ���� �˻� �Լ� 
int is_empty(QueueType* q)
{
	return q->rear == q->front;
}
//��ȭ ���� �˻� �Լ� 
int is_full(QueueType* q)
{
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}
//���� �Լ� 
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		queue_error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
//���� �Լ� 
element dequeue(QueueType* q)
{
	if (is_empty(q))
		queue_error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
//��ũ �Լ� 
element peek(QueueType* q)
{
	if (is_empty(q))
		queue_error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
//ť ��� �Լ� 
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
//============= ����ť �ڵ� ���� =============
//���� ��ȸ �Լ�
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
	//���� �޸𸮸� �Ҵ�
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n6 = (TreeNode*)malloc(sizeof(TreeNode));

	/*����Ʈ�� ����
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

	printf("���� ��ȸ: ");
	level_order(root);
	printf("\n");

	free(n1); free(n2); free(n3);
	free(n4); free(n5); free(n6);
	return 0;
}