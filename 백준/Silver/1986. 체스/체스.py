'''
체스판의 크기가 주어진다
그리고 연속해서 퀸, 나이트, 폰의 위치가 주어진다.
폰은 상대방을 잡을 수 없다 (장애물 역할)
퀸은 장애물이 있으면 해당 구간을 지날 수 없다
나이트는 장애물이 있어도 갈 수 있다.
이렇다 할때 체스판에 안전한 위치가 몇개일지 구하라
'''
'''
단순 구현 같다.
'''
from collections import deque

queen_direction = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]
knight_direction = [(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)]

# N = 세로길이, M = 가로길이
N, M = map(int, input().split())

cnt = N * M
board = [[0] * M for _ in range(N)]

queen_lis = list(map(int, input().split()))
knight_lis = list(map(int, input().split()))
pawn_lis = list(map(int, input().split()))

que = deque()

if queen_lis != [0]:
    for q in range(1, queen_lis[0]*2+1, 2):
        que.append([queen_lis[q]-1, queen_lis[q+1]-1, 'Q'])
        board[queen_lis[q]-1][queen_lis[q+1]-1] = 1
        cnt -= 1

if knight_lis != [0]:
    for k in range(1, knight_lis[0]*2+1, 2):
        que.append([knight_lis[k]-1, knight_lis[k+1]-1, 'K'])
        board[knight_lis[k]-1][knight_lis[k+1]-1] = 1
        cnt -= 1

if pawn_lis != [0]:
    for p in range(1, pawn_lis[0]*2+1, 2):
        board[pawn_lis[p]-1][pawn_lis[p+1]-1] = 1
        cnt -= 1

while que:
    x, y, kind = que.popleft()

    if kind == 'Q':
        for e in range(8):
            di, dj = queen_direction[e]
            power = 1
            while True:
                nx = x + (di * power)
                ny = y + (dj * power)

                if 0 <= nx < N and 0 <= ny < M and board[nx][ny] != 1:
                    if board[nx][ny] == 0:
                        cnt -= 1
                    board[nx][ny] = 2
                    power += 1

                else:
                    break

    elif kind == 'K':
        for e in range(8):
            di, dj = knight_direction[e]
            nx = x + di
            ny = y + dj

            if 0 <= nx < N and 0 <= ny < M and board[nx][ny] != 1:
                if board[nx][ny] == 0:
                    cnt -= 1
                board[nx][ny] = 2

print(cnt)
