arr = [[0] * 101 for _ in range(101)]
area = 0
N = int(input())

for f in range(N):
    x1, y1 = map(int, input().split())

    for x in range(x1, x1+10):
        for y in range(y1, y1+10):
            if arr[x][y] == 0:
                arr[x][y] = 1


for i in range(101):
    for j in range(101):
        if arr[i][j] == 1:
            area += 1

print(area)