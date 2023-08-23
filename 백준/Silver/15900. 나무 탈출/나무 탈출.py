import sys
input = sys.stdin.readline

def dfs(r, N, arr):
    stack = []
    front = -1
    rear = -1
    stack.append(r)
    rear += 1

    visited = [-1] * (N+1)
    visited[r] = 0
    all_cnt = 0

    while rear != front:
        cnt = 0
        front += 1
        r = stack[front]
        for n in range(len(arr[r])):
            if arr[r][n] and visited[arr[r][n]] == -1:
                stack.append(arr[r][n])
                visited[arr[r][n]] = visited[r] + 1
                rear += 1

            else:
                cnt += 1

        else:
            if r != 1 and len(arr[r]) == 1:
                all_cnt += visited[r]

    return all_cnt


N = int(input())
edge = [[] * (N+1) for _ in range(N+1)]

for i in range(N-1):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

result = dfs(1, N, edge)

if result % 2 == 1:
    print('Yes')
else:
    print('No')
