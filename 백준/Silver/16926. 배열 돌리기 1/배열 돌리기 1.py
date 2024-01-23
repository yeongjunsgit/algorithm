'''
배열이 주어진다.
해당 배열을 R번 만큼 회전 시킨다.
회전 방향은 반시계 방향으로 1칸씩 회전한다.
주어지는 배열을 돌린 후 나오는 배열을 출력하여라.
'''
'''
구.현
'''


def rotate(arr):
    tmp_arr = [[0] * M for _ in range(N)]
    shell_deep = min(M, N) // 2
    for d in range(shell_deep):
        start = d
        row_end = M - 1 - d
        column_end = N - 1 - d
        for i in range(start, column_end+1):
            for j in range(start, row_end+1):
                if i == start or j == start or j == row_end or i == column_end:
                    moved = 0
                    nx = i
                    ny = j
                    while moved != R:
                        if nx == start:
                            if ny != start:
                                nx += di[0]
                                ny += dj[0]
                                moved += 1
                            else:
                                nx += di[1]
                                ny += dj[1]
                                moved += 1

                        elif ny == start:
                            if nx != column_end:
                                nx += di[1]
                                ny += dj[1]
                                moved += 1
                            else:
                                nx += di[2]
                                ny += dj[2]
                                moved += 1

                        elif nx == column_end:
                            if ny != row_end:
                                nx += di[2]
                                ny += dj[2]
                                moved += 1
                            else:
                                nx += di[3]
                                ny += dj[3]
                                moved += 1

                        elif ny == row_end:
                            if nx != start:
                                nx += di[3]
                                ny += dj[3]
                                moved += 1
                            else:
                                nx += di[0]
                                ny += dj[0]
                                moved += 1

                    tmp_arr[nx][ny] = arr[i][j]

    return tmp_arr


di = [0, 1, 0, -1]
dj = [-1, 0, 1, 0]

# N = 세로길이, M = 가로길이, R = 회전 수
N, M, R = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

result = rotate(arr)

for r in range(N):
    print(*result[r])
