#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = -1;
	int list[5] = { 0 };
	do
	{
		i++;
	} while (list[i] == 0);  //i�� ����Ʈ�� �ʰ��ϸ� ����
	printf("%d\n", i);
	printf("���\n");

	return 0; 
}