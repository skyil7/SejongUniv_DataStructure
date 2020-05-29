# 큐<sup>Queue</sup>
큐 ADT는 임의의 개체들을 저장하며, 선입선출 (First In, First Out; FIFO)을 따른다.     
삽입은 큐의 뒤(rear), 삭제는 큐의 앞(front)에서 수행한다.

## 주요 큐 함수
```c
void enqueue(e);// 큐의 뒤에 원소를 삽입
elem dequeue(); // 큐의 앞에서 원소를 삭제하여 반환

elem front(); // 큐의 앞에 있는 원소를 반환
int size();
bool isEmpty();
iter elements();
```

## 큐의 응용
- 직접 응용
	- 대기열, 관료적 체제
	- 공유자원에 대한 접근
	- 멀티프로그래밍
- 간접 응용
	- 알고리즘 수행을 위한 보조 데이터구조
	- 다른 데이터구조의 구성 요소

## 배열 기반 큐
크기 N의 배열을 **원형**으로 사용한다. `f`와 `r` 두 개의 변수를 사용하여 front와 rear 위치를 기억한다. 이때, f가 일부러 front원소 한 칸 앞을 가르키도록 하는 응용도 가능하다.

빈 큐와 만원 큐를 차별화하기 위해, 한 개의 빈 방을 예비로 둔다.

### 함수의 구현
```python
def size():
	return (N-f+r+1)%N
def isEmpty():
	return (r+1)%N == f
def isFull():
	return (r+2)%N == f
```

## 연결리스트 기반 큐
단일연결리스트를 사용하여 큐를 구현할 수 있다. 삽입과 삭제가 특정 위치에서만 수행되므로, 역방향링크는 불필요하다.

# Dequeue ADT
Dequeue는 스택과 큐를 합친 방식으로 동작한다. 삽입과 삭제가 앞과 뒤 모두에서 이루어진다.

아래와 같은 주요 함수를 갖는다.

```c
void push(e); // Front에 원소 삽입
elem pop(); // Front 위치의 원소를 삭제하여 반환
void inject(e); // Rear 위치에 원소 삽입
elem eject(); // Rear 위치의 원소를 삭제하여 반환

elem front();
elem rear(); // 각각 삭제없이 반환
int size();
bool isEmpty();
```

이중연결리스트를 활용하여 dequeue를 구현 가능한데, 삽입 삭제 위치가 정해져 있으므로 특별노드는 불필요하다.