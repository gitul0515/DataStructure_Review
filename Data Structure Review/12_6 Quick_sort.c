//�� ���� ���α׷�
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 9
#define SWAP(X,Y,T) ((T)=(X),(X)=(Y),(Y)=(T))

void quick_sort(int* list, int left, int right);
int partition(int* list, int left, int right);

int main()
{
	int i;
	int num = MAX_SIZE;
	int list[MAX_SIZE];
	srand(time(NULL));
	for (i = 0; i < num; i++)
		list[i] = (rand() % 100) + 1;
	
	quick_sort(list, 0, num - 1); //�� ���� ȣ��
								  //ù �ε����� ������ �ε��� ����
	for (i = 0; i < num; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0; 
}

void quick_sort(int* list, int left, int right)
{
	int q;
	if (left < right)   //����Ʈ�� ��Ұ� 2�� �̻��� ��
	{
		q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int partition(int* list, int left, int right)
{
	int low, high, pivot, temp;
	low = left;            //do-while���� ����Ͽ� ���� �Ҵ�
	high = right + 1;      //low�� left+1����, high�� right���� ����
	pivot = left;          //pivot���� ù��° ��Ҹ� �Ҵ�
	do
	{
		do
			low++;
		while (list[low] < list[pivot]);  //�ڸ���Ʈ�� ������ �ʰ��ϸ� �������� ����
		do                                  //���� ���� ��쿡�� �������� ����(������)
			high--;
		while (list[high] > list[pivot]);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	
	SWAP(list[pivot], list[high], temp);
	return high;	  //pivot���� ����� �ε����� ��ȯ
}