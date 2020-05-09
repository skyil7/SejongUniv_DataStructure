# 집합
집합 ADT는 유일한 개체들을 갖는다. (중복 X)   
집합 ADT 관련 작업들의 효율적인 구현을 위해, 집합을 집합 원소들의 정렬된 리스트로 표현한다.

집합의 주요 함수들은 아래와 같다.

```c
set union(B); // 집합 B와의 합집합
set intersect(B); // 집합 B와의 교집합
set subtract(B); // 집합 B를 차감한 차집합
```
집합 A와 B에 관한 주요 작업의 실행시간은 최대 O(|A| + |B|)시간이 되어야 한다.

위 함수 이외에도 집합 ADT는 아래 함수를 갖는다.
```c
// 일반 함수
int size();
bool isEmpty();
iter elements();
//질의 함수
bool member(e);
bool subset(B);
//갱신 함수
addElem(e);
removeElem(e);
//예외
emtySetException();
```
## 집합 응용
- 직접 응용
	-	키워드 검색
	-	집합론에 대한 계산
-	간접 응용
	-	알고리즘을 위한 보조 데이터 구조
	-	다른 데이터 구조를 구성하는 요소

## 집합을 연결리스트에 저장
- 집합을 연결리스트로 구현 가능
	- 각 노드가 하나의 집합원소 표현
	- 헤더 및 트레일러 이중연결리스트가 권장됨
- 원소들은 일정 순서에 의해 정렬되어 저장
- 기억장소 사용: O(n)
- 배열을 이용할 수도 있다!

## 집합 함수
- 주의사항: 이후 나올 집합 함수는 파괴적임.
	- 집합 A와 B를 보존하지 않음
- 성능은 최소 O(|A| + |B|) 보장되며, addLast 작업의 경우 O(1) 시간에 수행

### 합집합<sup>union</sup>
```python
def union(A,B)
	C = set()
	while (!A.isEmpty() and !B.isEmpty()):
		a,b = A.get(1), B.get(1)
		if a<b:
			C.addLast(a)
			A.removeFirst()
		elif a>b:
			C.addLast(b)
			B.removeFirst()
		else: # a==b
			C.addLast(a)
			A.removeFirst()
			B.removeFirst()
	
	while !A.isEmpty():
		a=A.get(1)
		C.addLast(a)
		A.removeFirst()
	while !B.isEmpty():
		b=B.get(1)
		C.addLast(b)
		B.removeFirst()
	return C
```
### 교집합<sup>intersect</sup>
```python
def intersect(A, B):
	C = set()
	while (!A.isEmpty() and !B.isEmpty()):
		a, b = A.get(1), B.get(1)
		if  a<b:
			A.removeFirst()
		elif a>b:
			B.removeFirst()
		else: # a==b
			C.addLast(a)
			A.removeFirst()
			B.removeFirst()
	while !A.isEmpty():
		A.removeFirst()
	while !B.isEmpty():
		B.removeFirst()
	return C
```
### 차집합<sup>subtract</sup>
```python
def subtract(A, B):
	C = set()
	while (!A.isEmpty() and !B.isEmpty()):
		a, b = A.get(1), B.get(1)
		if  a<b:
			C.addList(a)
			A.removeFirst()
		elif a>b:
			B.removeFirst()
		else: # a==b
			A.removeFirst()
			B.removeFirst()
	while !A.isEmpty():
		a = A.get(1)
		C.addLast(a)
		A.removeFirst()
	while !B.isEmpty():
		B.removeFirst()
	return C
```
### 소속과 부분집합
```python
def member(e):
	if(A.isEmpty()):
		return False
	p = A
	while True:
		a = p.elem
		if a<e:
			if p.next == null:
				return False
			else:
				p = p.next
		elif a>e:
			return False
		else: # a==e
			return True
```
```python
def subset(A, B):
	if A.isEmpty():
		return True
	p = A
	while True:
		if B.member(p.elem):
			if (p.next == null: # p is last node
				return True
			else:
				p = p .next
		else:
			return False
```
`subset()`의 실행시간은 O(|A||B|) 이다.

