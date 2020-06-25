#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct q {
	struct q* next;
	int uid;
} QU;

int isEmpty(QU* f)
{
	if (f == 0)
	{
		printf("empty queue!\n");
		return 1;
	}
	return 0;
}

void enqueue(QU** f, QU** r, int uid)
{
	QU* n;

	printf("%d 예약\n", uid);

	n = (QU*)malloc(sizeof(QU));
	n->uid = uid;
	n->next = 0;
	if (*f == 0) //첫 원소면
	{
		*f = n;
		*r = n;
		return;
	}
	(*r)->next = n;
}

void dequeue(QU** f, QU** r)
{
	QU* p;
	if (isEmpty(*f))
	{
		return;
	}
	printf("printing %d...\n", (*f)->uid);
	p = *f;
	*f = (*f)->next;
	free(p);
}

void front(QU* f)
{
	if (isEmpty(f))
	{
		return;
	}
	printf("다음 출력: %d\n", (f)->uid);
}

void size(QU* f)
{
	int n = 0;
	QU* p;
	for (p = f; p; p = p->next)
		n++;
	printf("대기 인원: %d명\n", n);
}

void elements(QU* f)
{
	int n = 0;
	QU* p;
	printf("대기열: ");
	for (p = f; p; p = p->next)
		printf(" %d", p->uid);
	printf("\n");
}

int main()
{
	QU* f = 0, *r = 0;
	int com;
	int uid;
	
	// 프린터 예약 프로그램

	while (1)
	{
		printf("1. 프린트 예약 2. 프린트 진행 3. 다음 출력 확인 4. 대기 인원수 5. 대기열 출력\n");
		scanf("%d", &com);
		if (com == 1)
		{
			printf("예약자 ID: ");
			scanf("%d", &uid);
			enqueue(&f, &r, uid);
		}
		else if (com == 2)
		{
			dequeue(&f, &r);
		}
		else if (com == 3)
		{
			front(f);
		}
		else if (com == 4)
		{
			size(f);
		}
		else if (com == 5)
		{
			elements(f);
		}
		else
			return;
	}


	return 0;
}