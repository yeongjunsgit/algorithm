'''
백준씨가 신나는 캠프를 진행하려고 한다.
근데, 캠프에서 문제를 낼때 너무 쉬우면 시시해하고 너무 어려우면 야유가 쏟아진다.
딱 적절한 정도의 문제 출제가 필요한데, 가장 쉬운 문제와 가장 어려운 문제의 난이도 차는 X보다 크거나
같아야하고, 문제 난이도의 합도 L보다 크거나 같고, R보다 작거나 같아야한다.
문제의 난이도들이 주어질때, 출제 가능한 방법의 수를 구하여라.
'''
'''
흠 문제가 N개 주어질때, max와 min을 구해야하는건데 그러면
일단 X를 만족하는 경우를 찾고 나머지 수들을 더해서 L과 R 사이일때 까지 개수를 샐까?
그러면 NlogN 가능??하려나
'''
from itertools import combinations

# N = 문제의 개수, L = 문제난이도 합의 최소값, R = 문제 난이도 합의 최대값, X = 문제끼리의 난이도 차이
N, L, R, X = map(int, input().split())

quizzes = list(map(int, input().split()))

cnt = 0

for i in range(2, N+1):
    for j in combinations(quizzes, i):
        mini = min(j)
        maxy = max(j)
        if maxy - mini >= X:
            if L <= sum(j) <= R:
                cnt += 1

print(cnt)
