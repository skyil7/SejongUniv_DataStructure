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
	int r = 0, c = 0;
	int sr = 0, sc = 0;

	scanf("%d %d", &n, &m);

	for (sc = 0; sc < m; sc++)
	{
		r = sr, c = sc;
		while (c >= 0 && r < n)
			matrix[r++][c--] = i++;// 대각선 그리기
	}
	sc = m - 1;
	for (sr = 1; sr < n; sr++)
	{
		r = sr, c = sc;
		while (c >= 0 && r < n)
			matrix[r++][c--] = i++;// 대각선 그리기
	}

	print(matrix, n, m);

	return 0;
}