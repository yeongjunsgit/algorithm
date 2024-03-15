'''
현재 위치에서 자신보다 작은 값중 가장 많은 값이 쌓인 값을 저장하자!
아? 음... 숫자로 보면 안되겠네 카드 개수가 천개니까 카드로 조회하자!
'''
# N = 카드의 개수
N = int(input())

cards = list(map(int, input().split()))

dp = [0] * N

dp[0] = 1

for i in range(1, N):
    last_best = 0
    for j in range(i):
        if dp[j] > last_best and cards[j] < cards[i]:
            last_best = dp[j]

    dp[i] = last_best + 1

print(max(dp))
