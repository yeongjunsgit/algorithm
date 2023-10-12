from collections import deque
from itertools import combinations

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

def bfs(arr):
    global min_move
    max_move = 0
    visited = [[int(1e9)] * N for _ in range(N)]
    que = deque()
    for l in arr:
        si, sj = l[0], l[1]
        que.append([0, si, sj])
        visited[si][sj] = 0

    while que:
        move, x, y = que.popleft()
        for f in range(4):
            nx = x + di[f]
            ny = y + dj[f]

            if 0 <= nx < N and 0 <= ny < N:
                if lab[nx][ny] == 2 or lab[nx][ny] == 0:
                    if visited[nx][ny] > move+1:
                        visited[nx][ny] = move + 1
                        if max_move < move + 1:
                            max_move = move + 1
                        que.append([move+1, nx, ny])

    check = True
    for t in range(N):
        if check is False:
            break
        for u in range(N):
            if visited[t][u] == int(1e9):
                if lab[t][u] == 0 or lab[t][u] == 2:
                    check = False
                    break

    if check is True:
        if max_move < min_move:
            min_move = max_move


N, M = map(int, input().split())

lab = [list(map(int, input().split())) for _ in range(N)]

virus = []

for w in range(N):
    for z in range(N):
        if lab[w][z] == 2:
            virus.append([w, z])

min_move = int(1e9)

check_lis = list(combinations(virus, M))

for c in check_lis:
    bfs(c)


if min_move != int(1e9):
    print(min_move)
else:
    print(-1)