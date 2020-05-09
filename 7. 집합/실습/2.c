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
	if (s == 0 || (s->elem == 0 && s->next == 0))
		return 1;
	return 0;
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
// print set
void print(set* s)
{
	set* p;

	if (isEmpty(s))
	{
		printf("0\n");
		return;
	}

	for (p = s->next; p->next; p = p->next)
		printf(" %d", p->elem);
	printf(" %d\n", p->elem);
}
set unionSet(set* A, set* B)
{
	set C = { 0 };
	set* p = &C;
	set* a = A->next, * b = B->next;

	if (isEmpty(A))
		return *B;
	if (isEmpty(B))
		return *A;

	while (!isEmpty(a) && !isEmpty(b))
	{
		if (a->elem < b->elem)
		{
			p = addElem(p, a->elem);
			a = a->next;
		}
		else if (a->elem > b->elem)
		{
			p = addElem(p, b->elem);
			b = b->next;
		}
		else
		{
			p = addElem(p, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	while (!isEmpty(a))
	{
		p = addElem(p, a->elem);
		a = a->next;
	}
	while (!isEmpty(b))
	{
		p = addElem(p, b->elem);
		b = b->next;
	}
	return C;
}
set intersect(set* A, set* B)
{
	set C = { 0 };
	set* p = &C;
	set* a = A->next, * b = B->next;

	if (isEmpty(A))
		return C;
	if (isEmpty(B))
		return C;

	while (!isEmpty(a) && !isEmpty(b))
	{
		if (a->elem < b->elem)
		{
			a = a->next;
		}
		else if (a->elem > b->elem)
		{
			b = b->next;
		}
		else
		{
			p = addElem(p, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	return C;
}

int main()
{
	int n, i, e;
	set A = { 0 }, B = { 0 };
	set u, inter;
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

	u = unionSet(&A, &B);
	print(&u);
	inter = intersect(&A, &B);
	print(&inter);

	return 0;
}