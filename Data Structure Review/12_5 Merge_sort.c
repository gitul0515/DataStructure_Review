//�պ� ���� ���α׷�
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

	merge_sort(list, 0, num-1);    //�պ� ���� ȣ��
	                               //ó���� ������ �ε����� ����
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}

void merge_sort(int* list, int left, int right)
{
	int mid;
	if (left < right)    //����Ʈ�� ��Ұ� �� �� �̻��� ��
	{
		mid = (left + right) / 2;         //����Ʈ�� �յ� ����
		merge_sort(list, left, mid);      //�κ� ����Ʈ ����
		merge_sort(list, mid + 1, right); 
		merge(list, left, mid, right);    //�պ�
	}
}

void merge(int* list, int left, int mid, int right)
{
	/*
	i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
	j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
	k�� ���ĵ� ����Ʈ�� ���� �ε���
	*/
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	int sorted[MAX_SIZE] = {0};
	
	//���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	//���� �ִ� ���ڵ��� �ϰ� ����
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];    
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	//�迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹��
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
