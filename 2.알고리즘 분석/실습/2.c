#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int mostOnes(int** A, int n)
{
	int i = 0, j = 0, res = 0;
	while (i < n)
	{
		if (A[i][j] == 1)
		{
			j++;
			res = i;
		}
		else
			i++;
	}
	return res;
}

int main()
{
	int n;
	int i, j;
	int** mat;

	scanf("%d", &n);

	mat = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		mat[i] = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &mat[i][j]);

	i = mostOnes(mat, n);
	printf("%d", i);

	for (i = 0; i < n; i++)
		free(mat[i]);
	free(mat);

		return 0;
}