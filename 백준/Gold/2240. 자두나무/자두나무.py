'''
자두는 자두를 받아먹으려고 한다
자두네 집에는 자두나무가 2개 있으며 자두가 떨어질때 해당 나무 아래 있어야 자두를 받아먹을 수 있다.
자두가 떨어지는 나무의 순서는 정해져있다.
자두는 나무와 나무를 이동할 수 있는 횟수가 정해져 있다.
해당 횟수안에서 가장 자두를 많이 받을 수 있는 경우를 구하여라!
맨처음엔 1번 나무에 서있다.
'''
'''
두개의 위치가 있다.
W 만큼 움직일 수 있다.
흠... 잘 감이 안오네
일단 경우의 수 만큼 늘려버리면 무조건 시간초과가 날거같은데...
이건 안되겠다 ㅋㅋ
단순히 DP로 하고싶은데 흠... 이동횟수 제약이 있는게 걸린다 이것까지 관리해서 DP가 가능할까?
어떻게 해야하지............?
우선 해당 위치에서 발생하는 2가지 경우를 따져보자..
현재위치에 남기, 옆으로 이동하기
그렇게하면 되려나...?
'''
import sys
input = sys.stdin.readline


# T = 떨어지는 자두의 개수, W = 이동 가능한 횟수
T, W = map(int, input().split())

# dp를 W(이동가능 횟수)만큼 기록할수 있게 선언
dp = [[-1] * (T+1) for _ in range(W+1)]
# 맨처음은 아무것도 얻을 수 없으니 0
dp[0][0] = 0
cnt = 0

# 주어지는 자두의 떨어지는 위치를 보고 생각한다.
# 기본적으로 시작은 1에서 함으로 홀수번 움직이면 위치는 2번나무,
# 0을 포함한 짝수번 움직인 상황은 1번 나무이다.
# 즉, dp를 순회하면서 W값이 홀수 or 짝수에 따라 주어지는 자두나무 드랍위치를 확인하여 아래서 끌어올리거나, 바로 1초전의 경우에서
# 값을 가져오는 등의 방법으로 구현함
for t in range(1, T+1):
    tree = int(input())
    # 자두 드랍 위치가 1이라면
    if tree == 1:
        # 이동 가능 횟수만큼 순회한다.
        for i in range(W+1):
            # 현재 위치가 1번 나무일때,
            if i % 2 == 0:
                tmp = -1
                tmp_2 = -1
                # 바로 1초전에 상황이 계산된적이 있다면 해당 값에 1을 더해서(현재 위치에서 자두가 떨어지기 때문) tmp에 저장
                if dp[i][t-1] != -1:
                    tmp = dp[i][t-1] + 1
                # 1초전에 바로 아랫 이동횟수의 값이 존재한다면, 해당 값에 1을 더해서 tmp_2에 저장(이동횟수를 이용해 현재나무로 왔기때문)
                if i-1 >= 0 and dp[i-1][t-1] != -1:
                    tmp_2 = dp[i-1][t-1] + 1
                # 2개의 값중 가장 큰값을 현재 위치에 저장
                tmp_dp = max(tmp, tmp_2)
                if dp[i][t] < tmp_dp:
                    dp[i][t] = tmp_dp

            # 현재 위치가 2번 나무라면,
            elif i % 2 == 1:
                tmp = -1
                tmp_2 = -1
                # 바로 1초전 현재위치의 값을 가져와 tmp에 넣는다 (현재 위치에서 자두가 떨어지지 않기 때문에 값을 더하지 않음)
                if dp[i][t-1] != -1:
                    tmp = dp[i][t-1]

                # 바로 1초전 바로 아랫 이동횟수의 값을 가져와 tmp_2에 저장 (현재 위치에서 자두가 떨어지지 않기 때문에 값을 더하지 않음)
                if i-1 >= 0 and dp[i-1][t-1] != -1:
                    tmp_2 = dp[i-1][t-1]
                # 2개의 값중 가장 큰 값을 현재 위치에 저장
                tmp_dp = max(tmp, tmp_2)
                if dp[i][t] < tmp_dp:
                    dp[i][t] = tmp_dp

    # 만약 2번 나무에서 자두가 떨어진다면,
    elif tree == 2:
        # 이동 횟수만큼 순회한다.
        for i in range(W+1):
            # 현재 위치가 2번 나무라면
            if i % 2 == 1:
                tmp = -1
                tmp_2 = -1
                # 바로 1초전 현재 위치의 값에 1을 더한 값을 tmp에 저장한다 (현재 위치에서 자두가 떨어짐)
                if dp[i][t-1] != -1:
                    tmp = dp[i][t-1] + 1

                # 바로 1초전 바로 아랫 이동횟수의 값을 가져와 1을 더한 후 tmp_2에 저장 (현재 위치에서 자두가 떨어짐)
                if i-1 >= 0 and dp[i-1][t-1] != -1:
                    tmp_2 = dp[i-1][t-1] + 1
                # 2개의 값중 가장 큰 값을 현재 위치에 저장
                tmp_dp = max(tmp, tmp_2)
                if dp[i][t] < tmp_dp:
                    dp[i][t] = tmp_dp

            # 현재 위치가 1번 나무라면
            elif i % 2 == 0:
                tmp = -1
                tmp_2 = -1
                # 바로 1초전 현재 위치의 값을 tmp에 저장한다. (현재 위치에서 자두가 떨어지지 않기 때문에 값을 더하지 않음)
                if dp[i][t-1] != -1:
                    tmp = dp[i][t-1]

                # 바로 1초전 아랫 이동횟수의 값을 가져와 tmp_2에 저장한다
                if i-1 >= 0 and dp[i-1][t-1] != -1:
                    tmp_2 = dp[i-1][t-1]
                # 둘 중 큰 값을 현재 위치에 저장
                tmp_dp = max(tmp, tmp_2)
                if dp[i][t] < tmp_dp:
                    dp[i][t] = tmp_dp

# 모든 dp를 순회하면서 가장 높은 값을 찾는다.
for p in range(W+1):
    for q in range(T+1):
        if dp[p][q] > cnt:
            cnt = dp[p][q]

print(cnt)
