'''
재서기는 수혀니와 숨바꼭질을 한다.
재서기가 농장에 있는 여러개의 헛간 중 한 곳에 숨는다.
수혀니는 1번 농장에서 부터 재서기를 찾는다.
재서기는 가장 먼곳에 숨어야 오랫동안 들키지 않고 숨을 수 있다.
최대한 멀리 있는 헛간을 찾아주자!
만약 최대길이인 헛간이 여러개라면 가장 낮은 값을 출력한다.
'''
'''
1번 농장에서 가장 먼곳을 찾아야한다!
근데... 길이 5만개 까지 나온다는데 흠... 걍 단순히 돌려도 되려나?
길이 5만개라 플루이드 워샬은 짤도 없을거 같고
최대로 먼곳이어야 해서 백트래킹도 안될거 같은데 일단 그래프 탐색 ㄱㄱ
'''
import heapq

# N = 헛간의 개수, M = 길의 개수
N, M = map(int, input().split())

graph = [[] for _ in range(N+1)]

for m in range(M):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

visited = [1e9] * (N+1)
visited[1] = 0
pq = []
heapq.heappush(pq, [0, 1])

while pq:
    moved, now = heapq.heappop(pq)

    new_move = moved + 1
    for g in graph[now]:
        if visited[g] > new_move:
            visited[g] = new_move
            heapq.heappush(pq, [new_move, g])

maximum = 0
maximum_contents = 0
maximum_room = 0

for v in range(1, N+1):
    if visited[v] > maximum:
        maximum = visited[v]
        maximum_contents = 1
        maximum_room = v
    elif visited[v] == maximum:
        maximum_contents += 1

print(f'{maximum_room} {maximum} {maximum_contents}')
