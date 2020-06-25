#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct tree {
	int elem;
	struct tree* left, * right;
}TREE;

int addNode(TREE* root, int el, int le, int ri)
{
	TREE* l = 0, *r = 0;
	int res = 1;

	if (root->elem == el)
	{
		if (le)
		{
			l = (TREE*)malloc(sizeof(TREE));
			l->elem = le;
		}
		if (ri)
		{
			r = (TREE*)malloc(sizeof(TREE));
			r->elem = ri;
		}
		root->left = l;
		root->right = r;
		return 0;
	}
	if (res && root->left)
		res = addNode(root->left, el, le, ri);
	if (res && root->right)
		addNode(root->right, el, le, ri);
	return 1;
}

void search(TREE* r, char* com)
{
	char* p = com;
	if (r != 0)
		printf(" %d", r->elem);
	if (*p == 0)
	{
		printf("\n");
		return;
	}
	else if (*p == 'L' && r != 0)
	{
		search(r->left, p + 1);
	}
	else if (*p == 'R' && r != 0)
	{
		search(r->right, p + 1);
	}
}

int main()
{
	TREE root = { 0 };
	char com[101] = { 0 };
	int n, i;
	int el, le, ri;

	scanf("%d", &n);
	scanf("%d %d %d", &el, &le, &ri);
	root.elem = el;
	addNode(&root, el, le, ri);
	for (i = 1; i < n; i++)
	{
		scanf("%d %d %d", &el, &le, &ri);
		addNode(&root, el, le, ri);
	}

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(com);
		search(&root, com);
	}


	return 0;
}