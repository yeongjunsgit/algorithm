'''
악!
'''
'''
맨 앞자리는 무조건 소수가 가능한 값만 가능하다.
모든 자리가 소수로 될 수 있는 경우만 찾아서 뒤에 하나씩 붙여나가자
'''
from collections import deque
import math

def check(num):
    target = math.floor(math.sqrt(num))

    for c in range(2, target+1):
        if num % c == 0:
            return False

    else:
        return True


N = int(input())

part = 10 ** (N-1)

que = deque()

que.extend([2, 3, 5, 7])
odd = [1, 3, 5, 7, 9]

while que:
    catch = que.popleft()
    if part < catch < part * 10:
        print(catch)

    else:
        tmp = catch * 10
        for o in range(5):
            pri = tmp + odd[o]
            judge = check(pri)

            if judge is True:
                que.append(pri)
