import heapq

N, M = map(int, input().split())    # N은 카드의 개수, M은 연산 횟수

pq = []
cards = list(map(int, input().split()))

for i in cards:
    heapq.heappush(pq, i)

for m in range(M):
    tmp_1 = heapq.heappop(pq)
    tmp_2 = heapq.heappop(pq)

    tmp = tmp_1 + tmp_2

    heapq.heappush(pq, tmp)
    heapq.heappush(pq, tmp)


print(sum(pq))