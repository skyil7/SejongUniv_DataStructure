# 스택<sup>Stack</sup>
내용물을 쌓고 꺼내는 것처럼, Last In First Out(후입선출)인 자료구조.   
삽입과 삭제가 스택의 top이라는 부분에서 수행된다.

스택의 주요 함수는 아래와 같다.
```c
void push(e); //원소를 삽입
element pop(); // 가장 최근에 삽입된 원소를 삭제하여 반환

element top(); // 가장 최근에 삽인된 원소를 반환
int size(); // 저장된 원소의 수를 반환
boolean isEmpty();
iterator elements(); // 스택 전체 원소 반환
```

스택에서 발생 가능한 예외는 아래와 같다.
```c
emptyStackException();
fullStackException();
```

## 스택의 활용
- 직접 응용
	- 웹브라우저의 방문 기록
	- 문서편집기에서 되돌리기 기록
	- 윈도 운영체제에서 겹쳐진 윈도우들
	- C++ 혹은 자바에서 함수의 연쇄적인 호출
	- 재귀의 구현
- 간접 응용
	- 알고리즘 수행을 위한 보조 데이터구조
	- 다른 데이터구조를 구성하는 요소

## 스택의 구현
- 배열을 이용
	- 변수 t를 이용하여 top원소의 첨자를 관리
	- 크기 제한이 있으니 `fullStackException()`을 고려하자!
	- 기억장소를 O(n)만큼 사용하고, 각 작업의 실행시간은 O(1)임.
	- 스택의 최대 크기가 예측 가능해야 하고, 동적이지 못함.
- 연결리스트를 이용
	- 단일연결리스트를 사용하여 구현 가능
		- 삽입/삭제가 top에서만 수행되므로, 헤더노드는 불필요함
	- top 원소를 연결리스트의 첫 노드에 저장하고 이곳을 t로 가리킴
	- 기억장소 사용 O(n)
	- 각 작업 시간 O(1)

## 스택의 응용 문제
### 심볼 균형
괄호나 주석 등의 심볼(`(`, `{`, `"`, `/*` 등..)의 균형을 체크하는데 스택을 활용할 수 있다.

### 역순 출력
문자열의 역순 출력에 스택을 활용할 수 있다.

### 후위수식
우리가 일반적으로 사용하는 중위수식<sup>infix expression</sup>과 달리, 컴퓨터는 후위수식<sup>postfix expression</sup>을 사용한다.

아래 두 식은 같은 식을 각각 중위수식과 후위수식으로 나타낸 것이다.
```
5 x 3 + 2 (6 + 3) x 2
5 3 x 2 + 6 3 + 2 x + 
```

중위수식은 피연산자 연산자 피연산자의 순서로 나타내어지고, 우선순위는 괄호에 의해 무시될 수 있다.  
반면, 후위수식에서는 피연산자.. 연산자 순서로 나타내어진다.

중위수식을 후위수식으로 바꾸어 평가하는데 스택을 응용할 수 있다.

```python
def evaluate(): # 후위수식의 평가(연산)
	# input: stream of legal postfix exp
	# output number

	S = stack()
	while !endOfFile():
		s = getSymbol()
		if isOperand(s): # 피연산자인지
			S.push(s)
		else: # 연산자임
			a = S.pop()
			b = S.pop()
			S.push(doOperator(s,b,a))
	return S.pop()
```

```python
def convert(): # 중위수식을 후위수식으로 변환
	#input stream of legal infix expression
	#output stream of legal postfix expression

	S = stack()
	while !endOfFile():
		s = getSymbol()
		if isOperand(s):
			write(s)
		elif s=='(':
			S.push(s)
		elif s==')':
			while S.top() != '(':
				write(S.pop())
			S.pop()
		else # s가 연산자
			while !S.isEmpty() and P[s] <= P[S.top()]:
				write(S.pop())
			S.push(s)
	while !S.isEmpty():
		write(S.pop())
	return
```
