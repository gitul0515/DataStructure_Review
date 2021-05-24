//배열리스트 프로그램
#include<stdio.h>
#include<stdlib.h>
#define MAX_LIST_SIZE 100  //리스트의 최대크기 

typedef int element;
typedef struct
{
	element array[MAX_LIST_SIZE];   //배열 정의
	int size;                       //저장된 항목들의 개수
}ArrayListType;

//오류 처리 함수 
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//리스트 초기화 함수
void init_List(ArrayListType* l)
{
	l->size = 0;
}
//공백 상태 검사 함수 
int is_empty(ArrayListType* l)
{
	return l->size == 0;
}
//포화 상태 검사 함수 
int is_full(ArrayListType* l)
{
	return l->size >= MAX_LIST_SIZE;
}
//전달된 인덱스의 값을 반환하는 함수   O(1)
element get_entry(ArrayListType* l, int pos)
{
	if (is_empty(l))
		error("공백 상태 오류");
	if (pos < 0 || pos >= l->size)
		error("위치 오류");
	return l->array[pos];
}
//후위 삽입 함수  O(1)
void insert_last(ArrayListType* l, element item)
{
	if (is_full(l))
		error("포화 상태 에러");
	l->array[(l->size)++] = item;
}
//삽입 함수     O(n)
void insert(ArrayListType* l, int pos, element item)
{
	if (!is_full(l) && pos >= 0 && pos <= l->size)
	{
		int i;
		for (i = l->size - 1; i >= pos; i--)
			l->array[i + 1] = l->array[i];
		l->array[pos] = item;
		l->size++;
	}
}
//삭제 함수          O(n)
element delete(ArrayListType* l, int pos)
{
	if (is_empty(l))
		error("공백 상태 오류");
	if (pos < 0 || pos >= l->size)
		error("위치 오류");
	element item = l->array[pos];
	for (int i = pos; i < l->size - 1; i++)
		l->array[i] = l->array[i + 1];
	l->size--;
	return item;
}
//리스트 출력 함수  O(n)
void print_list(ArrayListType* l)
{
	int i;
	for (i = 0; i < l->size; i++)
		printf("%d->", l->array[i]);
	printf("\n");
}

int main()
{
	ArrayListType list;

	init_List(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);

	printf("%d\n", get_entry(&list, 0));
	printf("%d\n", get_entry(&list, 1));
	printf("%d\n", get_entry(&list, 2));
	return 0; 
}