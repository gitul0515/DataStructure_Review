//�ð� ���� �Լ�: localtime()
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

int main()
{
	time_t rawTime;
	struct tm* pTimeInfo;

	rawTime = time(NULL);
	pTimeInfo = localtime(&rawTime);

	printf("time_t : %lld\n", rawTime);

	int year = pTimeInfo->tm_year + 1900;  //�������� 1900�� ������
	int month = pTimeInfo->tm_mon + 1;     //������ 1�� ������
	int mday = pTimeInfo->tm_mday;
	int hour = pTimeInfo->tm_hour;
	int min = pTimeInfo->tm_min;
	int sec = pTimeInfo->tm_sec;
	printf("TimeInfo: %d�� %d�� %d�� %d�ð� %d�� %d��\n", 
		    year, month, mday, hour, min, sec);

	return 0;
}