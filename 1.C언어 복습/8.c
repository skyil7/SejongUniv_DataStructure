#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct student {
	char name[8];
	int ko, eng, math;
	double avg;
} STU;

int main()
{
	int n;
	STU* ar;
	STU* p;

	scanf("%d", &n);

	ar = (STU*)malloc(sizeof(STU) * n);
	for (p = ar; p < ar + n; p++)
	{
		scanf("%s %d %d %d", p->name, &p->ko, &p->eng, &p->math);
		p->avg = (double)(p->ko + p->eng + p->math) / 3;
		printf("%s %.1lf", p->name, p->avg);
		if (p->ko >= 90 || p->eng >= 90 || p->math >= 90)
			printf(" GREAT");
		if (p->ko < 70 || p->eng < 70 || p->math < 70)
			printf(" BAD");
		printf("\n");
	}

	free(ar);

	return 0;
}