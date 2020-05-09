#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct SET {
	int elem;
	struct SET* next;
} set;

// return 1 if Set is Empty
int isEmpty(set* s)
{
	if (s->next)
		return 0;
	return 1;
}
// add Elem and return Pointer of last elem
set* addElem(set* s, int e)
{
	set* n;

	n = (set*)malloc(sizeof(set));
	n->elem = e;
	n->next = 0;
	s->next = n;

	return n;
}
// return 1 if e is member of A
int member(set* A, int e)
{
	set* p=A->next;
	if (isEmpty(A))
		return 0;
	while (1)
	{
		if (p->elem < e)
		{
			if (p->next == 0)
				return 0;
			p = p->next;
		}
		else if (p->elem > e)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
// subset
int subset(set* A, set* B)
{
	set* a = A->next;
	if (isEmpty(A))
		return 0;
	while (1)
	{
		if (member(B, a->elem))
		{
			if (a->next == 0)
				return 0;
			a = a->next;
		}
		else
			return a->elem;
	}
}

int main()
{
	int n, i, e;
	set A = { 0 }, B = { 0 };
	set* p = &A, * q = &B;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e);
		p = addElem(p, e);
	}

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &e);
		q = addElem(q, e);
	}

	printf("%d", subset(&A, &B));

	return 0;
}