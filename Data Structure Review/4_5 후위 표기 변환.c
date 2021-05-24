#include<stdio.h>
#include<string.h>

// ==== 스택 코드의 시작 ====
#define STACK_MAX_SIZE 100
typedef char element;
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

//후위 표기 출력 함수 
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