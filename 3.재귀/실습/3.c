#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void sep(int n)
{
	if (n < 10)
		printf("%d\n", n);
	else
	{
		printf("%d\n", n % 10);
		sep(n / 10);
	}
}

int main()
{
	int n;

	scanf("%d", &n);

	sep(n);

	return 0;
}