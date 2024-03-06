'''
뿌요뿌요를 구현하자
상대방의 뿌요뿌요 판이 주어진다.
같은색깔이 4개이상 연결되어 있으면 해당 뿌요들은 사라지고 위에 있던 뿌요들은 중력을 받아 아래로 내려간다.
이 현상은 동시 다발적으로 일어 날 수 있으며 한 턴에 일어난 현상을 1체인으로 친다.
중력으로 인해 뿌요들이 떨어졌을 때, 새롭게 뿌요들이 4개이상 연결 되어 뿌요들이 사라질 수 있다.
이럴때 체인이 2개가 된다. 이렇게 해서 연속되는 체인의 개수가 몇개일지 구하여라
'''
'''
구현하자!
중력을 받아 떨어지는 것을 잘 구현해야 하는게 포인트일듯?
'''
from collections import deque


def popping_puyo(base, x, y):
    que = deque()
    que.append([x, y])
    visited[x][y] = 1
    connected = 1
    passed_connect = [(x, y)]

    while que:
        tx, ty = que.popleft()
        for f in range(4):
            nx = tx + direction[f][0]
            ny = ty + direction[f][1]

            if 0 <= nx < 12 and 0 <= ny < 6:
                if visited[nx][ny] == 0 and puyo_puyo[nx][ny] == base:
                    que.append([nx, ny])
                    visited[nx][ny] = 1
                    connected += 1
                    passed_connect.append((nx, ny))

    if connected >= 4:
        for p in range(len(passed_connect)):
            px, py = passed_connect[p]
            puyo_puyo[px][py] = '.'
        return 1

    else:
        return 0


def gravity():
    for v in range(11, -1, -1):
        for w in range(6):
            if puyo_puyo[v][w] != '.':
                dx = v+1
                if 0 <= dx < 12:
                    if puyo_puyo[dx][w] == '.':
                        while True:
                            if 0 <= dx < 12:
                                if puyo_puyo[dx][w] == '.':
                                    puyo_puyo[dx][w], puyo_puyo[dx-1][w] = puyo_puyo[dx-1][w], puyo_puyo[dx][w]
                                    dx += 1

                                else:
                                    break

                            else:
                                break


puyo_puyo = [list(input()) for _ in range(12)]

chain = 0

direction = [(0, 1), (1, 0), (0, -1), (-1, 0)]

while True:
    visited = [[0] * 6 for _ in range(12)]
    chained = False
    for i in range(12):
        for j in range(6):
            if puyo_puyo[i][j] != '.' and visited[i][j] == 0:
                this_turn = popping_puyo(puyo_puyo[i][j], i, j)
                if this_turn == 1:
                    chained = True

    if chained is True:
        chain += 1
        gravity()

    elif chained is False:
        break

print(chain)
