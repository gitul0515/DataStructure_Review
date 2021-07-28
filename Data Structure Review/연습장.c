//qsort 함수 라이브러리의 사용
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

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
	double list[MAX_SIZE] = { 5.7, 3.2, 0.7, 9.5, 4.1 };

	qsort((void*)list, (size_t)MAX_SIZE, sizeof(double), compare);

	for (i = 0; i < 5; i++)
		printf("%0.1f ", list[i]);
	printf("\n");
	return 0; 
}
