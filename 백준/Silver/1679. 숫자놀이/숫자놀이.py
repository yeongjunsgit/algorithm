N = int(input())

numbers = list(map(int, input().split()))

K = int(input())

dp = [int(1e9)] * (numbers[-1] * K + 2)

for i in range(1, numbers[-1] * K + 2):
    if i in numbers:
        dp[i] = 1

    else:
        for j in range(N):
            if i < numbers[j]:
                break

            elif i >= numbers[j]:
                dp[i] = min(dp[i], dp[i-numbers[j]]+1)

    if dp[i] > K:
        if i % 2 == 0:
            print(f'holsoon win at {i}')
            break

        elif i % 2 == 1:
            print(f'jjaksoon win at {i}')
            break

