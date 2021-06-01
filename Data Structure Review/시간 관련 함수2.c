//시간 관련 함수: localtime()
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

	int year = pTimeInfo->tm_year + 1900;  //연도에는 1900을 더해줌
	int month = pTimeInfo->tm_mon + 1;     //월에는 1을 더해줌
	int mday = pTimeInfo->tm_mday;
	int hour = pTimeInfo->tm_hour;
	int min = pTimeInfo->tm_min;
	int sec = pTimeInfo->tm_sec;
	printf("TimeInfo: %d년 %d월 %d일 %d시간 %d분 %d초\n", 
		    year, month, mday, hour, min, sec);

	return 0;
}