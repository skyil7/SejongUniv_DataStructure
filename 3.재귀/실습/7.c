#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int exam(char* str, char q, int cnt)
{
	if (*str == 0)
		return cnt;
	if (*str == q)
		return exam(str + 1, q, cnt + 1);
	return exam(str + 1, q, cnt);
}

int main()
{
	char str[101] = { 0 };
	char q;

	gets(str);
	scanf("%c", &q);

	printf("%d", exam(str, q, 0));

	return 0;
}