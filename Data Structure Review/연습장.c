#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

int main()
{
	time_t rawtime = time(NULL);
	struct tm* Ptime = localtime(&rawtime);

	printf("rawtime: %lld\n", rawtime);

	int year = Ptime->tm_year + 1900;
	int month = Ptime->tm_mon + 1;
	int day = Ptime->tm_mday;
	int hour = Ptime->tm_hour;
	int min = Ptime->tm_min;
	int sec = Ptime->tm_sec;
	printf("%d년 %d월 %d일 %d시 %d분 %d초\n",
			year, month, day, hour, min, sec);

	return 0; 
}