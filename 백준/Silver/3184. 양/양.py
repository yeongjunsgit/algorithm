'''
미키네 뒷마당에는 양이 있다.
저녁 사이에 늑대들이 마당에 들어와 양을 공격했다.
하지만 양은 순순히 잡혀주지 않는다. 울타리로 이루어진 한 구역에
양과 늑대들이 있다.
만약 양이 늑대보다 많을 경우, 양이 늑대를 쫓아낸다 그 이외의 경우에는
늑대가 양을 잡아먹는다.
양과 늑대의 배치가 주어졌을때, 남은 양과 늑대의 수를 구하여라!
'''
'''
영역을 구하고 해당 영역에 있는 늑대와 양의 수를 따져보면 될것 같다!
'''
from collections import deque

directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())

farm = [list(input()) for _ in range(N)]

wolfs = 0
sheep = 0

visited = [[0] * M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if farm[i][j] != '#' and visited[i][j] == 0:
            que = deque()
            que.append([i, j])
            visited[i][j] = 1
            tmp_wolfs = 0
            tmp_sheep = 0

            while que:
                x, y = que.popleft()
                if farm[x][y] == 'v':
                    tmp_wolfs += 1
                elif farm[x][y] == 'o':
                    tmp_sheep += 1

                for f in range(4):
                    di, dj = directions[f]
                    nx = x + di
                    ny = y + dj

                    if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] == 0 and farm[nx][ny] != '#':
                        visited[nx][ny] = 1
                        que.append([nx, ny])

            if tmp_wolfs >= tmp_sheep:
                wolfs += tmp_wolfs
            else:
                sheep += tmp_sheep

print(f'{sheep} {wolfs}')
