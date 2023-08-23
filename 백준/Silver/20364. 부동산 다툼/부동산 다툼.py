
def can_get_it(r):
    start = 1
    g = want_house[r]
    match = 0
    if visited[g] == 0:
        visited[g] = 1
    else:
        match = g
    while g > 0:
        if visited[g//2] == 0:
            g //= 2
        elif visited[g//2] == 1:
            match = g // 2
            g //= 2

    print(match)

N, Q = map(int, input().split())
want_house = [0] * (N+Q+1)
visited = [0] * (N+Q+1)
for i in range(1, Q+1):
    want_house[i] = int(input())

for j in range(1, Q+1):
    can_get_it(j)