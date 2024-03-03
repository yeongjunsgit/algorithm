'''
주어진 수 N보다 크거나 같으면서, 소수이기까지 하고 거기다가 팰린드롬인 어마어마한 수를 찾아야한다.
이때, N에서 부터 가장 작은 수여야만 한다.
'''
'''
N보다 큰 값을 찾아야 한다는게 좀 걸리네
에라스토스테네스의 체? 그걸 쓰기엔 좀 어려울 것 같은데
그렇다고 일일이 N보다 큰 값에 대해서 소수인지 확인하는게 괜찮을까?
게다가 펠린드롬인지 확인까지 해야한다.
'''
import math
from collections import deque


def is_palindrome(num):
    word = str(num)
    words = deque(list(word))
    for w in range(len(words) // 2):
        tmp_1 = words.popleft()
        tmp_2 = words.pop()

        if tmp_1 != tmp_2:
            return False

    else:
        return True


def is_primary(num):
    if num != 1:
        target = math.floor(math.sqrt(num))
        for p in range(2, target+1):
            if num % p == 0:
                return False

        else:
            return True
    elif num == 1:
        return False


# N = 주어지는 수
N = int(input())

while True:
    first_check = is_palindrome(N)
    if first_check is False:
        N += 1
    else:
        if N % 2 == 0 and N >= 10:
            N += 1

        else:
            second_check = is_primary(N)
            if second_check is False:
                N += 1

            else:
                print(N)
                break
