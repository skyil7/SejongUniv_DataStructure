#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s {
	struct s* next;
	char el;
} STACK;

void push(STACK** s, char ch)
{
	STACK* n;

	n = (STACK*)malloc(sizeof(STACK));
	n->el = ch;
	n->next = *s;
	*s = n;
}

void getStr(STACK** s, int n)
{
	int i;
	char ch;

	for (i = 0; i < n; i++)
	{
		scanf("%c", &ch);
		push(s, ch);
	}
}

char pop(STACK** t)
{
	char ch = (*t)->el;
	STACK* n = (*t)->next;
	free(*t);
	*t = n;
	return ch;
}

int compare(STACK** t, int n)
{
	int i;
	char ch;

	for (i = 0; i < n; i++)
	{
		scanf("%c", &ch);
		if (pop(t) != ch)
			return 0;
	}
	return 1;
}

int main()
{
	int n, flag;
	STACK *t;
	
	// 입력: 문자열 길이 n, 문자열
	// 입력받은 문자열이 회문인지 아닌지 검사
	// 회문 예시: abba, level

	scanf("%d", &n);
	getchar();
	if (n % 2 == 0)
	{
		getStr(&t, n/2);
		flag = compare(&t, n/2);
	}
	if (n % 2 == 1) // 이 경우 가운데 한 글자 무시
	{
		getStr(&t, n/2);
		getchar();
		flag = compare(&t, n/2);
	}
	if (flag)
	{
		printf("회문입니다!");
	}
	else
	{
		printf("회문이 아닙니다!");
	}

	return 0;
}