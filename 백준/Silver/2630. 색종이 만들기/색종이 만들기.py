'''
하얀색은 0, 파란색은 1
하얀색, 파란색 순으로 출력
'''

from collections import deque

N = int(input())

paper = [list(map(int, input().split())) for _ in range(N)]
white_paper = 0
blue_paper = 0

que = deque()
que.append([N, 0, 0])

while que:
    s, x, y = que.popleft()
    static = paper[x][y]
    is_ok = True

    for i in range(x, x+s):
        if is_ok is False:
            break
        for j in range(y, y+s):
            if paper[i][j] != static:
                que.append([s//2, x, y])
                que.append([s//2, x, y + s//2])
                que.append([s//2, x + s//2, y])
                que.append([s//2, x + s//2, y + s//2])
                is_ok = False
                break
    else:
        if is_ok is True:
            if static == 0:
                white_paper += 1
            else:
                blue_paper += 1

print(white_paper)
print(blue_paper)