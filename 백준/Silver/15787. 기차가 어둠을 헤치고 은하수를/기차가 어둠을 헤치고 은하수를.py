'''
N개의 기차가 어둠을 헤치고 은하수를 건너려고 한다.
기차는 20개의 일렬로된 좌석이 있고, 한 개의 좌석에는 한명의 사람이 탈 수 있다.
기차의 번호를 1번부터 N번으로 매길 때, 어떠한 기차에 대하여 M개의 명령이 주어진다.
명령의 종류는 4가지로 다음과 같다.
1 i x : i번째 기차에 x번째 좌석에 사람을 태워라. 이미 사람이 있다면 아무런 행동도 하지 않는다.
2 i x : i번째 기차에 x번째 좌석에 앉은 사람은 하차한다. 만약 그 자리에 아무도 없다면 아무일도 일어나지 않는다.
3 i : i번째 기차에 앉아있느 승객들이 모두 한 칸씩 뒤로 간다. k번째 앉은 사람은 k+1번째로 이동하여 앉는다. 만약 20번째 자리에 사람이 앉아있었다면, 그 사람은 이명령후 하차한다.
4 i : i번째 기차의 승객들이 모두 한 칸씩 앞으로 간다. 1번째 사람이 있었다면 명령 후 하차한다.

M번의 명령 후에 1번째 기차부터 순서대로 한 기차씩 은하수를 건너는데 조건이 있다.
이미 지나간 좌석배치도와 똑같은 좌석배치를 가진 기차는 지나갈 수 없다.
이럴때 지나갈 수 있는 기차의 개수를 구하시오.
'''
'''
구현좌 같은데
'''
# N = 기차의 수, M = 명령의 횟수
N, M = map(int, input().split())

trains = [[0] * 21 for _ in range(N+1)]

for m in range(M):
    commands = list(map(int, input().split()))
    if commands[0] == 1:
        target = commands[1]
        seat = commands[2]

        trains[target][seat] = 1

    elif commands[0] == 2:
        target = commands[1]
        seat = commands[2]
        trains[target][seat] = 0

    elif commands[0] == 3:
        target = commands[1]
        for t in range(20, 0, -1):
            if trains[target][t] == 1:
                if t == 20:
                    trains[target][t] = 0

                else:
                    trains[target][t+1] = 1
                    trains[target][t] = 0

    elif commands[0] == 4:
        target = commands[1]
        for t in range(1, 21):
            if trains[target][t] == 1:
                if t == 1:
                    trains[target][t] = 0

                else:
                    trains[target][t-1] = 1
                    trains[target][t] = 0

cnt = 0
passed_trains = set()
for i in range(1, N+1):
    check = tuple(trains[i])
    if check not in passed_trains:
        cnt += 1
        passed_trains.add(check)

print(cnt)
