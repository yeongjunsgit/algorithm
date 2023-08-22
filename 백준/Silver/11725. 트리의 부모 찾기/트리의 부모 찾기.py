# 1. 트리의 root는 1이다.
# 2. 트리의 연결관계는 주어지나, 무엇이 부모인지 알려주지 않는다.
# 3. 트리를 다 연결하고, 1부터 출발한다. 그 후 각 노드의 루트를 찾는다.
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N = int(input())

match_lis = [[] for _ in range(N+1)]
visited = [0] * (N+1)
p_c_lis = [0] * (N+1)


for _ in range(N-1):
    p, c = map(int, input().split())
    match_lis[p].append(c)
    match_lis[c].append(p)


def bfs(n):
    if visited[n] == 0:
        visited[n] = 1
        for i in range(len(match_lis[n])):
            l = match_lis[n][i]
            if visited[l] == 0:
                p_c_lis[l] = n
                bfs(l)


bfs(1)

for j in range(2, N+1):
    print(p_c_lis[j])