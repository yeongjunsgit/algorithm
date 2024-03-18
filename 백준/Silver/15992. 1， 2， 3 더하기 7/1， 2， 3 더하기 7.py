'''
각 숫자에 인덱스 값으로 몇가지 수를 이용해서 해당 수를 만들었는지를 기록하여 저장한 후 호출하자
'''

dp = [[0] * (d+1) for d in range(1001)]

dp[1][1] = 1
dp[2][1] = 1
dp[2][2] = 1
dp[3][1] = 1
dp[3][2] = 2
dp[3][3] = 1

for i in range(4, 1001):
    for j in range(1, i + 1):
        if j == 1:
            dp[i][j] = 0

        elif i == j:
            dp[i][j] = 1

        else:
            tmp = 0
            for k in range(1, 4):
                if i - k >= j - 1:
                    tmp += dp[i - k][j - 1]

            dp[i][j] = tmp % 1000000009

T = int(input())

for tc in range(1, T+1):
    N, M = map(int, input().split())
    print(dp[N][M])
