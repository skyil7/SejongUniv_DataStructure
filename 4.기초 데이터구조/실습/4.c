#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int print(int m[][100], int n, int t)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < t; j++)
			printf(" %d", m[i][j]);
		printf("\n");
;	}
}

int main()
{
	int n, m, i = 1, j;
	int matrix[100][100] = { 0 };
	int r = 0, c = -1;
	int adder = 1;
	int rbound, cbound;

	scanf("%d %d", &n, &m);
	rbound = n-1;
	cbound = m;

	while (i <= n * m)
	{
		for (j = 0; j < cbound; j++)
		{
			c += adder;
			matrix[r][c] = i++;
		}
		cbound--;
		
		for (j = 0; j < rbound; j++)
		{
			r += adder;
			matrix[r][c] = i++;
		}
		rbound--;
		adder *= -1;
	}

	print(matrix, n, m);

	return 0;
}