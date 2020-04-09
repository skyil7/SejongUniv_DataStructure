#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int print(int m[][100], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %d", m[i][j]);
		printf("\n");
;	}
}

int main()
{
	int n, i = 1;
	int m[100][100] = { 0 };
	int row = 0, col = 0;
	int cadder = 1;

	scanf("%d", &n);

	while (i <= n*n)
	{
		m[row][col] = i++;
		col += cadder;
		if (col == n || col == -1)
		{
			cadder *= -1;//reverse direction
			col += cadder;
			row++;
		}
	}

	print(m, n);

	return 0;
}