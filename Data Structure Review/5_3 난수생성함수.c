//난수 생성 함수
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
		printf("%d번째 주사위 값(난수): %d\n", i + 1, (rand() % 6) + 1);
	return 0; 
}