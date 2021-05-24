#include<stdio.h>
#include<stdlib.h>

// ==== 스택 코드의 시작 ====
#define STACK_MAX_SIZE 100
typedef double element;
typedef struct
{
	element data[STACK_MAX_SIZE];
	int top;
}Stacktype;

//초기화 함수 
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//공백 상태 검출 함수 
int is_empty(Stacktype* s)
{
	return s->top == -1;
}

//포화 상태 검출 함수 
int is_full(Stacktype* s)
{
	return s->top >= STACK_MAX_SIZE - 1;
}

//삽입 함수 
void push(Stacktype* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "포화 상태 에러 \n");
		return;
	}
	s->data[++(s->top)] = item;
}

//삭제 함수 
element pop(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 상태 에러 \n");
		exit(1);
	}
	return s->data[(s->top)--];
}

//피크 함수 
element peek(Stacktype* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "공백 상태 에러 \n");
		exit(1);
	}
	return s->data[s->top];
}
// ==== 스택 코드의 끝 ====

//후위표기 계산 함수 
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
		if ('0' <= ch && ch <= '9')   //피연산자(숫자)의 경우 
			push(&s, ch - '0');       //문자를 정수화하여 스택에 삽입 
		else                          //연산자의 경우 
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
				fprintf(stderr, "식 오류 \n");
				exit(1);
			}
		}
	}
	if (s.top != 0)
	{
		fprintf(stderr, "식 오류 \n");
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