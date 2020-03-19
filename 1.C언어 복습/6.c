#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct student {
	char name[10];
	int score;
}STU;

int main()
{
	STU st[5], *p;
	double scoreAVG = 0.0;

	for (p = st; p < st + 5; p++)
	{
		scanf("%s %d", p->name, &p->score);
		scoreAVG += p->score;
	}
	scoreAVG /= 5;

	for (p = st; p < st + 5; p++)
	{
		if (p->score < scoreAVG)
			printf("%s\n", p->name);
	}

	return 0;
}