#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node
{
	struct node* left, * right;
	int elem;
}NODE;

NODE* newRoot(int data, NODE* left, NODE* right)
{
	NODE* n;
	n = (NODE*)malloc(sizeof(NODE));
	n->elem = data;
	n->left = left;
	n->right = right;
	return n;
}
NODE* newLeaf(int data)
{
	NODE* n;
	n = (NODE*)malloc(sizeof(NODE));
	n->left = 0;
	n->right = 0;
	n->elem = data;
}
void print(NODE* t[], int n)
{
	NODE* node = t[n];
	printf(" %d", node->elem);
	if (node->left)
		printf(" %d", (node->left)->elem);
	if (node->right)
		printf(" %d", (node->right)->elem);
}

int main()
{
	NODE* t[9] = { 0 };
	int n;
	t[4] = newLeaf(70);
	t[5] = newLeaf(90);
	t[7] = newLeaf(130);
	t[8] = newLeaf(80);

	t[6] = newRoot(120, t[7], t[8]);
	t[2] = newRoot(30, t[4], t[5]);
	t[3] = newRoot(50, 0, t[6]);
	t[1] = newRoot(20, t[2], t[3]);

	scanf("%d", &n);
	if (n >= 1 && n <= 8)
		print(t, n);
	else
		printf("-1");

	return 0;
}