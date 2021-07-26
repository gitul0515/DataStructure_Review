//합병 정렬 프로그램
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

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

	merge_sort(list, 0, num-1);   //합병 정렬 호출
	        					  //시작 인덱스와 마지막 인덱스 전달
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}

void merge_sort(int* list, int left, int right)
{
	int mid;
	if (left < right)    //리스트의 요소가 2개 이상일 때
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);        //부분 리스트로 분할
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);      //정렬된 부분리스트 합병
	}
}

void merge(int* list, int left, int mid, int right)
{
	/*
		i는 왼쪽 부분리스트의 인덱스를 가리킴
		j는 오른쪽 부분리스트의 인덱스를 가리킴
		k는 임시 리스트의 인덱스를 가리킴
	*/
	int i, j, k, l; 
	i = left; j = mid + 1; k = left;       
	int temp_list[MAX_SIZE] = { 0 };      //임시 리스트

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			temp_list[k++] = list[i++];
		else
			temp_list[k++] = list[j++];
	}

	if (i > mid)
		for (l = j; l <= right; l++)
			temp_list[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			temp_list[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = temp_list[l];
}