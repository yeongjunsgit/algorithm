'''
연구소 바이러스 침투
벽 3개 세워서 바이러스 막자
가장 많은 안전구역 확보하라
'''
'''
어떻게 이걸 알 수 있을까?
전부다 넣어보지 않고서야... 흠...
전부다 넣어보지 뭐 그럼
'''
from collections import deque

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]


def bfs():
    visited = [[0] * M for _ in range(N)]
    cnt = len(virus)
    for j in range(len(virus)):
        que = deque()
        vx, vy = virus[j]
        visited[vx][vy] = 1
        que.append([vx, vy])

        while que:
            tvx, tvy = que.popleft()
            for f in range(4):
                nx = tvx + direction[f][0]
                ny = tvy + direction[f][1]

                if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] == 0 and arr[nx][ny] == 0:
                    visited[nx][ny] = 1
                    cnt += 1
                    que.append([nx, ny])

    return cnt


def perm(s, e):
    global result
    if s == e:
        for z in range(3):
            x, y = zeros[pq[z]]
            arr[x][y] = 1
        tmp = bfs()
        tmp_result = (N*M) - ones - tmp
        if result < tmp_result:
            result = tmp_result
        for a in range(3):
            x, y = zeros[pq[a]]
            arr[x][y] = 0

    else:
        for i in range(len(zeros)):
            if used[i] == 0:
                used[i] = 1
                pq.append(i)
                perm(s+1, e)
                used[i] = 0
                pq.pop()


# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

zeros = []
ones = 3
virus = []
result = 0

for p in range(N):
    for q in range(M):
        if arr[p][q] == 0:
            zeros.append([p, q])

        elif arr[p][q] == 1:
            ones += 1

        elif arr[p][q] == 2:
            virus.append([p, q])

used = [0] * len(zeros)
pq = []

perm(0, 3)

print(result)
