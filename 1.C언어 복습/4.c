#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void shift(char* str)
{
	char flow = *str, * p, temp;
	for (p = str; *(p + 1); p++)
	{
		*p = *(p + 1);
	}
	*p = flow;
}

int main()
{
	char str[101] = { 0 };
	int len, i;

	gets(str);

	len = strlen(str);

	printf("%s\n", str);
	for (i = 0; i < len-1; i++)
	{
		shift(str);
		printf("%s\n", str);
	}

	return 0;
}