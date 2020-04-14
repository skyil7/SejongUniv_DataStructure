# 추상자료형
추상자료형<sup>Abstract Data Type:ADT</sup>은 다음을 명세한다.

- 저장된 데이터
- 데이터에 대한 작업들
- 작업 중 발생 가능한 에러 상황들

그러나 구체적으로 이러한 작업과 데이터를 어떻게 프로그램적으로 정의할 지는 명세하지 않는다.

# 리스트 ADT
리스트 ADT는 연속적인 임의 개체들을 모델링 한다. 각 원소는 다른 자료형을 가질 수 있다. 원소에 대한 접근은 순위<sup>rank</sup>를 이용한다.

## 리스트 ADT의 메소드
원소는 그 순위를 특정하여 접근, 삽입, 삭제될 수 있다.

- 일반 메소드
	- boolean isEmpty()
	- interger size()
	- Iterator elements()
- 접근 메소드
	- element get(r)
- 갱신 메소드
	- element set(r, e)
	- add(r,e), addFirst(e), addLast(e)
	- element remove(r)
	- element removeFirst(),
	- element removeLast()

## 예외<sup>Exception</sup>
어떤 ADT 작업을 실행하고자 할 때 발생 가능한 오류 상황. `throw <Exception>`과 같이 표현한다.

리스트 ADT의 예외들
- invalidRankException()
- fullListException()
- emptyListException()

## 리스트의 응용
리스트 ADT는 원소들의 순서 집단을 저장하기 위한 기초적이고 일반적인 목적의 데이터구조다.

- 직접 응용
	- 스택, 큐, 집합 등을 표현하기 위한 도구
	- 소규모 데이터베이스
- 간접 응용
	- 더 복잡한 데이터구조를 구축하기 위한 재료로 활용

# 리스트 ADT 구현
## 배열을 이용한 구현
- N개의 단순 또는 복잡한 원소들로 구성된 배열 V
- 변수 n으로 리스트의 크기를 관리
- 배열에서 순위는 0에서 출발
- 작업 `get(r)` 또는 `set(r,e)`는 O(1) 시간에 V[r]을 각각 반환 또는 저장하도록 구현
	- `r < 0` 또는 `r > n-1`인 경우는 예외처리 필요

### 필요 작업
- 초기화<sup>initialization</sup>: 빈 배열을 생성, O(1)
- 순회<sup>traverasal</sup>: 모든 원소를 순회, O(n)
- 삽입<sup>insertion</sup>: r순위에 새 원소 e가 들어갈 자리를 만들기 위해 최대 O(n) 시간 소요
- 삭제<sup>deletion</sup>: r순위의 원소를 삭제하고 빈 자리를 채우기 위해 최대 O(n) 시간 소요

### 성능
배열을 이용하여 리스트 ADT를 구현할 경우
- 데이터 구조에 의한 기억장소 사용량: O(n)
- size, isempty, get, set: O(1)
- add,remove: O(n)
- addFirst, removeFirst: O(n)
- addLast, removeLast: O(1)

이때, 배열을 원형으로 이용하면 `addFirst`와 `removeFirst`를 O(1)로 만들 수 있다.

add 작업에서 배열이 가득찼다면 배열을 동적으로 확장하여 해결 가능하다.

## 연결리스트를 이용한 구현
단일 연결리스트 혹은 이중 연결리스트를 활용
 