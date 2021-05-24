#include<stdio.h>
#include<stdlib.h>
#define STACK_MAX_SIZE 100
// ==== ���� �ڵ��� ���� ====
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
element is_empty(Stacktype* s)
{
	return s->top == -1;
}

//��ȭ ���� ���� �Լ� 
element is_full(Stacktype* s)
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

int check_matching(char* p)
{
	Stacktype s;
	char ch, open_ch;
	int i, n = strlen(p);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = p[i];
		switch (ch)
		{
		case '(': case '{': case '[':
			push(&s, ch);
			break;
		case ')': case '}': case ']':
			if (is_empty(&s))
				return 0;
			else
			{
				open_ch = pop(&s);
				if (open_ch == '(' && ch != ')' ||
					open_ch == '{' && ch != '}' ||
					open_ch == '[' && ch != ']'){
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main()
{
	char* p = "{([1+1] + 3)}";

	if (check_matching(p) == 1)
		printf("%s: ��ȣ�˻� ���� \n", p);
	else 
		printf("%s: ��ȣ�˻� ���� \n", p);
	return 0; 
}