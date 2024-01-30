'''
상근이는 결혼식에 친구들을 초대하려고한다
그런데 친구의 친구까지 초대할 것이다
친구 관계도가 주어질 때 결혼식에 초대할 사람이 몇명인지 구하여라!
'''
'''
간단하게 bfs?
'''
from collections import deque

# N = 사람의 수
N = int(input())

cnt = 0

graph = [[] for _ in range(N+1)]

M = int(input())

for m in range(M):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

que = deque()
visited = [0] * (N+1)
visited[1] = 1

for i in graph[1]:
    que.append(i)
    visited[i] = 1
    cnt += 1

while que:
    now = que.popleft()
    for j in graph[now]:
        if visited[j] != 1:
            cnt += 1
            visited[j] = 1

print(cnt)
