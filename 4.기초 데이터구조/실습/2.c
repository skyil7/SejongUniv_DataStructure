#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main()
{
	int n, m, i;
	int* p;
	int a, b;
	int prev, cur;
	int ar[100];

	scanf("%d", &n);
	for (p = ar; p < ar + n; p++)
		scanf("%d", p);

	scanf("%d", &m);
	scanf("%d", &a);
	prev = *(ar + a);

	for (i = 1; i < m; i++)
	{
		scanf("%d", &b);
		cur = *(ar + b);
		*(ar + b) = prev;
		prev = cur;
	}

	for (p = ar; p < ar + n; p++)
		printf(" %d", *p);

	return 0;
}