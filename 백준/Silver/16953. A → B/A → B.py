import sys
sys.setrecursionlimit(10**5)

from collections import deque

def bfs(S, F, cnt):
    global result
    que = deque()
    que.append([S, cnt])

    while que:
        i, move = que.popleft()
        if i == F:
            result = move+1

        elif i < F:
            i2 = i * 2
            que.append([i2, move+1])
            ip1 = i * 10 + 1
            que.append([ip1, move+1])


S, F = map(int, input().split())

result = -1


bfs(S, F, 0)

print(result)