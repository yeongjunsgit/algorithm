'''
오르막 수란 점점 올라가는 숫자를 말한다!
수의 길이인 N이 주어졌을 때, 해당 길이의 수에서 발생하는
오르막 수의 개수를 구하여라!
'''
'''
음 약간 dp 느낌으로 가면 될 것 같다!
각 자리에서 발생할 수 있는 각 수마다의 개수를 구하는것!
'''
# N = 수의 길이
N = int(input())

dp = [[0] * 10 for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(10):
        if i == 1:
            dp[i][j] = 1

        else:
            for k in range(j+1):
                dp[i][j] += dp[i-1][k]


result = sum(dp[N]) % 10007

print(result)
