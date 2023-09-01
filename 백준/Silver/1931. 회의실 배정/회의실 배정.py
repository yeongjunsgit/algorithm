import sys
input = sys.stdin.readline

N = int(input())
time = []
for n in range(N):
    a, b = map(int, input().split())
    time.append((a, b))

time.sort(reverse=True)

j = 0
S = []
for i in range(1, N):
    if time[j][0] >= time[i][1]:
        S.append(i)
        j = i

print(len(S)+1)