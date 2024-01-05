'''
젤다가 동굴안을 탐험한다.
젤다가 루피를 가장 적게 먹고 끝에 도착할 수 있는 경우의 소모되는 루피를 출력하자!
'''
'''
흠 최소 비용이라면 역시 다익스트라지 않을까??
비슷한 뉘앙스로 bfs랑 섞어해보고 안되면 쌩 다익스트라로 해보자!
'''
from collections import deque

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

tc = 1

while True:
    N = int(input())
    if N == 0:
        break
    else:
        cave = [list(map(int, input().split())) for _ in range(N)]
        visited = [[int(1e9)] * N for _ in range(N)]
        link = (0, 0)
        visited[0][0] = cave[0][0]

        que = deque()
        que.append(link)

        while que:
            x, y = que.popleft()

            for f in range(4):
                nx = x + di[f]
                ny = y + dj[f]

                if 0 <= nx < N and 0 <= ny < N:
                    new_loopy = visited[x][y] + cave[nx][ny]
                    if visited[nx][ny] > new_loopy:
                        visited[nx][ny] = new_loopy

                        que.append((nx, ny))

        print(f'Problem {tc}: {visited[N-1][N-1]}')
        tc += 1
