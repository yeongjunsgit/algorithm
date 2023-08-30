import sys
input = sys.stdin.readline
print = sys.stdout.write
from collections import deque

def bfs(X):
    global cnt
    global result
    neo = X
    que = deque()
    route = [-1] * (X+1)
    que.append(X)
    visited = [0] * (X+1)
    visited[X] = 0
    while X != 1:
        X = que.popleft()
        if X % 3 == 0:
            if visited[X//3] == 0:
                visited[X//3] = visited[X] + 1
                route[X//3] = X
                que.append(X//3)
                if X // 3 == 1:
                    break

        if X % 2 == 0:
            if visited[X//2] == 0:
                visited[X//2] = visited[X] + 1
                route[X//2] = X
                que.append(X//2)
                if X // 2 == 1:
                    break

        if visited[X-1] == 0:
            que.append(X-1)
            route[X-1] = X
            visited[X-1] = visited[X] + 1
            if X - 1 == 1:
                break

    cnt = visited[1]
    tmp = 0
    start = 1
    result.appendleft(start)
    while tmp != neo:
        tmp = route[start]
        result.appendleft(tmp)
        start = tmp


X = int(input())
cnt = 0
result = deque()

if X != 1:
    bfs(X)
else:
    cnt = 0
    result.append(1)

print(str(cnt) + '\n')
for i in result:
    print(str(i) + ' ')