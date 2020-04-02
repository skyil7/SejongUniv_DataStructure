#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);
	printf("%d", gcd(a,b));

	return 0;
}