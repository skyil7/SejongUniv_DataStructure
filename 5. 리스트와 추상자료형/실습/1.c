#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct list {
	char data;
	struct list* prev, *next;
}List;

void add(List li, int r, char e)
{
	List* p = &li, * n;
	int i;
	for (i = 0; i < r; i++)
	{
		if (p->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		p = p->next;
	}
	if (r == 0)
	{
		printf("invalid position\n");
		return;
	}
	n = (List*)malloc(sizeof(List));
	n->prev = p->prev;
	(n->prev)->next = n;
	n->next = p;
	p->prev = n;
	n->data = e;
}
void deleteElem(List li, int r)
{
	List* p = &li;
	int i;
	for (i = 0; i < r; i++)
	{
		if (p->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		p = p->next;
	}
	if (p->next == 0||r==0)
	{
		printf("invalid position\n");
		return;
	}
	(p->next)->prev = p->prev;
	(p->prev)->next = p->next;
	free(p);
}
void get(List li, int r)
{
	List* p = &li;
	int i;
	for (i = 0; i < r; i++)
	{
		if (p->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		p = p->next;
	}
	if (p->next == 0||r==0)
	{
		printf("invalid position\n");
		return;
	}
	printf("%c\n", p->data);
}
void print(List li)
{
	List* p;
	for (p = li.next; p->next; p = p->next)
		printf("%c", p->data);
	printf("\n");
}

int main()
{
	int n, i, r;
	char com, e;
	List head, tail;

	head.next = &tail;
	head.prev = 0;
	tail.next = 0;
	tail.prev = &head;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		scanf("%c", &com);
		getchar();
		//printf("com: %c\n", com);
		if (com == 'A')
		{
			scanf("%d", &r);
			getchar();
			scanf("%c", &e);
			getchar();
			add(head, r, e);
		}
		else if (com == 'D')
		{
			scanf("%d", &r);
			getchar();
			deleteElem(head, r);
		}
		else if (com == 'G')
		{
			scanf("%d", &r);
			getchar();
			get(head, r);
		}
		else if (com == 'P')
		{
			print(head);
		}
	}

	return 0;
}