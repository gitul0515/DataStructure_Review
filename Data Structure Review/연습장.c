#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = -1;
	int list[5] = { 0 };
	do
	{
		i++;
	} while (list[i] == 0);  //i가 리스트를 초과하면 거짓
	printf("%d\n", i);
	printf("출력\n");

	return 0; 
}