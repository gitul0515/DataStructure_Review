#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10
#define SWAP(X,Y,T) ((T)=(X),(X)=(Y),(Y)=(T))

void selection_sort(int list[], int num);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];

	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = (rand() % 100) + 1;  //난수 생성 및 출력(1~100)

	selection_sort(list, num);
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");

	return 0; 
}

void selection_sort(int list[], int num)
{
	int i, j, temp, least;
	for (i = 0; i < num-1; i++)
	{
		least = i;
		for (j = i + 1; j < num; j++)
			if (list[least] > list[j]) least = j;
		SWAP(list[i], list[least], temp);
	}
}