'''
앞뒤로 감싸는 경우는 1?1 2?2 3?3 뿐이다
저장되있는건 펠린드롬인 애들만이니까
해당 값으로 추가할 수 있는 경우들을 세어주자!
6일때,
141 -> 111111, 1221, 11211
222 -> 222, 2112
33 -> 33
'''

T = int(input())

dp = [0] * 100001
dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 2

for tc in range(1, T+1):
    N = int(input())

    if dp[N] != 0:
        print(dp[N])

    else:
        for i in range(4, N+1):
            base = 0
            if i - 2 >= 0:
                base += dp[i-2]

            if i - 4 >= 0:
                base += dp[i-4]

            if i - 6 >= 0:
                base += dp[i-6]

            dp[i] = base % 1000000009

        else:
            print(dp[N])
