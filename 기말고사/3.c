#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct t {
	struct t* left, *right;
} TREE;

int isMirrored(TREE* t1, TREE* t2) // 거울상 확인 함수
{
	// 모든 노드가 left, right = 0으로 초기화 되어 있어야 정상 작동합니다.
	if (t1 == 0 && t2 == 0) //두 서브트리가 모두 null
		return 1;
	if (t1 == 0 && t2 != 0) // 두 서브트리 중 하나만 null
		return 0;
	if (t1 != 0 && t2 == 0) // 두 서브트리 중 하나만 null
		return 0;

	return isMirrored(t1->left, t2->right) && isMirrored(t1->right, t2->left); 
}

void makeNode(TREE* t, int l, int r)
{
	TREE* a, * b;
	if (l)
	{
		a = (TREE*)malloc(sizeof(TREE));
		a->left = 0;
		a->right = 0;
		t->left = a;
	}
	else
		t->left = 0;
	if (r)
	{
		b = (TREE*)malloc(sizeof(TREE));
		b->left = 0;
		b->right = 0;
		t->right = b;
	}
	else
		t->right = 0;
}

int main()
{
	TREE a;
	
	// 이진트리가 대칭 형태인지 확인하는 프로그램
	
	makeNode(&a, 1, 1);
	makeNode(a.left, 1, 0);
	makeNode(a.right, 0, 1);
	printf("트리 생성됨\n");
	printf("결과: %d", isMirrored(&a, &a));

	return 0;
}