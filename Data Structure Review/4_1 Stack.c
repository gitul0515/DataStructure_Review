#include<stdio.h>
#include<stdlib.h>

//���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ==== ���� �ڵ��� ���� ====
#define STACK_MAX_SIZE 100
typedef int element;
typedef struct
{
	element data[STACK_MAX_SIZE];
	int top;
}Stacktype;

//�ʱ�ȭ �Լ� 
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//���� ���� ���� �Լ� 
int is_empty(Stacktype* s)
{
	return s->top == -1;
}

//��ȭ ���� ���� �Լ� 
int is_full(Stacktype* s)
{
	return s->top >= STACK_MAX_SIZE - 1;
}

//���� �Լ� 
void push(Stacktype* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "��ȭ ���� ���� \n");
		return;
	}
	s->data[++(s->top)] = item;
}

//���� �Լ� 
element pop(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	return s->data[(s->top)--];
}

//��ũ �Լ� 
element peek(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	return s->data[s->top];
}
// ==== ���� �ڵ��� �� ====

int main()
{
	Stacktype s;
	init_stack(&s);

	push(&s, 1); push(&s, 2); push(&s, 3);

	printf("%d \n", pop(&s));
	printf("%d \n", peek(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));

	return 0; 
}
