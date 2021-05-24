//동적 배열 스택
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct
{
	int top;
	int capacity;
	element* data;
}StackType;

//스택 초기화 함수 
void init_stack(StackType* s)
{
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(sizeof(element) * s->capacity);
}
//오류 처리 함수 
void stack_error(char* ch)
{
	fprintf(stderr, "%s\n", ch);
	exit(1);
}
//공백 상태 검출 함수 
int is_empty(StackType* s)
{
	return s->top == -1;
}
//포화 상태 검출 함수 
int is_full(StackType* s)
{
	return s->top == s->capacity - 1;
}
//삽입 함수 
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		s->capacity *= 2;
		(element*)realloc(s->data, sizeof(element) * s->capacity);
	}
	s->data[++(s->top)] = item;
}
//삭제 함수 
element pop(StackType* s)
{
	if (is_empty(s))
		stack_error("공백 상태 에러");
	return s->data[(s->top)--];
}
//피크 함수 
element peek(StackType* s)
{
	if (is_empty(s))
		stack_error("공백 상태 에러");
	return s->data[s->top];
}

int main()
{
	StackType s;
	init_stack(&s);
	element item;

	//스택에 8개의 정수 삽입
	while (s.top != 7)
	{
		printf("정수 입력: ");
		scanf("%d", &item);
		push(&s, item);
	}
	//모두 꺼내어서 출력
	while (!is_empty(&s))
		printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}