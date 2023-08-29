import sys
input = sys.stdin.readline

def dfs(s):
    stack = []
    visited = [[0] * N for _ in range(N)]
    k = s
    while True:
        for c in range(N):
            if arr[k][c] == 1 and visited[k][c] == 0:
                connect_arr[s][c] = 1
                visited[k][c] = 1
                stack.append(k)
                k = c
                break
        else:
            if stack:
                k = stack.pop()
            else:
                break

    return

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]
connect_arr = [[0] * N for _ in range(N)]

for i in range(N):
    dfs(i)

for j in range(N):
    for p in range(N):
        print(connect_arr[j][p], end=' ')
    print()