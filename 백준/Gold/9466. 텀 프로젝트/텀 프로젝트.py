'''
팀을 짜주자!
각 학생들은 팀을 하고싶어하는 학생이 1명이 있다 (반드시 1명만) 팀을 구성할 때 쭉이어가다가 마지막에 처음 팀을 짜고 싶어했던
학생으로 돌아오면 팀이된다 즉 혼자 하고싶은 사람도 팀이 된다!
모두 팀을 짜줬을 때, 팀을 짜지 못한 학생들의 수를 구하여라!
'''
'''
각 학생들을 노드로 보고 원하는 학생을 간선으로 생각하여 루프가 생기는지 확인하자!
루프가 생기면 팀 아니면 팀을 못 만든 것이다!
중간에 생기는 루프도 관리하면 용이할 것 같긴했는데 그렇게 해야할것 같다
어떻게 구현하는게 좋을까? dfs?
'''
from collections import deque

# T = 테스트 케이스의 개수
T = int(input())

for tc in range(1, T+1):
    # N = 학생의 수
    N = int(input())

    wanna = [0] + list(map(int, input().split()))
    students = [0] * (N+1)
    result = N
    rooped = [0] * (N+1)

    for w in range(1, N+1):
        if rooped[w] == 0:
            que = deque()
            que.append([w, w, [w], {w}])

            while que:
                now, source, cnt, cnt_set = que.popleft()

                next_node = wanna[now]
                if next_node == source:
                    result -= len(cnt)
                    for c in cnt:
                        rooped[c] = 1
                    break

                elif next_node in cnt_set:
                    idx = cnt.index(next_node)
                    result -= (len(cnt) - idx)
                    for r in range(idx, len(cnt)):
                        rooped[cnt[r]] = 1
                    break

                if next_node >= w and rooped[next_node] == 0:
                    if now == next_node:
                        break
                    rooped[next_node] = 1
                    cnt.append(next_node)
                    cnt_set.add(next_node)
                    que.append([next_node, source, cnt, cnt_set])

    print(result)
