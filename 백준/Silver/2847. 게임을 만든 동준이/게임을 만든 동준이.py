N = int(input())
level = []
max_level = -1
cnt = 0
for n in range(N):
    level.append(int(input()))

max_level = level[-1]

for i in range(len(level)-2, -1, -1):
    if level[i] >= max_level:
        while level[i] >= max_level:
            level[i] -= 1
            cnt += 1
    max_level = level[i]

print(cnt)