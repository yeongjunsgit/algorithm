'''
0과 1로만 이루어진 행렬 A와 B가 있다.
어느 한 부분을 선택하면 해당 부분을 포함한 8방향의 숫자들이 다른 숫자로 바뀐다.
이 행동을 해서 A 행렬을 B 행렬로 바꿀 때 걸리는 최소 횟수를 구하시오.
'''
'''
브루트 포스를 하되, 이미 탐색한 적이 있던 행렬의 모양은 또 다시 판단하지 않는다!
'''


def reverse_num(x, y):
    for e in range(9):
        nx = x + directions[e][0]
        ny = y + directions[e][1]

        arr_A[nx][ny] = (arr_A[nx][ny] + 1) % 2


# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())

arr_A = [list(map(int, input())) for _ in range(N)]
arr_B = [list(map(int, input())) for _ in range(N)]

directions = [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]

result = -1
is_over = False
cnt = 0

for i in range(N):
    for j in range(M):
        if arr_A[i][j] != arr_B[i][j]:
            if 0 <= i + 2 < N and 0 <= j+2 < M:
                reverse_num(i, j)
                cnt += 1

if arr_A == arr_B:
    result = cnt

print(result)
