'''
그래픽스 너무 어려워요
학생들은 N개의 책상으로 나열된, 책상에 2명씩 앉아있다. 교수님은
학생들 얼굴만 봐도 무슨 점수를 받을지 알고있다.
근데 색연필을 1개밖에 안가져와서 질문을 잘해서 1개의 그레이드를 최대 학생 수 만큼 주려고한다.
무슨 점수를 받을지 알고 있을 때, 질문을 해서 가장 많은 학생의 수를 그레이드 주자.
'''
'''
음~~~ 지나가면서 최대값을 기록하자! 연속되는 경우만 기록해주며 만약 이동했을때 해당 수가 없다면 0으로 초기화한다.
최고기록 경신을 횟수 변경마다 확인하여 지속적으로 갱신!
더 작은 그레이드 라면 같은 학생수라도 해당 그레이드로 변경!
'''
from collections import deque

# N = 책상의 수
N = int(input())

best = [0, 0]

grades = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0}

for n in range(N):
    one, two = map(int, input().split())
    for i in range(1, 6):
        if i == one or i == two:
            grades[i] += 1
            if best[0] < grades[i]:
                best = [grades[i], i]

            elif best[0] == grades[i]:
                if best[1] > i:
                    best[1] = i

        else:
            grades[i] = 0

print(*best)
