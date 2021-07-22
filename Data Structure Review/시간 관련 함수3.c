//시간 관련 함수: ctime(), asctime()
#include<stdio.h>
#include<time.h>

int main()
{
	time_t rawtime = time(&rawtime);
	char* str1 = ctime(&rawtime);
	printf("ctime의 결과: %s\n", str1);

	struct tm* ptime = localtime(&rawtime);
	char* str2 = asctime(ptime);
	printf("asctime의 결과: %s\n", str2);

	return 0;
}