//�ð� ���� �Լ�: time(), Sleep()
#include<stdio.h>
#include<time.h>         //time �Լ��� �ִ� ��� ����
#include<windows.h>      //Sleep �Լ��� �ִ� ��� ����

int main()
{
	time_t start_time = time(NULL);  //���� �ð��� ����
	Sleep(2000);                     //���α׷� 2�� ����
	printf("%lld\n", time(NULL) - start_time);
	return 0;
}