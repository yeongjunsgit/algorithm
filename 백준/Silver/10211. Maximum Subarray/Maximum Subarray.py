'''
N개의 정수로 이루어진 배열이 있을때, 해당 배열에서 연속한 부분 배열 중
원소의 합이 가장 큰 부분 배열을 찾아 그 합을 구하여라!
'''
'''
DP 문제 같다!
해당 배열을 순회하면서 해당위치까지의 발생할 수 있는 가장 큰 총합을 기록해두고,
계속해서 진행하자!
'''
# T = 테스트케이스의 개수
T = int(input())

for tc in range(1, T+1):
    N = int(input())
    arr = list(map(int, input().split()))

    dp = [0] * N
    dp[0] = arr[0]

    for i in range(1, N):
        tmp = dp[i-1] + arr[i]

        dp[i] = max(tmp, arr[i])

    print(max(dp))