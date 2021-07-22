//선택 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10
#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))
void selection_sort(int* list, int n);

int main(void)
{
	int i;
	int list[MAX_SIZE];
	int n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)            
		list[i] = rand() % 100;  //난수 생성 및 출력(0~99)

	selection_sort(list, n);     //선택 정렬 호출
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

void selection_sort(int* list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[least] > list[j]) least = j;
		}
		if (i!=least)
			SWAP(list[i], list[least], temp);
	}
}