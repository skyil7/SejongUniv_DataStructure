#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
	19011484 백지오
	리스트 ADT로 파이썬의 자료구조인 dictionary(사전)를 구현해보았습니다.
	C 언어에서는 딕셔너리 같이 동적인 자료형이 없어, 데이터를 다룰 때 힘들었는데 이를 이용해 해결 가능할 듯 합니다.
	각 원소는 문자열(100자 이하)인 key값과 정수 데이터로 구성됩니다.
	일반 리스트 처럼 마지막 원소를 넣거나 삭제하거나, 키값을 이용한 삭제, 혹은 탐색이 가능합니다.
*/

typedef struct Dictionary {
	int data; //데이터를 저장
	char key[100]; //키 값을 저장
	struct Dictionary* next;
}dict;

// 비었으면 1 리턴
int isEmpty(dict d)
{
	if (d.next)
		return 0;
	return 1;
}
// 사이즈 리턴
int size(dict d)
{
	return d.data;
}
// 모든 원소 출력 (elements()와 같음)
void print_all(dict d)
{
	dict* p;
	for (p = d.next; p->next; p = p->next)
	{
		printf("(%s, %d)\n", p->key, p->data);
	}
	printf("(%s, %d)\n", p->key, p->data);
}
// 원소 추가하고 성공 시 1 리턴 (addLast()와 같음)
int input_data(dict *d)
{
	dict *newElem, *p;

	getchar();
	newElem = (dict*)malloc(sizeof(dict));
	printf("키값을 입력하세요: ");
	gets(newElem->key);
	printf("데이터를 입력하세요. (정수): ");
	scanf("%d", &newElem->data);
	newElem->next = 0;//초기화

	for (p = d; p->next; p = p->next);

	p->next = newElem;
	printf("%s, %d 입력됨\n", newElem->key, newElem->data);

	return 1;
}
// 키값으로 원소 찾고 발견하면 1 리턴 (전체 탐색)
int search_data(dict *d)
{
	dict *p;
	char query[100] = { 0 };

	getchar();
	printf("찾고자 하는 원소의 키값 입력: ");
	gets(query);

	for (p = d; p->next; p = p->next)
	{
		if (!strcmp(query, p->key))//키값 일치하면
		{
			printf("Data: %d\n", p->data);
			return 1;
		}
	}
	if (!strcmp(query, p->key))//마지막 원소가 안됨..
	{
		printf("Data: %d\n", p->data);
		return 1;
	}
	printf("일치하는 데이터 미발견\n");
	return 0;
}
// 맨 뒤의 값 삭제
void removeLast(dict *d)
{
	dict* p, * prev= d;
	for (p = d; p->next; p = p->next)
		prev = p;//마지막 원소까지 포인터 이동, prev 포인터도 만들걸...
	prev->next = 0;
	free(p);
}
// 키값으로 삭제
int removeKey(dict* d)
{
	dict* p, * prev = d;
	char query[100] = { 0 };
	int flag = 0;

	getchar();
	printf("지우고자 하는 원소의 키값 입력: ");
	gets(query);

	for (p = d; p->next; p = p->next)
	{
		if (!strcmp(query, p->key))//키값 일치하면
		{
			flag = 1;
			break;
		}
		prev = p;
	}
	if (!strcmp(query, p->key))//마지막 원소가 안됨..
	{
		flag = 1;
	}
	if (!flag) // 못 찾았으면
	{
		printf("일치하는 데이터 미발견\n");
		return 0;
	}
	prev->next = p->next;//지난 원소랑 다음 원소 연결
	free(p);
	return 1;
}

int main()
{
	int cmd = -1;
	dict myDict = { 0 };//헤드노드의 선언. 헤드 노드는 data에 size를 저장
	myDict.data = (int *)malloc(sizeof(int));
	myDict.data = 0;//size 초기화
	

	while (1)
	{
		printf("1.사전 사이즈 출력\n");
		printf("2.사전에 값 넣기\n");
		printf("3.키값으로 값 찾기\n");
		printf("4.사전 전체 출력\n");
		printf("5.맨 뒤의 값 삭제\n");
		printf("6.키값으로 삭제\n");
		printf("이외는 종료\n");
		printf("명령 번호 입력: ");
		scanf("%d", &cmd);
		if (cmd == 1)
			printf("%d\n", size(myDict));
		else if (cmd == 2)
			myDict.data += input_data(&myDict);//성공하면 size 1추가
		else if (cmd == 3)
			search_data(&myDict);
		else if (cmd == 4)
			print_all(myDict);
		else if (cmd == 5)
			removeLast(&myDict);
		else if (cmd == 6)
			removeKey(&myDict);
		else
			break;
	}

	return 0;
}