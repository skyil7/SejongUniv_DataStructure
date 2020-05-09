#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int dif(int* ar, int n)
{
	int max = 0;
	int *p,*q;
	for (p = ar; p < ar + n; p++)//전체 순회
	{
		for (q = p; q < ar + n; q++)//p 이후 전체 순회
		{
			if (*q - *p > max)//EXP, 오름차 순이므로 이것만 점검해도 됨
				max = *q - *p;//IND IND ASS
		}
	}
	return max; // RET
}

/*
	dif 의 실행속도 = O(n^2) (상수시간)
*/

int negcnt(int* ar, int n)
{
	int* p;
	int cnt = 0;
	for (p = ar; p < ar + n; p++)//배열 순회
	{
		if (*p < 0)//음수 탐색
			cnt++;//count
	}
	return cnt; //RET
}
/*
negcnt의 실행속도는 O(n)
For 반복문 안에서 IND와 EXP, ASS를 n회 시행
*/

int main()
{
	int n;
	int* arr;
	int* p;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);//n 크기 배열 할당

	for (p = arr; p < arr + n; p++)
		scanf("%d", p);//arr 입력

	printf("%d\n", dif(arr, n));// 원소의 차 중 최댓값 함수 호출(CAL)
	printf("%d", negcnt(arr, n));// 음수 갯수 함수 호출(CAL)


	return 0;
}