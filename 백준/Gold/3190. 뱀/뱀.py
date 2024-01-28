'''
뱀게임을 아는가? 뱀 게임은 NxN 정사각 보드위에 놓여있는 사과를 먹는 뱀게임이다.
뱀은 매초마다 이동을 하는데 다음과 같은 규칙을 따른다.
뱀은 무조건 0, 0에 있다!
1. 뱀은 머리를 다음칸까지 늘린다.
2. 만약 늘린 위치가 벽이거나, 내몸이 위치한 곳이라면 게임이 끝난다.
3. 만약 이동한 위치가 사과가 있다면 머리가 늘어난 채로 유지한다.
4. 만약 위치에 사과가 없다면 꼬리를 줄인다. (즉, 늘어나지 않는다.)
과연 주어지는 상황을 받았을때 게임이 몇초후에 끝날까?
'''
'''
구 현!
'''
from collections import deque

# N = 보드의 크기
N = int(input())
# K = 사과의 개수
K = int(input())

board = [[0] * N for _ in range(N)]
board[0][0] = 1
snake = deque()
snake.appendleft([0, 0])

cnt = 0
move_direction = (0, 1)
is_over = False

left_change = {
    (0, 1): (-1, 0),
    (-1, 0): (0, -1),
    (1, 0): (0, 1),
    (0, -1): (1, 0)
}

right_change = {
    (0, 1): (1, 0),
    (1, 0): (0, -1),
    (0, -1): (-1, 0),
    (-1, 0): (0, 1)
}


for k in range(K):
    ax, ay = map(int, input().split())
    board[ax-1][ay-1] = 2

# T = 뱀의 방향 변환 횟수
# L = 왼쪽으로 90도, D = 오른쪽으로 90 도 회전
T = int(input())

for t in range(T):
    if is_over is True:
        break
    second, command = input().split()
    for s in range(int(second) - cnt):
        nx = snake[0][0] + move_direction[0]
        ny = snake[0][1] + move_direction[1]
        cnt += 1
        if 0 <= nx < N and 0 <= ny < N:
            if board[nx][ny] == 2:
                board[nx][ny] = 1
                snake.appendleft([nx, ny])

            elif board[nx][ny] == 0:
                board[nx][ny] = 1
                board[snake[-1][0]][snake[-1][1]] = 0
                snake.appendleft([nx, ny])
                snake.pop()

            elif board[nx][ny] == 1:
                is_over = True
                break

        else:
            is_over = True
            break

    if command == 'L':
        move_direction = left_change[move_direction]

    elif command == 'D':
        move_direction = right_change[move_direction]

if is_over is False:
    while True:
        nx = snake[0][0] + move_direction[0]
        ny = snake[0][1] + move_direction[1]
        cnt += 1
        if 0 <= nx < N and 0 <= ny < N:
            if board[nx][ny] == 2:
                board[nx][ny] = 1
                snake.appendleft([nx, ny])

            elif board[nx][ny] == 0:
                board[nx][ny] = 1
                board[snake[-1][0]][snake[-1][1]] = 0
                snake.appendleft([nx, ny])
                snake.pop()

            elif board[nx][ny] == 1:
                is_over = True
                break

        else:
            is_over = True
            break

print(cnt)
