//�պ� ���� ���α׷�
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

	merge_sort(list, 0, num-1);   //�պ� ���� ȣ��
	        					  //���� �ε����� ������ �ε��� ����
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}

void merge_sort(int* list, int left, int right)
{
	int mid;
	if (left < right)    //����Ʈ�� ��Ұ� 2�� �̻��� ��
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);        //�κ� ����Ʈ�� ����
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);      //���ĵ� �κи���Ʈ �պ�
	}
}

void merge(int* list, int left, int mid, int right)
{
	/*
		i�� ���� �κи���Ʈ�� �ε����� ����Ŵ
		j�� ������ �κи���Ʈ�� �ε����� ����Ŵ
		k�� �ӽ� ����Ʈ�� �ε����� ����Ŵ
	*/
	int i, j, k, l; 
	i = left; j = mid + 1; k = left;       
	int temp_list[MAX_SIZE] = { 0 };      //�ӽ� ����Ʈ

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