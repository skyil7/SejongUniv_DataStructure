#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sum(int x)
{
	int i, r = 0;
	for (i = 1; i <= x; i++)
		r += i;
	return r;
}

int main()
{
	int x, i, res = 0;

	scanf("%d", &x);

	for (i = 1; i <= x; i++)
	{
		res += sum(i);
	}

	printf("%d", res);

	return 0;
}