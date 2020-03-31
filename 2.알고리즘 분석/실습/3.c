#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	int n;
	int* x, * p;
	int* a;

	scanf("%d", &n);
	x = (int*)malloc(sizeof(int) * n);

	for (p = x; p < x + n; p++)
		scanf("%d", p);

	a = prefixAverages1(x, n);
	for (p = a; p < a + n; p++)
		printf(" %d", *p);
	printf("\n");
	free(a);

	a = prefixAverages2(x, n);
	for (p = a; p < a + n; p++)
		printf(" %d", *p);
	free(a);
	free(x);

	return 0;
}