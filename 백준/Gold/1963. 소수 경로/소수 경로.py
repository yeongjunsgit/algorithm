'''
창영이는 비밀번호를 4자리의 소수로 정해두었다
그러나 비밀번호를 바꿀때가 되어서 비밀번호를 바꾸어야한다.
하지만 해당 게임은 비밀번호를 바꿀 때 단 1개의 숫자만 바꿀 수 있다.
창영이는 소수를 사랑해서 1개의 숫자를 바꿀때도 소수가 아니라면 용서하지 못한다.
몇번의 소수를 걸쳐서 원하는 비밀번호로 바꿀 수 있을지 구하라!
만약, 이동이 불가능하다면, impossible을 출력하라!
'''
'''
비밀번호는 무조건 4자리이고 1~9안의 숫자로 바꿀수 있다.
1개씩 바꾸어서 소수인지를 확인하고, 경우의 수를 돌리면 되지 않을까?
흠 그런데 이거... 소수인지 아닌지는 어떻게 판단할까...?

1. 해당 수를 나누어서 소수인지 판단하기!
-> 이거 모든 경우의 수를 봐야하기 때문에, 4개의 숫자 자리중 한자리 당
8개의 경우의 수가 나온다 즉 숫자 1개 탐색당 32번씩 해야하는데, 
가능은 할 것 같지만 흠 효율적이진 않아보이는데...
우선 나누어서 판단할 것이라면, 해당 숫자의 제곱근에 +1을 해서 2부터 그 제곱근까지
해당 숫자와 나누어 떨어지는지 확인해야한다!

2. 에라토스테네스의 체
-> 소수 구하는 방법 찾아보다가 얻어걸린 이론이다. 2부터 해당 수까지 순회하면서
해당 수의 배수를 전부 배열에서 뺀다. 그렇게 진행하여 남은 숫자들은 소수 인 것이다.
소수가 많이 등장할 것 같아보임으로 이 알고리즘이 제일 나아보인다!
이걸로 채택!
'''
from collections import deque
import math

used_lis = [True for i in range(10001)]

for p in range(2, int(math.sqrt(10000)) + 1):
    if used_lis[p] is True:
        q = 2
        while p * q <= 10000:
            if used_lis[p*q] is True:
                used_lis[p*q] = False
            q += 1

T = int(input())

for tc in range(1, T+1):
    now_num, target = map(int, input().split())

    que = deque()
    que.append([0, now_num])
    visited = {now_num: 1}
    result = "impossible"

    while que:
        moved, now = que.popleft()
        if now == target:
            result = moved
            break

        string_now = str(now)
        lis_now = list(string_now)
        for f in range(4):
            for i in range(10):
                if str(i) != lis_now[f]:
                    tmp_lis = lis_now.copy()
                    tmp_lis[f] = str(i)
                    tmp = ''.join(tmp_lis)
                    tmp_num = int(tmp)
                    if used_lis[tmp_num] is True and tmp_num >= 1000:
                        if tmp_num not in visited:
                            visited[tmp_num] = 1
                            que.append([moved+1, tmp_num])

    print(result)
