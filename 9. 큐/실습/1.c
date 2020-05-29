#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int enqueue(int* q, int* r, int* f, int n, int e)
{
	*r += 1;
	*r %= n;
	if (*r == *f)
		return 0; // Error
	*(q + *r) = e;
	return 1;
}
int dequeue(int* q, int* r, int* f, int n)
{
	if (*r == *f)
		return 0;
	*f += 1;
	*f %= n;
	*(q + *f) = 0;
	return 1;
}
void print(int* q, int n)
{
	int* p;
	for (p = q; p < q + n; p++)
		printf(" %d", *p);
	printf("\n");
}

int main()
{
	int r = 0, f = 0;
	int n, m;
	int iter, e = 0;
	char com;
	int* q;

	scanf("%d", &n);
	q = (int*)calloc(sizeof(int), n);

	scanf("%d", &m);
	for (iter = 0; iter < m; iter++)
	{
		getchar();
		scanf("%c", &com);
		//printf("Com: %c\n", com);
		if (com == 'I')
		{
			getchar();
			scanf("%d", &e);
			if (!enqueue(q, &r, &f, n, e))
			{
				printf("overflow");
				print(q, n);
				break;
			}
		}
		else if (com == 'D')
		{
			if (!dequeue(q, &r, &f, n))
			{
				printf("underflow");
				break;
			}
		}
		else if (com == 'P')
		{
			print(q, n);
		}
	}

	return 0;
}