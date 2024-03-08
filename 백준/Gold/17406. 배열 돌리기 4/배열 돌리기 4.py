'''
배열을 돌리자
돌려야할 배열과 돌릴 구간이 주어진다.
단, 배열을 돌릴 구간을 주어진 순서대로 돌릴필요는 없다.
이렇게 했을때 모든 회전 작업을 수행한 배열에서 한 열의 모든 합이 가장 낮은 값을 해당 배열의 값이라 한다.
회전시 발생할 수 있는 최소 값을 구하여라.
'''
'''
순서가 정해져있지 않아 최악의 경우가 720개의 경우의 수가 발생한다
50*50의 배열을 720번의 복사를 통해 배열을 다룬다면 시간초과 or 메모리 초과가 발생할 수도 있을 듯
조심해서 접근하자
'''
import copy

def perm(s, e):
    global result
    if s == e:
        tmp = chain_rotate(pq)
        if result > tmp:
            result = tmp

        return

    else:
        for p in range(K):
            if used[p] == 0:
                used[p] = 1
                pq.append(commands[p])
                perm(s+1, e)
                used[p] = 0
                pq.pop()


def chain_rotate(orders):
    tmp_arr = copy.deepcopy(arr)

    for q in range(K):
        # empty_arr = [[0] * M for _ in range(N)]
        tx, ty, weight = orders[q]
        start = [tx-weight-1, ty-weight-1]
        end = [tx+weight-1, ty+weight-1]
        rotate(start, end, tmp_arr)

    min_power = int(1e9)
    for n in range(N):
        tmp_power = sum(tmp_arr[n])
        if tmp_power < min_power:
            min_power = tmp_power

    return min_power


def rotate(start, end, base):
    changer = []
    shell_deep = min(end[0] - start[0], end[1] - start[1]) // 2
    for d in range(shell_deep):
        start_point = start
        row_end = end[1] - d
        column_end = end[0] - d
        for i in range(start_point[0] + d, column_end+1):
            for j in range(start_point[1] + d, row_end+1):
                if i == start_point[0] + d or j == start_point[1] + d or j == row_end or i == column_end:
                    nx = i
                    ny = j
                    if nx == start_point[0] + d:
                        if ny != row_end:
                            nx += di[0]
                            ny += dj[0]

                        else:
                            nx += di[1]
                            ny += dj[1]

                    elif ny == row_end:
                        if nx != column_end:
                            nx += di[1]
                            ny += dj[1]
                        else:
                            nx += di[2]
                            ny += dj[2]

                    elif nx == column_end:
                        if ny != start_point[1] + d:
                            nx += di[2]
                            ny += dj[2]
                        else:
                            nx += di[3]
                            ny += dj[3]

                    elif ny == start_point[1] + d:
                        if nx != start_point[0] + d:
                            nx += di[3]
                            ny += dj[3]
                        else:
                            nx += di[0]
                            ny += dj[0]

                    changer.append([nx, ny, base[i][j]])

    for c in changer:
        x, y, pre = c
        base[x][y] = pre

    return base


di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

# N = 세로 길이, M = 가로 길이, K = 회전 횟수
N, M, K = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

commands = []

for k in range(K):
    command = list(map(int, input().split()))
    commands.append(command)

pq = []
used = [0] * K
result = int(1e9)

perm(0, K)

print(result)
