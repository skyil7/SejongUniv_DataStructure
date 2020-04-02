#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sum(int n)
{
	if (n == 1)
		return 1;
	return n + sum(n - 1);
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d", sum(n));

	return 0;
}