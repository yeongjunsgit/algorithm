'''
크기가 NxM인 배열이 있을 때, 배열에 연산을 R번 적용하려고 한다. 연산은 총 6가지가 있다.
1번 연산은 배열의 상하반전시키는 연산이다.
2번 연산은 배열을 좌우 반전시키는 연산이다.
3번 연산은 오른쪽으로 90도 회전시키는 연산이다.
4번 연산은 왼쪽으로 90도 회전시키는 연산이다.
5,6번 연산은 수행하려면 배열을 크기가 N/2 x M/2인 4개의 부분 배열로 나누어야 한다.
4개의 구간으로 나눈 배열을 이용하여
5번 연산은 1 -> 2, 2->3, 3->4, 4->1로 이동한다.
6번 연산은 1 -> 4, 4->3, 3->2, 2->1로 이동한다.

이때 배열과 연산의 개수가 주어질때, 모든 연산을 완료한 후 나타나는 배열을 출력하라.
'''
'''
단순 구현이지만 얼마나 시간을 안먹이고 할 수 있을까 하 일단 해보자
'''
def function_1():
    new_arr = [[] for _ in range(N)]
    idx = 0

    for n in range(N-1, -1, -1):
        new_arr[idx] = arr[n]
        idx += 1

    return new_arr


def function_2():
    new_arr = [[] for _ in range(N)]
    idx = 0

    for n in range(N):
        arr[n].reverse()
        new_arr[idx] = arr[n]
        idx += 1

    return new_arr


def function_3():
    new_arr = [[0] * N for _ in range(M)]
    for i in range(N):
        for j in range(M):
            new_arr[j][N-1-i] = arr[i][j]

    return new_arr


def function_4():
    new_arr = [[0] * N for _ in range(M)]
    for i in range(N):
        for j in range(M):
            new_arr[M-1-j][i] = arr[i][j]

    return new_arr


def function_5():
    new_arr = [[0] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if 0 <= i < N // 2 and 0 <= j < M // 2:
                new_arr[i][j+(M//2)] = arr[i][j]

            elif 0 <= i < N // 2 and M // 2 <= j < M:
                new_arr[i+(N//2)][j] = arr[i][j]

            elif N // 2 <= i < N and M // 2 <= j < M:
                new_arr[i][j-(M//2)] = arr[i][j]

            elif N // 2 <= i < N and 0 <= j < M // 2:
                new_arr[i-(N//2)][j] = arr[i][j]

    return new_arr


def function_6():
    new_arr = [[0] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):
            if 0 <= i < N // 2 and 0 <= j < M // 2:
                new_arr[i+(N//2)][j] = arr[i][j]

            elif N // 2 <= i < N and 0 <= j < M // 2:
                new_arr[i][j+(M//2)] = arr[i][j]

            elif N // 2 <= i < N and M // 2 <= j < M:
                new_arr[i-(N//2)][j] = arr[i][j]

            elif 0 <= i < N // 2 and M // 2 <= j < M:
                new_arr[i][j-(M//2)] = arr[i][j]

    return new_arr


# N = 세로 길이, M = 가로 길이, R = 연산의 수
N, M, R = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]

command_lis = list(map(int, input().split()))

for r in range(R):
    command = command_lis[r]

    if command == 1:
        arr = function_1()
    elif command == 2:
        arr = function_2()
    elif command == 3:
        arr = function_3()
        N, M = M, N
    elif command == 4:
        arr = function_4()
        N, M = M, N
    elif command == 5:
        arr = function_5()
    elif command == 6:
        arr = function_6()

for r in range(len(arr)):
    print(*arr[r])
