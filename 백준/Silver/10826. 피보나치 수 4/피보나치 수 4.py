import sys
sys.setrecursionlimit(10**5)

def fibo(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        if memo[n] == 0:
            memo[n] = fibo(n-1) + fibo(n-2)
            return memo[n]
        else:
            return memo[n]

N = int(input())
memo = [0] * (N+1)
print(fibo(N))