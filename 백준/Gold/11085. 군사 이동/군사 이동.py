'''
오오 백준왕국
오오 가장 많은 병사를 보낼수 있는 경로를 찾아 해당 경로에서 가장 적은 너비를 구하라 오오
'''
'''
다익스트라를 이용하는게 어떨까?
'''
import heapq

# N = 정점의 개수, M = 간선의 개수
N, M = map(int, input().split())

kingdom, empire = map(int, input().split())

graph = [[] for _ in range(N)]

for m in range(M):
    a, b, d = map(int, input().split())

    graph[a].append([b, d])
    graph[b].append([a, d])

pq = []

heapq.heappush(pq, [-int(1e9), kingdom])

result = 0
visited = [int(1e9)] * N
visited[kingdom] = -int(1e9)
while result == 0:
    soilders, now = heapq.heappop(pq)

    if now == empire:
        if result < -soilders:
            result = soilders
            continue

    for i in graph[now]:
        new_soilders, next_node = -i[1], i[0]
        if new_soilders < soilders:
            new_soilders = soilders
        if visited[next_node] > new_soilders:
            heapq.heappush(pq, [new_soilders, next_node])
            visited[next_node] = new_soilders

print(-result)
