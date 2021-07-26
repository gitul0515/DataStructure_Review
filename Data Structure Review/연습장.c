//퀵 정렬 라이브러리 함수
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(void* arg1, void* arg2)
{
	if (*(double*)arg1 > *(double*)arg2)
		return 1;
	else if (*(double*)arg1 == *(double*)arg2)
		return 0;
	else
		return -1;
}

int main()
{
	int i;
	double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };
	qsort((void*)list, (size_t)5, sizeof(double), compare);
	
	for (i = 0; i < 5; i++)
		printf("%0.1f ", list[i]);
	printf("\n");
	return 0; 
}