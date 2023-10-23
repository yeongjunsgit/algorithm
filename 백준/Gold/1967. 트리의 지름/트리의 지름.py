import sys
input = sys.stdin.readline
from collections import deque

def bfs(si):
    global result
    que = deque()
    que.append([0, si])
    visited = [0] * (N+1)
    visited[si] = 1
    tmp_result = 0

    while que:
        move, now = que.popleft()
        if move > tmp_result:
            tmp_result = move

        if graph[now]:
            for i in range(len(graph[now])):
                if visited[graph[now][i][0]] == 0:
                    next_move = move + graph[now][i][1]
                    next_node = graph[now][i][0]
                    que.append([next_move, next_node])
                    visited[graph[now][i][0]] = 1

    if result < tmp_result:
        result = tmp_result

N = int(input())
graph = [[] for _ in range(N+1)]
all_set = set()
root_set = set()
result = 0

for n in range(N-1):
    root, child, dist = map(int, input().split())
    root_set.add(root)
    all_set.add(root)
    all_set.add(child)
    graph[root].append([child, dist])
    graph[child].append([root, dist])


leaf_set = all_set - root_set

leaf_lis = list(leaf_set)

for l in leaf_lis:
    bfs(l)

print(result)