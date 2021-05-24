//���� �迭 ����
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct
{
	int top;
	int capacity;
	element* data;
}StackType;

//���� �ʱ�ȭ �Լ� 
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
}
//���� ó�� �Լ� 
void stack_error(char* ch)
{
	fprintf(stderr, "%s\n", ch);
	exit(1);
}
//���� ���� ���� �Լ� 
int is_empty(StackType* s)
{
	return s->top == -1;
}
//��ȭ ���� ���� �Լ� 
int is_full(StackType* s)
{
	return s->top == s->capacity - 1;
}
//���� �Լ� 
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		(element*)realloc(s->data, sizeof(element) * s->capacity);
	}
	s->data[++(s->top)] = item;
}
//���� �Լ� 
element pop(StackType* s)
{
	if (is_empty(s))
		stack_error("���� ���� ����");
	return s->data[(s->top)--];
}
//��ũ �Լ� 
element peek(StackType* s)
{
	if (is_empty(s))
		stack_error("���� ���� ����");
	return s->data[s->top];
}

int main()
{
	StackType s;
	init_stack(&s);
	element item;

	//���ÿ� 8���� ���� ����
	while (s.top != 7)
	{
		printf("���� �Է�: ");
		scanf("%d", &item);
		push(&s, item);
	}
	//��� ����� ���
	while (!is_empty(&s))
		printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}