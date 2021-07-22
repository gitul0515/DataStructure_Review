//연결 리스트로 구현한 스택
#include<stdio.h>
#include<malloc.h>

typedef int element;
typedef struct StackNode
{
	element data;             //데이터 영역
	struct StackNode* link;   //링크 영역
}StackNode;

typedef struct
{
	StackNode* top;
}LinkedStackType;

//오류 처리 함수 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수 
void init(LinkedStackType* s)
{
	s->top = NULL;
}
//공백 상태 검출 함수 
int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}
//포화 상태 검출 함수 
int is_full(LinkedStackType* s)
{
	return 0;
}
//삽입 함수 
void push(LinkedStackType* s, element item)
{
	if (is_full(s))
		error("포화 상태 에러");

	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	new->data = item;
	new->link = s->top;
	s->top = new;
}
//삭제 함수 
element pop(LinkedStackType* s)
{
	if (is_empty(s))
		error("공백 상태 에러\n");

	StackNode* temp = s->top;
	element data = s->top->data;
	s->top = s->top->link;
	free(temp);
	return data;
}

//피크 함수 
element peek(LinkedStackType* s)
{
	if (is_empty(s))
		error("공백 상태 에러\n");
	return s->top->data;
}

//출력 함수 
void print_stack(LinkedStackType* s)
{
	for (StackNode* temp = s->top; temp != NULL; temp = temp->link)
		printf("%d->", temp->data);
	printf("NULL\n");
}

int main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0; 
}