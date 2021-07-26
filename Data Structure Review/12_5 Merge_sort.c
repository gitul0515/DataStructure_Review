//합병 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 8

void merge_sort(int* list, int left, int right);
void merge(int* list, int left, int mid, int right);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = (rand() % 100) + 1;

	merge_sort(list, 0, num-1);    //합병 정렬 호출
	                               //처음과 마지막 인덱스를 전달
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

void merge_sort(int* list, int left, int right)
{
	int mid;
	if (left < right)    //리스트의 요소가 두 개 이상일 때
	{
		mid = (left + right) / 2;         //리스트의 균등 분할
		merge_sort(list, left, mid);      //부분 리스트 정렬
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right);    //합병
	}
}

void merge(int* list, int left, int mid, int right)
{
	/*
	i는 정렬된 왼쪽 리스트에 대한 인덱스
	j는 정렬된 오른쪽 리스트에 대한 인덱스
	k는 정렬될 리스트에 대한 인덱스
	*/
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	int sorted[MAX_SIZE] = {0};
	
	//분할 정렬된 list의 합병
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	//남아 있는 레코드의 일괄 복사
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];    
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//배열 sorted[]의 리스트를 배열 list[]로 재복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
