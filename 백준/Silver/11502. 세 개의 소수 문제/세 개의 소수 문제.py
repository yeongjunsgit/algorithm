'''
정수(사람아님)론에 따르면, 세 개의 소수 문제는 다음과 같은 추측을 말한다.
5보다 큰 임의의 홀수는 정확히 세 개의 소수들의 합으로 나타낼 수 있다.
물론 하나의 소수를 여러 번 더 할 수 있다.
예를 들면
7 = 2+2+3
11 = 2+2+7
25 = 7+7+11

이다. 5보다 큰 임의의 홀수를 입력받아서, 그 홀수가 어떻게 세 소수의 합으로 표현될 수 있는지 알아보는
프로그램을 작성하시오.
'''
'''
소수 몇개 구해서 중복이 가능하게 수열을 짜면 어떠려나 터지려나
일단 주어지는 정수(사람아님)의 범위가 7 부터 1000까지의 홀수라서 가능할 것 같긴하다. 
'''


def perm(s, e):
    global is_over
    if is_over is True:
        return
    if s == e:
        if sum(pq) == N:
            print(*pq)
            is_over = True

    else:
        for i in range(len(primary)):
            if primary[i] < N:
                pq.append(primary[i])
                perm(s+1, e)
                pq.pop()


primary = []
aerastos = [True for _ in range(1001)]

for a in range(2, 1001):
    if aerastos[a] is True:
        primary.append(a)
        idx = 2
        while True:
            if a * idx < 1001:
                aerastos[a*idx] = False
                idx += 1

            else:
                break

T = int(input())

for tc in range(1, T+1):
    N = int(input())

    pq = []
    is_over = False
    perm(0, 3)
    if is_over is False:
        print(0)
