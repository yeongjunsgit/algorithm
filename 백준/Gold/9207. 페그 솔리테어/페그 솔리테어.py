'''
페그 솔리테어를 구현하자!
페그 솔리테어는 구멍이 뚫려있는 이차원 게임판에서 하는 게임이다.
각 빈칸에는 핀을 꽂을 수 있다.
핀은 수평, 수직 방향으로 인접한 핀을 뛰어넘어서 그 핀의 다음 칸으로 이동하는 것만 허용된다.
인접한 다음 칸은 비어있어야 하고, 그 인접한 핀은 제거된다.
위 규칙에 따라 진행할때, 주어지는 상황에서 발생할 수 있는 최소 핀 개수와,
해당 최소 핀을 만들때 움직이는 이동 횟수 중 최소 값을 구하여라!
'''
'''
브루트 포스 각
'''
import heapq
import copy


def move_pin(arr, moved):
    global pq
    for i in range(5):
        for j in range(9):
            if arr[i][j] == 'o':
                for f in range(4):
                    nx = i + di[f]
                    ny = j + dj[f]
                    if 0 <= nx < 5 and 0 <= ny < 9:
                        if arr[nx][ny] == 'o':
                            tnx = nx + di[f]
                            tny = ny + dj[f]
                            if 0 <= tnx < 5 and 0 <= tny < 9:
                                if arr[tnx][tny] == '.':
                                    tmp_arr = copy.deepcopy(arr)
                                    tmp_arr[i][j] = '.'
                                    tmp_arr[nx][ny] = '.'
                                    tmp_arr[tnx][tny] = 'o'
                                    heapq.heappush(pq, [moved+1, tmp_arr])


def judge(arr):
    cnt = 0
    for p in range(5):
        for q in range(9):
            if arr[p][q] == 'o':
                cnt += 1

    return cnt

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

T = int(input())

for tc in range(1, T+1):
    board = [list(input()) for _ in range(5)]
    pq = []

    heapq.heappush(pq, [0, board])

    pins = 8
    min_moved = 0

    while pq:
        moving, now_board = heapq.heappop(pq)

        pin = judge(now_board)
        if pin < pins:
            pins = pin
            min_moved = moving

        elif pin == pins:
            if min_moved > moving:
                min_moved = moving

        move_pin(now_board, moving)

    print(f'{pins} {min_moved}')

    if tc != T:
        space = input()
