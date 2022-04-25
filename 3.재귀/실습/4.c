#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int findMax(int* ar, int* end)
{
	if (ar == end - 1)
		return *ar;
	if (*ar > * (ar + 1))
		*(ar + 1) = *ar;
	return findMax(ar + 1, end);
}

int main()
{
	int n;
	int ar[20] = { 0 };
	int* p;

	scanf("%d", &n);
	for (p = ar; p < ar + n; p++)
		scanf("%d", p);

	printf("%d", findMax(ar, ar + n));

	return 0;
}
