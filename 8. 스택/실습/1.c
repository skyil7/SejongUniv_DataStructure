#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

char pop(char* s, int *tt)
{
	char p;
	int t = *tt;
	if (t < 0)
	{
		printf("Stack Empty\n");
		return;
	}
	p = *(s + t);
	*(s + t) = 0;
	(*tt)--;
	return p;
}
char push(char* s, int* tt, int n, char el)
{
	(*tt)++;
	if (*tt < n)
		* (s + *tt) = el;
	else
	{
		printf("Stack FULL\n");
		(*tt)--;
	}
}
void print(char* s, int t)
{
	int i;	
	for (i = t; i >= 0; i--)
	{
		printf("%c", *(s + i));
	}
	printf("\n");
}

int main()
{
	char* s;
	char* tmp;
	int n, com, t, i, j;
	int cn;
	char order[6] = { 0 };
	char el;

	scanf("%d", &n);  //스택크기
	scanf("%d", &com);//명령 개수
	
	s = (char*)malloc(sizeof(char) * (n));
	t = -1;
	for (i = 0; i < com; i++)
	{
		scanf("%s", order);
		if (!strcmp(order, "POP"))
		{
			pop(s, &t);
		}
		else if (!strcmp(order, "PUSH"))
		{
			getchar();
			scanf("%c", &el);
			push(s, &t, n, el);
		}
		else if (!strcmp(order, "PEEK"))
		{
			if (t < 0)
				printf("Stack Empty\n");
			else
				printf("%c\n", *(s + t));
		}
		else if (!strcmp(order, "DUP"))
		{
			el = pop(s, &t);
			push(s, &t, n, el);
			push(s, &t, n, el);
		}
		else if (!strcmp(order, "UpR"))
		{
			scanf("%d", &cn);
			if (cn > t+1)
				continue;
			el = pop(s, &t);
			tmp = (char*)malloc(sizeof(char) * (cn - 1));
			for (j = 0; j < cn - 1; j++)
			{
				*(tmp + j) = pop(s, &t);
			}
			push(s, &t, n, el);
			for (j = j - 1; j >= 0; j--)
				push(s, &t, n, *(tmp + j));
		}
		else if (!strcmp(order, "DownR"))
		{
			scanf("%d", &cn);
			if (cn > t + 1)
				continue;
			tmp = (char*)malloc(sizeof(char) * (cn - 1));
			for (j = 0; j < cn - 1; j++)
			{
				*(tmp + j) = pop(s, &t);
			}
			el = pop(s, &t);
			for (j = j - 1; j >= 0; j--)
				push(s, &t, n, *(tmp + j));
			push(s, &t, n, el);
		}
		else if (!strcmp(order, "PRINT"))
		{
			print(s, t);
		}
	}

	return 0;
}