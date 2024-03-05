'''
스카이 콩콩 2개 A, B가 있다. 각각 A, B에 적힌 번호가 스카이콩콩이 가진 힘이다.
스카이 콩콩을 가볍게 타면 현재 위치에서 해당 스카이 콩콩의 힘만큼 -, + 하여 이동할 수 있다.
스카이 콩콩을 썌게 타면 현재 위치 * 스카이 콩콩의 힘의 위치로 이동이 가능하다.
그냥 양 옆으로 1칸씩 걸어가는 것도 가능하다. 이렇게 했을때, 주미의 위치까지 가장 빠르게 갈 수있는
이동 횟수를 구하여라.
'''
'''
bfs처럼 하자! 대신 목표지점에 도착하는 순간 끝
visited를 이용해서 해당 위치에 갔을 때, 이동횟수를 기록하여 그보다 더 오래걸려서 오면 skip
'''
from collections import deque

# A, B = 각 스카이콩콩의 힘, N = 동규의 현재 위치, M = 주미의 위치
A, B, N, M = map(int, input().split())

visited = [int(1e9)] * 100001
visited[N] = 0

que = deque()
que.append(N)

while que:
    now = que.popleft()
    moved = visited[now]
    if now == M:
        print(moved)
        break
    commands = [now+1, now-1, now+A, now+B, now-A, now-B, now*A, now*B]
    for c in commands:
        if 1 <= c <= 100000 and visited[c] > moved+1:
            visited[c] = moved+1
            que.append(c)
