#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct deque {
	int e;
	struct deque* prev, * next;
}DQ;
void add_front(DQ** f, DQ** r, int e)
{
	DQ* n;
	n = (DQ*)malloc(sizeof(DQ));
	n->e = e;
	n->next = *f;
	n->prev = 0;
	if (*f == 0) // 첫 원소인 경우
	{
		*f = n;
		*r = n;
	}
	else
	{
		(*f)->prev = n;
		*f = n;
	}
}
void add_rear(DQ** f, DQ** r, int e)
{
	DQ* n;
	n = (DQ*)malloc(sizeof(DQ));
	n->e = e;
	n->next = 0;
	n->prev = *r;
	if (*r == 0) // 첫 원소인 경우
	{
		*f = n;
		*r = n;
	}
	else
	{
		(*r)->next = n;
		*r = n;
	}
}
void print(DQ* f)
{
	DQ* p;
	for (p = f; p; p = p->next)
	{
		printf(" %d", p->e);
	}
	printf("\n");
}
int delete_front(DQ** f, DQ** r)
{
	DQ* n;
	if (*f == 0)
	{
		printf("underflow\n");
		return 0;
	}
	n = (*f)->next;
	if (n != 0)
	{
		n->prev = 0;
	}
	else
	{
		*r = n;
	}
	free(*f);
	*f = n;
}
int delete_rear(DQ** f, DQ** r)
{
	DQ* n;
	if (*r == 0)
	{
		printf("underflow\n");
		return 0;
	}
	n = (*r)->prev;
	if (n != 0)
	{
		n->next = 0;
	}
	else
	{
		*f = n;
	}
	free(*r);
	*r = n;
}

int main()
{
	DQ* f = 0, *r = 0;
	int n, i, e;
	char com;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &com);
		if (com == 'A')
		{
			scanf("%c", &com);
			if (com == 'F')
			{
				scanf("%d", &e);
				add_front(&f, &r, e);
			}
			else if (com == 'R')
			{
				scanf("%d", &e);
				add_rear(&f, &r, e);
			}
		}
		else if (com == 'D')
		{
			scanf("%c", &com);
			if (com == 'F')
			{
				if (!delete_front(&f, &r))
				{
					break;
				}
			}
			else if (com == 'R')
			{
				if (!delete_rear(&f, &r))
				{
					break;
				}
			}
		}
		else if (com == 'P')
		{
			print(f);
		}
	}

	return 0;
}