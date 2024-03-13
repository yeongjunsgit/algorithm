'''
다익스트라
'''
import heapq

N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]

for m in range(M):
    s, e, dis = map(int, input().split())
    graph[s].append([e, dis])
    graph[e].append([s, dis])


start, end = map(int, input().split())

visited = [int(1e9)] * (N+1)

pq = []

heapq.heappush(pq, [0, start])
visited[start] = 0

while pq:
    moved, now = heapq.heappop(pq)
    if moved > visited[end]:
        continue

    for i in range(len(graph[now])):
        next_node, distance = graph[now][i]
        new_dis = moved + distance
        if visited[next_node] > new_dis:
            visited[next_node] = new_dis
            heapq.heappush(pq, [new_dis, next_node])

print(visited[end])
