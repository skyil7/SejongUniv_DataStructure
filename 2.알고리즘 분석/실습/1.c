#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int modulo(int a, int b)
{
	if (a < b)
		return a;
	return modulo(a - b, b);
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

	return 0;
}