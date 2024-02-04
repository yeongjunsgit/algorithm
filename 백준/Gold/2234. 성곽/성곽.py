'''
주어지는 성곽이 있다. 해당 성곽에는 벽이 있고 해당 벽으로 방이 나누어져있다.
우리는 이 성에서 3가지의 경우를 구해야한다!
1. 이 성에 있는 방의 개수
2. 가장 넓은 방의 넓이
3. 하나의 벽을 제거했을때, 가장 넓은 방의 크기
세가지를 구해야하며, 입력이 특이하게 주어진다.
서쪽에 벽이 있을때는 1을 더하고, 북쪽에 벽이 있을때는 2를 더하고, 동쪽에 벽이 있을때는 4를,
남쪽에 벽이 있을때는 8을 더한 값이 주어진다. 각 칸에서 주어진 값을 보고 벽의 위치를 판단해 3가지 값을 구하자!
'''
'''
BFS같긴 하지만 진짜 입력 그지같다!
'''
from collections import deque

# N = 가로 길이, M = 세로 길이
N, M = map(int, input().split())

castle = [list(map(int, input().split())) for _ in range(M)]
visited = [[0] * N for _ in range(M)]

rooms = 0
width_room = 0
break_width = 0
directions = [8, 4, 2, 1]
directions_dict = {8: (1, 0), 4: (0, 1), 2: (-1, 0), 1: (0, -1)}
room_number = 1
size_dict = {}

for i in range(M):
    for j in range(N):
        if visited[i][j] == 0:
            que = deque()
            que.append([i, j, castle[i][j]])
            visited[i][j] = room_number
            room_number += 1
            size = 1

            while que:
                x, y, point = que.popleft()
                dij = []
                for d in directions:
                    if point >= d:
                        point -= d
                        dij.append(d)

                for k in [1, 2, 4, 8]:
                    if k not in dij:
                        di, dj = directions_dict[k]
                        nx = x + di
                        ny = y + dj

                        if 0 <= nx < M and 0 <= ny < N and visited[nx][ny] == 0:
                            que.append([nx, ny, castle[nx][ny]])
                            visited[nx][ny] = visited[i][j]
                            size += 1

            if size > width_room:
                width_room = size

            rooms += 1

            size_dict[visited[i][j]] = size

used = [0] * (rooms+1)
used[0] = 1
four_way = [(0, 1), (1, 0), (0, -1), (-1, 0)]
for p in range(M):
    for q in range(N):
        if used[visited[p][q]] == 0:
            used[visited[p][q]] = 1
            d_que = deque()
            d_que.append([p, q])
            connected = set()
            in_rooms = visited[p][q]
            visited[p][q] = 0

            while d_que:
                tx, ty = d_que.popleft()

                for f in range(4):
                    ndi, ndj = four_way[f]
                    tnx = tx + ndi
                    tny = ty + ndj

                    if 0 <= tnx < M and 0 <= tny < N:
                        if visited[tnx][tny] == in_rooms:
                            d_que.append([tnx, tny])
                            visited[tnx][tny] = 0

                        else:
                            if visited[tnx][tny] not in connected and visited[tnx][tny] != 0:
                                connected.add(visited[tnx][tny])
                                tmp_rooms = size_dict[in_rooms] + size_dict[visited[tnx][tny]]
                                if break_width < tmp_rooms:
                                    break_width = tmp_rooms

print(rooms)
print(width_room)
print(break_width)
