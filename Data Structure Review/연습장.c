//삽입 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 6

void shell_sort(int* list, int num);
void Inc_shell_sort(int* list, int first, int last, int gap);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
	{
		list[i] = (rand() % 100) + 1;
		printf("%d ", list[i]);
	}
	printf("---- 정렬 전\n");
	shell_sort(list, num);
	return 0;
}

void shell_sort(int* list, int num)
{
	int i, gap;
	for (gap = num / 2; gap > 0; gap /= 2)
	{
		if ((gap % 2) == 0)
			gap++;
		for (i = 0; i < gap; i++)
			Inc_shell_sort(list, i, num - 1, gap);
	}
}

void Inc_shell_sort(int* list, int first, int last, int gap)
{
	int i, j, key;
	for (i = first+gap; i <= last; i+=gap)
	{
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
	for (i = 0; i < last + 1; i++)
		printf("%d ", list[i]);
	printf("---- gap: %d\n", gap);
}