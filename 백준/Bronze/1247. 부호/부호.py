import sys
input = sys.stdin.readline

for i in range(3):
    N = int(input())
    M = 0
    for j in range(N):
        K = int(input())
        M += K
    if M > 0:
        print('+')
    elif M == 0:
        print(0)
    else:
        print('-')