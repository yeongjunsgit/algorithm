'''
태균이는 태권도 겨루기 중이다 지금 처참하게 지고 있지만 숨겨둔 필살기를 이용하여 빠르게 역전 하려고 한다
태균이의 필살기는 다음과 같다.
1. 상대에게 3점을 내주는 대신, 현재 나의 점수가 2배가 되는 사기 스킬이다.
2. 무조건 1점을 얻는 안정적인 사기 스킬이다.

2가지의 필살기를 이용하여 상대와 점수가 똑같아지고 싶다.
이때 최소로 필살기를 사용하는 횟수를 구하여라!
'''
'''
이동횟수를 dp 처럼 관리해서 하면 되지 않을까?
'''
import heapq

# T = 테스트 케이스의 개수
T = int(input())

for tc in range(1, T+1):
    start, end = map(int, input().split())

    visited = [int(1e9)] * 10000
    visited[start] = 0
    visited_target = [[] for _ in range(10000)]
    pq = []
    heapq.heappush(pq, [0, start, end])

    while pq:
        moved, now, target = heapq.heappop(pq)
        if now == target:
            print(moved)
            break

        double_now = now * 2
        double_target = target + 3

        if double_now <= double_target and double_target not in visited_target[double_now]:
            heapq.heappush(pq, [moved+1, double_now, double_target])
            visited_target[double_now].append(double_target)
        if target not in visited_target[now+1]:
            heapq.heappush(pq, [moved+1, now+1, target])
            visited_target[now+1].append(target)
