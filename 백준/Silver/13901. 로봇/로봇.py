'''
방의 크기, 장애물의 개수, 장애물의 위치, 로봇의 시작 위치, 이동방향의 순서가 주어진다
이동방향은 1이 위, 2는 아래, 3은 왼쪽, 4는 오른쪽
'''
'''
구현
'''

N, M = map(int, input().split())

room = [[0] * M for _ in range(N)]
visited = [[0] * M for _ in range(N)]

K = int(input())

for k in range(K):
    wx, wy = map(int, input().split())
    room[wx][wy] = 1

sx, sy = map(int, input().split())

move_dict = {1: (-1, 0), 2: (1, 0), 3: (0, -1), 4: (0, 1)}
move_command = list(map(int, input().split()))
move_idx = 0

cant_moved = 0
while True:
    visited[sx][sy] = 1

    nx = sx + move_dict[move_command[move_idx]][0]
    ny = sy + move_dict[move_command[move_idx]][1]

    if 0 <= nx < N and 0 <= ny < M:
        if visited[nx][ny] == 0:
            if room[nx][ny] == 0:
                sx, sy = nx, ny
                cant_moved = 0

            else:
                move_idx += 1
                move_idx %= 4
                cant_moved += 1

        else:
            move_idx += 1
            move_idx %= 4
            cant_moved += 1

    else:
        move_idx += 1
        move_idx %= 4
        cant_moved += 1

    if cant_moved == 4:
        break

print(f'{sx} {sy}')
