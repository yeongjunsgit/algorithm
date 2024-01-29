'''
어떤 자연수 N이 주어진다.
이 자연수를 어떤 자연수들의 제곱값의 합으로 표현할 수 있다.
이때, 해당 자연수를 만들때 필요한 제곱수 항의 최소 개수를 구하여라!
'''
'''
무조건 DP같다
근데 흠 각 숫자에 다다랐을때, 최소항의 개수를 구해야하는데,
7의 경우는 4지만, 8은 2이다. 이런 경우를 다룰 방법을 생각해봐야 함!
'''
import math

# N = 자연수
N = int(input())

dp = [0] * (N+1)

dp[1] = 1

for i in range(2, N+1):
    tmp = math.floor(math.sqrt(i))
    answer = dp[i-1] + 1
    for j in range(2, tmp+1):
        if j**2 != i:
            tmp_dp = dp[j**2] + dp[i - j**2]
        elif j**2 == i:
            tmp_dp = 1

        if answer > tmp_dp:
            answer = tmp_dp

    dp[i] = answer

print(dp[N])
