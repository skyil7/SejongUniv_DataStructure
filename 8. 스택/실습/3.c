#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct stack {
	char value;
	struct stack* prev;
} STACK;

int isOperand(char s)
{
	if ('A' <= s && s <= 'Z')
		return 1;
	return 0;
}
STACK* push(char elem, STACK* top)
{
	STACK* n = (STACK*)malloc(sizeof(STACK));
	n->value = elem;
	n->prev = top;
	return n;
}
char pop(STACK** top)
{
	char v = (*top)->value;
	STACK* prev = (*top)->prev;
	free(*top);
	*top = prev;
	return v;
}
void encode(char* str)
{
	char* p, * q;
	if (*str == '+')
		* str = 'p';
	if (*str == '-')
		* str = 'n';
	for (p = str + 1; *p; p++)
	{
		if (*p == '|' || *p == '&')
		{
			for (q = p + 1; *q; q++)
			{
				*(q - 1) = *q;
			}
			*(q - 1) = 0;
		}
	}
	for (p = str + 1; *p; p++)
	{
		if ((*(p - 1) < 'A' || *(p - 1) > 'Z') && *(p - 1) != ')')
		{
			if (*p == '+')
				* p = 'p';
			if (*p == '-')
				* p = 'n';
		}
	}
}
int pr(char ch)
{
	if (ch == '!' || ch == 'p' || ch == 'n')
		return 6;
	if (ch == '*' || ch == '/')
		return 5;
	if (ch == '+' || ch == '-')
		return 4;
	if (ch == '>' || ch == '<')
		return 3;
	if (ch == '&')
		return 2;
	if (ch == '|')
		return 1;
	return 0;
}
void convert(char* str)
{
	STACK *top = 0;
	char* p = str;
	char s = 1, t;

	while (s = *p++)
	{
		if (isOperand(s))
		{
			printf("%c", s);
		}
		else if (s == '(')
		{
			top = push(s, top);
		}
		else if (s == ')')
		{
			while (top->value != '(')
			{
				t = pop(&top);
				if (t == '|' || t == '&')
					printf("%c%c", t, t);
				else if (t == 'p')
					printf("+");
				else if (t == 'n')
					printf("-");
				else
					printf("%c", t);
			}
			pop(&top);
		}
		else
		{
			while (top != 0 && pr(s) <= pr(top->value))
			{
				t = pop(&top);
				if (t == '|' || t == '&')
					printf("%c%c", t, t);
				else if (t == 'p')
					printf("+");
				else if (t == 'n')
					printf("-");
				else
					printf("%c", t);
			}
			top = push(s, top);
		}
	}
	while (top != 0)
	{
		t = pop(&top);
		if (t == '|' || t == '&')
			printf("%c%c", t, t);
		else if (t == 'p')
			printf("+");
		else if (t == 'n')
			printf("-");
		else
			printf("%c", t);
	}
	printf("\n");
}

int main()
{
	int n;
	int i;
	char str[101];

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(str);
		encode(str);
		//printf("%s\n", str);
		convert(str);
	}

	return 0;
}