//시간 관련 함수: time(), Sleep()
#include<stdio.h>
#include<time.h>         //time 함수가 있는 헤더 파일
#include<windows.h>      //Sleep 함수가 있는 헤더 파일

int main()
{
	time_t start_time = time(NULL);  //현재 시간을 저장
	Sleep(2000);                     //프로그램 2초 정지
	printf("%lld\n", time(NULL) - start_time);
	return 0;
}