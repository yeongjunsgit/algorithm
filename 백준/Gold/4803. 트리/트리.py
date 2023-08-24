# 자신의 부모노드를 표기, visited를 고려하지 않고, 부모 노드를 빼고 도는 방식을 사용

def bfs(r, N, p, arr):
    global result
    que = [0] * (N+1)
    que_p = [0] * (N+1)
    rear = -1
    front = -1
    visited[r] = 1
    p = 0
    rear += 1
    que[rear] = r
    que_p[rear] = p
    ok = False

    while rear != front:
        front += 1
        x = que[front]
        p = que_p[front]
        for i in range(len(arr[x])):
            if arr[x][i] != p:
                if arr[x][i] in que:
                    return 0
                else:
                    rear += 1
                    que[rear] = arr[x][i]
                    que_p[rear] = x
                    visited[arr[x][i]] = 1

    if rear == front:
        for j in que:
            arr[j] = []
        ok = True

    if ok is True:
        result += 1

case = 0
while True:
    case += 1
    N, M = map(int, input().split())
    result = 0
    visited = [0] * (N + 1)
    if N == 0 and M == 0:
        break
    else:
        edge = [[] * (N+1) for _ in range(N+1)]
        for m in range(M):
            a, b = map(int, input().split())
            edge[a].append(b)
            edge[b].append(a)

    for j in range(1, N+1):
        if visited[j] == 0:
            if edge[j] == []:
                result += 1
            else:
                bfs(j, N, 0, edge)

    if result == 0:
        print(f'Case {case}: No trees.')

    elif result == 1:
        print(f'Case {case}: There is one tree.')

    else:
        print(f'Case {case}: A forest of {result} trees.')