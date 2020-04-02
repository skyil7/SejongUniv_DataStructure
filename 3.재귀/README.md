# 재귀<sup>recursive</sup>
알고리즘 자신을 이용하여 정의된 알고리즘을 재귀적 알고리즘이라 한다.

재귀 알고리즘은 문재를 부문재<sup>subproblem</sup>로 나눠서 푼다. 부문제가 충분히 작아지면 재귀 알고리즘은 재귀를 사용하지 않고 문제를 해결하는데 이를 베이스 케이스<sup>base case</sup>라고 한다.

## 기본 규칙
1. 베이스 케이스를 가져야 하고, 항상 베이스 케이스 방향으로 진행해야 한다.
2. 꼭 필요할 때만 사용하자. 반복되는 저장/복구 때문에 성능이 저하된다.

## 나쁜 재귀
### 잘못 설계된 재귀
- 베이스 케이스가 없거나 도달 불능
- 재귀 케이스가 베이스 케이스를 향해 작아진 부문제를 대상으로 재귀하지 않음
### 나쁜 재귀의 영향
- 부정확한 결과
- 미정지
- 기억장소 고갈

## 하노이 탑 문제
```pseudo
call A B C 3
	call A C B 2
		call A B C 1
			print A C
		print A B
		call C A B 1
			print C B
	print A C
	call B A C 2
		call B C A 1
			print B A
		print B C
		call A B C 1
			print A C
```

위는 `n=3`의 하노이 탑 재귀 호출 구조이다.

함수는 대강 `(from, by, to, n)`으로 이해하라.