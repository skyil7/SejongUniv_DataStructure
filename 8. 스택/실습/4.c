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
	if (s >= '0' && s <= '9')
		return 1;
	return 0;
}
void push(char elem, STACK** top)
{
	STACK *n = (STACK*)malloc(sizeof(STACK));
	n->value = elem;
	n->prev = *top;
	*top = n;
}
char pop(STACK** top)
{
	char re = (*top)->value;
	STACK* prev = (*top)->prev;
	free(*top);
	*top = prev;
	return re;
}
char doOper(char op, char a, char b)
{
	//printf("Performing Operation... %c %c %c\n", a, op, b);
	if (op == '+')
		return ((a - '0') + (b - '0')) + '0';
	if (op == '-')
		return ((a - '0') - (b - '0')) + '0';
	if (op == '*')
		return ((a - '0') * (b - '0')) + '0';
	if (op == '/')
		return ((a - '0') / (b - '0')) + '0';
}

void evaluate(char* str)
{
	STACK* top = 0;
	char* p = str;
	char s, a, b;

	for (p = str; *p; p++)
	{
		s = *p;
		if (isOperand(s))
			push(s, &top);
		else
		{
			a = pop(&top);
			b = pop(&top);
			push(doOper(s, b, a), &top);
		}
	}
	printf("%d\n", pop(&top)-'0');
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
		evaluate(str);
	}

	return 0;
}