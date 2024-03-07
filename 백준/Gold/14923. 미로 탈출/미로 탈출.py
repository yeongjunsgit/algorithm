'''
미로를 탈출하자 현재 위치와 탈출구의 위치가 주어졌을 때, 탈출구로 가는 최단 거리를 구하자!
이때, 단 1번만 벽을 부실 수 있다. 벽들의 위치가 같이 주어졌을 때, 최단 거리 구하자
단, 도달 할 수 없다면 -1 출력
'''
'''
bfs 두가자
'''
from collections import deque
import sys
# sys.stdin = open('input.txt')


# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())

start = list(map(int, input().split()))
end = list(map(int, input().split()))

labyrinth = [list(map(int, input().split())) for _ in range(N)]
visited = [[int(1e9)] * M for _ in range(N)]
visited_wall = [[int(1e9)] * M for _ in range(N)]

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

que = deque()
que.append([start[0]-1, start[1]-1])
visited[start[0]-1][start[1]-1] = 0

# 벽을 부셨을 때, 벽을 부수지 않았을 때의 2개의 배열을 순회하여서 값을 찾자!
# 단, 모든 부분을 순회해야하므로 들린 곳은 무조건 que 넣어야 할듯?
# 이 점을 기억해서 코드를 작성하면 풀 수 있을 것 같다.
while que:
    x, y = que.popleft()
    for f in range(4):
        nx = x + direction[f][0]
        ny = y + direction[f][1]

        if 0 <= nx < N and 0 <= ny < M:
            if labyrinth[x][y] == 0:
                is_que = False
                if labyrinth[nx][ny] == 0 and visited[nx][ny] > visited[x][y] + 1:
                    visited[nx][ny] = visited[x][y] + 1
                    que.append([nx, ny])
                    is_que = True
                if visited_wall[x][y] != int(1e9) and visited_wall[nx][ny] > visited_wall[x][y] + 1 and labyrinth[nx][ny] == 0:
                    visited_wall[nx][ny] = visited_wall[x][y] + 1
                    if is_que is False:
                        que.append([nx, ny])

                elif labyrinth[nx][ny] == 1 and visited_wall[nx][ny] > visited[x][y] + 1:
                    visited_wall[nx][ny] = visited[x][y] + 1
                    que.append([nx, ny])

            if labyrinth[x][y] == 1 and visited_wall[x][y] != int(1e9):
                if labyrinth[nx][ny] == 0 and visited_wall[nx][ny] > visited_wall[x][y] + 1:
                    visited_wall[nx][ny] = visited_wall[x][y] + 1
                    que.append([nx, ny])


result = min(visited[end[0]-1][end[1]-1], visited_wall[end[0]-1][end[1]-1])

if result == int(1e9):
    print('-1')

else:
    print(result)
