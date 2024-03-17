import sys
import heapq
input = sys.stdin.readline

N = int(input())

num_dict = {}

for n in range(N):
    num = int(input())
    if num in num_dict:
        num_dict[num] += 1

    else:
        num_dict[num] = 1

for i in range(1, 10001):
    if i in num_dict:
        for j in range(num_dict[i]):
            print(i)
