'''
게임을 한다.
가운데에 공유카드를 두고 각자 N개의 카드를 받는다 그리고 상대 팀의 카드를 K개 봉인한다.
마찬가지로 상대도 우리팀의 카드를 봉인한다. 상대팀이 우리팀의 카드를 최고의 방법으로 봉인한다고할때,
내가 가질 수 있는 가장 큰 점수를 구하여라
'''
'''
간단하게 생각하면 가장 큰 값끼리 곱하면 되지만 해당 문제는 음수값도 주고있다.
그냥 모든 경우의 수를 구한다음 K개의 높은 점수를 빼고 난 후의 점수를 출력하면 되지 않을까?
아.. 팀 카드 자체를 밴하는 거니까 점수를 몇개뺀다고 되는게 아니네 흠
가장 높은 점수를 가지는 카드를 벤하자?
10000번의 연산을 99 번까지 하자 흠 뭐 완탐도 되겠네
'''
import heapq

# N = 공유카드와, 팀카드의 개수, K = 팀카드의 벤 개수
N, K = map(int, input().split())

share_cards = list(map(int, input().split()))
team_cards = list(map(int, input().split()))

banned = []
for k in range(K):
    pq = []
    for s in range(N):
        for t in range(len(team_cards)):
            heapq.heappush(pq, [-(share_cards[s] * team_cards[t]), team_cards[t]])

    best = heapq.heappop(pq)
    team_cards.remove(best[1])

result = -(int(1e9))
for i in range(N):
    for j in range(len(team_cards)):
        tmp = share_cards[i] * team_cards[j]
        if result < tmp:
            result = tmp

print(result)
