#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

int* prefixAverages1(int* X, int n)
{
	int* A;
	int i, j;
	float sum;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		A[i] = sum / (i + 1) + 0.5;
	}
	return A;
}

int* prefixAverages2(int* X, int n)
{
	int* A;
	int i, j;
	float sum = 0;
	A = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		sum += X[i];
		A[i] = sum / (i + 1) + 0.5;
	}
	return A;
}

int main()
{
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	int n;
	int* x, * p;
	int* a;

	scanf("%d", &n);
	srand(time(NULL));
	x = (int*)malloc(sizeof(int) * n);

	for (p = x; p < x + n; p++)
		*p = rand() % 10000;


	QueryPerformanceFrequency(&ticksPerSec);//Save timer frequency
	QueryPerformanceCounter(&start);
	a = prefixAverages1(x, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	free(a);

	QueryPerformanceFrequency(&ticksPerSec);//Save timer frequency
	QueryPerformanceCounter(&start);
	a = prefixAverages2(x, n);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("time: %.12f sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	free(a);

	free(x);

	return 0;
}