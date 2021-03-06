//버블 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10
#define SWAP(X,Y,T) ((T=X),(X=Y),(Y=T))

void bubble_sort(int* list, int num);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < MAX_SIZE; i++)
		list[i] = (rand() % 100) + 1;

	bubble_sort(list, num);
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

void bubble_sort(int* list, int num)
{
	int i, j, temp;
	for (i = num-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
	}
}