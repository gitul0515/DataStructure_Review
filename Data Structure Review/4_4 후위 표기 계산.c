#include<stdio.h>
#include<stdlib.h>

// ==== ���� �ڵ��� ���� ====
#define STACK_MAX_SIZE 100
typedef double element;
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

//����ǥ�� ��� �Լ� 
double Postfix_notation(char* str)
{
	Stacktype s;
	init_stack(&s);
	int i;
	char ch;
	double f_num, s_num;

	for (i = 0; i < strlen(str); i++)
	{
		ch = str[i];
		if ('0' <= ch && ch <= '9')   //�ǿ�����(����)�� ��� 
			push(&s, ch - '0');       //���ڸ� ����ȭ�Ͽ� ���ÿ� ���� 
		else                          //�������� ��� 
		{
			f_num = pop(&s); s_num = pop(&s);
			switch (ch)
			{
			case '+':
				push(&s, s_num + f_num);
				break;
			case '-':
				push(&s, s_num - f_num);
				break;
			case '*':
				push(&s, s_num * f_num);
				break;
			case '/':
				push(&s, s_num / f_num);
				break;
			default:
				fprintf(stderr, "�� ���� \n");
				exit(1);
			}
		}
	}
	if (s.top != 0)
	{
		fprintf(stderr, "�� ���� \n");
		exit(1);
	}
	return pop(&s);
}

int main()
{
	char* str = "82/3-32*+";

	printf("Result: %0.1f \n", Postfix_notation(str));
	return 0;
}