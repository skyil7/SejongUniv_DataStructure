#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct polynomial {
	int coef, exp;
	struct polynomial* next;
} POLY;

void appendTerm(POLY* k, int coef, int exp)
{
	POLY* p;
	POLY* n;
	for (p = k; p->next != 0; p = p->next);//move p to last element
	n = (POLY*)malloc(sizeof(POLY));
	p->next = n;
	n->coef = coef;
	n->exp = exp;
	n->next = 0;
}

POLY addPoly(POLY x, POLY y)
{
	POLY result = { 0 };
	POLY* p, * q;
	int sum;

	p = x.next;
	q = y.next;

	while (p && q)
	{
		if (p->exp > q->exp)
		{
			appendTerm(&result, p->coef, p->exp);
			p = p->next;
		}
		else if (p->exp < q->exp)
		{
			appendTerm(&result, q->coef, q->exp);
			q = q->next;
		}
		else
		{
			sum = p->coef + q->coef;
			if (sum)
				appendTerm(&result, sum, p->exp);
			p = p->next;
			q = q->next;
		}
	}
	while (p)
	{
		appendTerm(&result, p->coef, p->exp);
		p = p->next;
	}
	while (q)
	{
		appendTerm(&result, q->coef, q->exp);
		q = q->next;
	}
	return result;
}

void print(POLY x)
{
	POLY *p;
	p = x.next;
	while (p)
	{
		printf(" %d", p->coef);
		printf(" %d", p->exp);
		p = p->next;
	}
}

int main()
{
	int n;
	int i, coef, exp;
	POLY x = { 0 }, y = { 0 };
	POLY z;

	scanf("%d", &n);// input x
	for (i = 0; i < n; i++)
	{
		scanf("%d", &coef);
		scanf("%d", &exp);
		appendTerm(&x, coef, exp);
	}
	scanf("%d", &n);// input y
	for (i = 0; i < n; i++)
	{
		scanf("%d", &coef);
		scanf("%d", &exp);
		appendTerm(&y, coef, exp);
	}

	z = addPoly(x, y);

	print(z);

	return 0;
}