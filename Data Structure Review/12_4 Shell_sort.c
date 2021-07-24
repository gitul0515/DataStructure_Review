//쉘 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

void Shell_sort(int* list, int num);
void Inc_insertion_sort(int* list, int first, int last, int gap);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < MAX_SIZE; i++)
		list[i] = (rand() % 100) + 1;

	Shell_sort(list, num);

	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}

void Shell_sort(int* list, int num)
{
	int i, gap;
	for (gap = num / 2; gap > 0; gap = gap / 2)
	{
		if (gap % 2 == 0)    //gap이 짝수면 1을 더한다.
			gap++;
		for (i = 0; i < gap; i++)  //gap만큼의 부분 리스트 생성
			Inc_insertion_sort(list, i, num - 1, gap);
	}
}

void Inc_insertion_sort(int* list, int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i += gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}