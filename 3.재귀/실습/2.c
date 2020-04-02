#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void sep(int n)
{
	if (n > 9)
	{
		sep(n / 10);
		printf("%d\n", n % 10);
	}
	else
		printf("%d\n", n);
}

int main()
{
	int n;

	scanf("%d", &n);

	sep(n);

	return 0;
}