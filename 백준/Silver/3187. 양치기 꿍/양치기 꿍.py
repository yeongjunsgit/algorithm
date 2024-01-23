'''
양들과 늑대를 싸우게 하자
늑대는 양을 잡아먹는다, 하지만 만약 양들이 늑대보다 많다면 양들이 늑대를 다 잡아버린다.
현재 목장의 현황이 주어진다.
늑대와 양은 울타리를 넘어다닐 수 없으며, 양과 늑대의 싸움은 울타리로 이루어진 한 구역에서 발생한다.
현재 현황에서 싸움이 끝난후 남는 양과 늑대의 수를 구하여라.
'''
'''
단순 bfs인듯?
'''
from collections import deque

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


# N = 세로길이, M = 가로길이
N, M = map(int, input().split())

farm = [list(input()) for _ in range(N)]
visited = [[0] * M for _ in range(N)]

sheep = 0
wolf = 0

for i in range(N):
    for j in range(M):
        if visited[i][j] == 0:
            if farm[i][j] != '#':
                que = deque()
                tmp_sheep = 0
                tmp_wolf = 0
                que.append([i, j])
                while que:
                    x, y = que.popleft()
                    if visited[x][y] == 0:
                        if farm[x][y] == '.':
                            visited[x][y] = 1

                        elif farm[x][y] == 'k':
                            tmp_sheep += 1
                            visited[x][y] = 1

                        elif farm[x][y] == 'v':
                            tmp_wolf += 1
                            visited[x][y] = 1

                        for f in range(4):
                            nx = x + di[f]
                            ny = y + dj[f]

                            if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] == 0:
                                if farm[nx][ny] != '#':
                                    que.append([nx, ny])

                if tmp_sheep > tmp_wolf:
                    sheep += tmp_sheep
                else:
                    wolf += tmp_wolf

print(f'{sheep} {wolf}')
