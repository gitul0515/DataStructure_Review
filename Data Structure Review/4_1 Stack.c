#include<stdio.h>
#include<stdlib.h>

//차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ==== 스택 코드의 시작 ====
#define STACK_MAX_SIZE 100
typedef int element;
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
