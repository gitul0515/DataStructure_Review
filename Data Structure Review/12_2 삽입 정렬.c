#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10
void insertion_sort(int list[], int num);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = (rand() % 100) + 1;

	insertion_sort(list, num);
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}

void insertion_sort(int list[], int num)
{
	int i, j, key;
	for (i = 1; i < num; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;
	}
}