#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void swap(int* ar, int a, int b)
{
	int* p, * q;
	int tmp;

	p = ar + a;
	q = ar + b;

	while (p < q)
	{
		tmp = *p;
		*p++ = *q;
		*q-- = tmp;
	}
}

int main()
{
	int n, m, i;
	int a, b;
	int* p;
	int ar[100];

	scanf("%d", &n);

	for (p = ar; p < ar + n; p++)
		scanf("%d", p);

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		swap(ar, a, b);
	}

	for (p = ar; p < ar + n; p++)
		printf(" %d", *p);

	return 0;
}