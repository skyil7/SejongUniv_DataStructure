#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int* a, * b;
	int* p, * q;
	int n;

	scanf("%d", &n);

	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);

	for (p = a; p < a + n; p++)
		scanf("%d", p);
	for (p = b; p < b + n; p++)
		scanf("%d", p);

	for (p = a, q = b + n - 1; p < a + n; p++, q--)
		printf(" %d", *p + *q);

	free(a);
	free(b);

	return 0;
}