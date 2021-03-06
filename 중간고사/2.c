#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int findRoute(int m, int n)
{
	if (m == 1)//1xn개의 길이 있으면 경우의 수는 n+1개
		return n + 1;
	if (n == 1)//위와 같음
		return m + 1;
	return findRoute(m - 1, n) + findRoute(m, n - 1);
	//바둑판에서 대각선 방향으로 가려면, 아래로 가거나 옆으로 가는 두 경우 중 하나만 선택하면 됨
	//두 경우에서 발생하는 수의 합이 가능한 모든 경우의 수
}

int main()
{
	int m, n;

	scanf("%d", &m);
	scanf("%d", &n);

	printf("%d", findRoute(m, n));

	return 0;
}