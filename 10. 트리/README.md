# 트리 ADT
트리는 계층적으로 저장된 데이터 원소들을 모델링한다.

최상위 원소를 제외하고, 각 원소는 부모 원소와 0개 이상의 자식 원소를 가진다.

## 트리 용어
- 루트(root): 뿌리 노드, 부모가 없는 최상위 노드
- 내부 노드(internal node), leaf: 자식이 없는 노드
- 형제(siblings): 같은 부모를 가진 노드들
- 조상 노드: 부모, 조부모 노드 등
- 자손 노드: 자식, 손주 노드 등
- 부트리(Subtree): 노드와 그 노드의 자손들로 구성된 트리
- 경로: 조상 또는 자손을 따라 이어진 노드 시퀀스 (예: ABD)
- 경로 길이: 경로내 간선의 수
- 노드의 깊이: 루트로부터 노드에 이르는 유일한 경로의 길이
- 노드의 높이: 노드로부터 리프에 이르는 가장 긴 경로의 길이
- 트리의 높이: 루트의 높이

## 순서트리<sup>ordered tree</sup>
순서트리는 각 노드의 자식들에 대해 선형 순서가 정의되어 있는 트리를 말한다.   
(목차가 있는 책 등)

## 트리 ADT 함수
```c
node root();
node parent(v);
node children(v);
elem element(v);

bool isInternal(v);
bool isExternal(v);
bool isRoot(v);

swap Elements(v, w);
elem setElem(v, e);
```

## 트리의 응용
- 조직구성도
	- 내부노드: 부, 과, 팀 등
	- 외부노드: 직원
- 파일 시스템
	- 내부노드: 폴더
	- 외부노드: 파일
- 프로그래밍 환경
	- 내부노드: 프로그램 구조물
	- 외부노드: 어휘, 상수, 심볼 등

## 트리 함수의 구현
```python
def height(v):
	if isExternal(v):
		return 0
	else:
		h=0
		for child in children(v):
			h = max(h, height(child))
		return 1+h
```
- 선위순회 (Preorder traversal)
	- 선위순회에서는, 노드가 그의 자손들보다 앞서 방문된다. (root -> leaf)
	- 실행시간은 O(n)
```python
def preOrder(v):
	visit(v)
	for w in children(v):
		preOrder(w)
```
- 후위순회 (Postorder traversal)
	- 노드가 그의 자손들보다 나중에 방문된다. (leaf -> root)
	- 실행시간은 선위와 같은 O(n)
```python
def postOrder(v):
	for w in children(v):
		postOrder(w)
	visit(v)
```
- 레벨 순회
	- 레벨 순회는 트리의 특정 깊이 d에 존재하는 모든 노드들을 순회한다.
	- 큐를 이용하여, 깊이 d의 모든 노드들이 깊이 d+1의 노드들에 앞서 방문된다.
	- 실행시간은 O(n)이다.
```python
def levelOrder(v):
	q = queue()
	q.enqueue(v)
	while !q.isEmpty():
		v = q.dequeue()
		visit(v)
		for w in children(v):
			q.enqueue(w)
	return
```

## 이진 트리 ADT
이진트리 ADT는 각 원소가 0개 혹은 2개의 자식 노드를 갖는 순서트리를 모델링 한다. 각 자식은, 왼쪽 및 오른쪽 자식이라 부른다.

### 배열 기반 이진 트리
1D 배열로 이진트리를 표현할 수 있다.

- 랭크 i의 노드에 대해
	- 왼쪽 자식의 위치는 2i
	- 오른쪽 자식의 위치는 2i+1
	- 부모의 위치는 i/2

노드 간의 링크를 저장할 필요가 없다.    
순위 0 셀은 사용하지 않고, 미사용 셀에는 특별한 값을 저장한다. (널값 혹은 널마커 #)

최선의 경우(완전 이진 트리) 메모리 사용량과 크기가 일치하지만, 최악의 경우에는 N = 2**n -1 이 될 수도 있다.

### 연결 이진 트리
각 노드에 아래 내용을 저장한다.
- 원소
- 부모노드
- 왼쪽 자식노드
- 오른쪽 자식노드
