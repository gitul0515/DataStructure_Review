//�ð� ���� �Լ�: ctime(), asctime()
#include<stdio.h>
#include<time.h>

int main()
{
	time_t rawtime = time(&rawtime);
	char* str1 = ctime(&rawtime);
	printf("ctime�� ���: %s\n", str1);

	struct tm* ptime = localtime(&rawtime);
	char* str2 = asctime(ptime);
	printf("asctime�� ���: %s\n", str2);

	return 0;
}