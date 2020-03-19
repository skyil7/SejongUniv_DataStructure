#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void ABS(int* arr, int k)
{
	int* p = arr;
	int max, * maxp;

	p += k;
	max = *p;
	maxp = p;
	for (p += 1; p < arr + 10; p++)
	{
		if (*p > max)
		{
			max = *p;
			maxp = p;
		}
	}
	*maxp = *(arr + k);
	*(arr + k) = max;
}

int main()
{
	int ar[10], k, *p;
	
	for (p = ar; p < ar + 10; p++)
		scanf("%d", p);

	for (k = 0; k < 10; k++)
		ABS(ar, k);

	for (p = ar; p < ar + 10; p++)
		printf(" %d", *p);

	return 0;
}