'''
총 8개의 톱니를 가지고 있는 톱니바퀴 T개가 일렬로 놓여져 있다.
각 톱니는 N극이나 S극 중 하나를 나타내고 있다. 톱니 바퀴에는 번호가 있으며 각 왼쪽부터 1번... 하여 T번까지 나타난다.
이때 톱니바퀴를 총 K번 회전 시키려고 한다. 톱니 바퀴의 회전은 한칸을 기준으로 한다. 회전은 시계방향 과 반시계방향 이 있다.
회전할때 만약 맞닿은 톱니바퀴의 톱니의 극이 서로 다르다면 해당 톱니바퀴는 돌려지는 톱니의 반대 방향으로 회전한다.
K번 회전 시켰을때 톱니바퀴의 최종 모양을 구하여라
'''
'''
구현하자
서로 맞닿는 부분은 2번, 6번 인덱스 이다.
'''
from collections import deque


def near_gear(now, direct, pre):
    global rotate_lis
    if now + 1 < T and now + 1 != pre:
        if gears[now][2] != gears[now+1][6]:
            rotate_lis.append([now+1, -direct])
            near_gear(now+1, -direct, now)

    if now - 1 >= 0 and now - 1 != pre:
        if gears[now][6] != gears[now-1][2]:
            rotate_lis.append([now-1, -direct])
            near_gear(now-1, -direct, now)


def rotate(data):
    global complete_lis
    num, goto = data

    tmp_gear = deque(gears[num])

    if goto == 1:
        tmp = tmp_gear.pop()
        tmp_gear.appendleft(tmp)
        complete_lis.append([num, tmp_gear])

    elif goto == -1:
        tmp = tmp_gear.popleft()
        tmp_gear.append(tmp)
        complete_lis.append([num, tmp_gear])



# T = 톱니바퀴의 개수
T = int(input())

gears = []

cnt = 0

# N극은 0, S극은 1
for t in range(T):
    gear = list(map(int, input()))
    gears.append(gear)

K = int(input())

for k in range(K):
    # 1 = 시계 방향, -1 = 반시계 방향
    target, direction = map(int, input().split())
    # 해당 기어에 맞닿은 기어들이 돌아가는지 확인
    rotate_lis = [[target-1, direction]]
    near_gear(target-1, direction, -1)

    complete_lis = []
    for r in rotate_lis:
        rotate(r)

    for c in complete_lis:
        gears[c[0]] = c[1]

for g in gears:
    if g[0] == 1:
        cnt += 1

print(cnt)
