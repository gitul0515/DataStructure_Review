#include<stdio.h>
#include<string.h>

// ==== ���� �ڵ��� ���� ====
#define STACK_MAX_SIZE 100
typedef char element;
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

//���� ǥ�� ��� �Լ� 
void Postfix_print(char* str)
{
	Stacktype s;
	int i; 
	char ch; 

	init_stack(&s);
	for (i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '+': case '-':
			while (!is_empty(&s) && peek(&s) != '(')
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '*': case '/':
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			while (peek(&s) != '(')
				printf("%c", pop(&s));
			pop(&s);
			break; 
		default:
			printf("%c", str[i]);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main()
{
	char* str = "(a+b)*c";
	Postfix_print(str);
	return 0; 
}