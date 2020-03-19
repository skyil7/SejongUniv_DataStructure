#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct time {
	int h, m, s;
	int tick;
}TIME;

int main()
{
	TIME a, b;
	TIME c;

	scanf("%d %d %d", &a.h, &a.m, &a.s);
	scanf("%d %d %d", &b.h, &b.m, &b.s);

	a.tick = a.h * 3600 + a.m * 60 + a.s;
	b.tick = b.h * 3600 + b.m * 60 + b.s;

	c.tick = b.tick - a.tick;

	c.h = c.tick / 3600;
	c.tick %= 3600;
	c.m = c.tick / 60;
	c.tick %= 60;
	c.s = c.tick;

	printf("%d %d %d", c.h, c.m, c.s);

	return 0;
}