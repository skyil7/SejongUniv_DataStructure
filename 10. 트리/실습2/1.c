#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct tree {
	int id, data;
	struct tree* left, * right;
}TREE;

void setLR(TREE* t, TREE* l, TREE* r)
{
	t->left = l;
	t->right = r;
}

TREE* newNode(int id, int data)
{
	TREE* n;
	n = (TREE*)malloc(sizeof(TREE));
	n->id = id;
	n->data = data;
	n->left = 0;
	n->right = 0;

	return n;
}

void preorder(TREE* root)
{
	if (!root)
		return;
	printf(" %d", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(TREE* root)
{
	if (!root)
		return;
	inorder(root->left);
	printf(" %d", root->data);
	inorder(root->right);
}

void postorder(TREE* root) {
	if (!root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf(" %d", root->data);

}

void findNode(TREE* root, int ID, int type) {

	if (ID <= 0 || ID > 8)
		printf("-1");
	else if (!root);
	else if (root->id == ID) {
		if (type == 1) {
			preorder(root);
		}
		else if (type == 2) {
			inorder(root);
		}
		else if (type == 3) {
			postorder(root);
		}
	}
	else {
		findNode(root->left, ID, type);
		findNode(root->right, ID, type);
	}
}

int main()
{
	TREE root;
	TREE* l, * r;
	TREE* from;

	int a, b;
	//트리 구현
	if (1)
	{
		root.id = 1;
		root.data = 20;

		l = newNode(2, 30);
		r = newNode(3, 50);
		setLR(&root, l, r);

		l = newNode(4, 70);
		r = newNode(5, 90);
		setLR(root.left, l, r);

		l = 0;
		r = newNode(6, 120);
		setLR(root.right, l, r);

		l = newNode(7, 130);
		r = newNode(8, 80);
		setLR((root.right)->right, l, r);
	}
	//트리 구현

	scanf("%d %d", &a, &b);
	findNode(&root, b, a);


	return 0;
}