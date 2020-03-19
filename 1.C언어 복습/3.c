#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int ar[50], n, m;
	int* p, * a, * b;

	scanf("%d", &n);

	for (p = ar; p < ar + n; p++)
		scanf("%d", p);

	scanf("%d", &m);
	a = ar + m;
	scanf("%d", &m);
	b = ar + m;
	swap(a, b);

	for (p = ar; p < ar + n; p++)
		printf(" %d", *p);

	return 0;
}