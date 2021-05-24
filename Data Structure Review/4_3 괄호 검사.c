#include<stdio.h>
#include<stdlib.h>
#define STACK_MAX_SIZE 100
// ==== 스택 코드의 시작 ====
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
element is_empty(Stacktype* s)
{
	return s->top == -1;
}

//포화 상태 검출 함수 
element is_full(Stacktype* s)
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
		printf("%s: 괄호검사 성공 \n", p);
	else 
		printf("%s: 괄호검사 실패 \n", p);
	return 0; 
}