'''
야구는 9명으로 이루어진 두 팀이 공격과 수비를 번걸아 하는 게임이다. 하나의 이닝은 공격과 수비로 이루어져 있고, N이닝 동안 게임을 진행해야 한다.
한 이닝에 3아웃이 발생하면 이닝이 종료되고, 두 팀이 공격과 수비를 서로 바꾼다.

두 팀은 경기가 시작하기 전까지 타순을 정해야 하고, 경기 중에는 타순을 변경할 수 없다. 9번 타자까지 공을 쳤는데 3아웃이 발생하지 않는 상태면 이닝은 끝나지 않고,
1번 타자가 다시 타석에 선다. 타순은 이닝이 변경되어도 순서를 유지해야 한다. 예를 들어 2이닝에 6번 타자가 마지막 타자였다면, 3이닝은 7번타자부터 타석에 선다.

한 야구팀의 감독 아인타는 타순을 정하려고 한다. 아인타 팀의 선수는 총 9명이 있고, 1번부터 9번까지 번호가 매겨져 있다. 아인타는 자신이 가장 좋아하는 선수인 1번 선수를
4번 타자로 미리 결정했다. 이제 다른 선수의 타순을 모두 정해야 한다. 아인타는 각 선수가 각 이닝에서 어떤 결과를 얻는지 미리 알고 있다. 가장 많은 득점을 하는 타순을
찾고, 그 때의 득점을 구해보자.
1 = 안타
2 = 2루타
3 = 3루타
4 = 홈런
0 = 아웃
'''
'''
1번 타자가 무조건 4번 타자이다.
그리고 아웃 당한 다면 그 다음이닝에선 아웃 당한타자의 다음 타자가 공을 쳐야한다.
어떻게 해야 할까 이거 알려면 브루트 포스 해야하지않을까?
'''
import sys
from itertools import permutations
input = sys.stdin.readline


def play_game(arr):
    global cnt
    idx = 0
    now_player = arr[idx]
    score = 0
    use_one = False

    for j in range(N):
        now_inning = innings[j]
        base1 = base2 = base3 = 0
        out = 0

        while out != 3:
            if idx == 3 and use_one is False:
                use_one = True
                now_player = 1
                idx -= 1

            elif idx == 3 and use_one is True:
                use_one = False
                now_player = arr[idx]

            else:
                now_player = arr[idx]

            now_score = now_inning[now_player-1]

            if now_score == 1:
                score += base3
                base1, base2, base3 = 1, base1, base2

            elif now_score == 2:
                score += (base2 + base3)
                base1, base2, base3 = 0, 1, base1

            elif now_score == 3:
                score += (base1 + base2 + base3)
                base1, base2, base3 = 0, 0, 1

            elif now_score == 4:
                score += (base1 + base2 + base3 + 1)
                base1, base2, base3 = 0, 0, 0

            elif now_score == 0:
                out += 1

            idx = (idx + 1) % 8

    if cnt < score:
        cnt = score


# N = 이닝 수
N = int(input())

innings = []

for n in range(N):
    inning = list(map(int, input().split()))
    innings.append(inning)

cnt = 0

for z in permutations([2, 3, 4, 5, 6, 7, 8, 9], 8):
    play_game(z)

print(cnt)
