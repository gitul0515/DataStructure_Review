//���� ����Ʈ�� ������ ����
#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode
{
	element data;             //������ ����
	struct StackNode* link;   //��ũ ����
}StackNode;

typedef struct
{
	StackNode* top;
}LinkedStackType;

//���� ó�� �Լ� 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//�ʱ�ȭ �Լ� 
void init(LinkedStackType* s)
{
	s->top = NULL;
}
//���� ���� ���� �Լ� 
int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}
//��ȭ ���� ���� �Լ� 
int is_full(LinkedStackType* s)
{
	return 0;
}
//���� �Լ� 
void push(LinkedStackType* s, element item)
{
	if (is_full(s))
		error("��ȭ ���� ����");

	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	new->data = item;
	new->link = s->top;
	s->top = new;
}
//���� �Լ� 
element pop(LinkedStackType* s)
{
	if (is_empty(s))
		error("���� ���� ����\n");

	StackNode* temp = s->top;
	element data = s->top->data;
	s->top = s->top->link;
	free(temp);
	return data;
}

//��ũ �Լ� 
element peek(LinkedStackType* s)
{
	if (is_empty(s))
		error("���� ���� ����\n");
	return s->top->data;
}

//��� �Լ� 
void print_stack(LinkedStackType* s)
{
	for (StackNode* temp = s->top; temp != NULL; temp = temp->link)
		printf("%d->", temp->data);
	printf("NULL\n");
}

int main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0; 
}