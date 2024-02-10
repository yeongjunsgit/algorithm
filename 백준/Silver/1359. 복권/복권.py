'''
지민이는 복권 광고를 봤다.
1부터 N까지의 수 중에 서로 다른 M 개의 수를 골라보세요! 저희도 똑같이 M개를 고를 건데 적어도 K개의
수가 같으면 당첨입니다
이거 완전 로또아니냐
지민이는 돌아오면서 자신이 복권에 당첨될 확률이 궁금해졌다.
지민이가 복권에 당첨될 확률을 구하는 프로그램을 작성하시오.
단, 절대/상대 오차는 10 ** -9 까지 허용한다.
'''
'''
그냥 경우의 수에서 발생할 수 있는 확률을 찾으라는 건가
예시를 보면 3개에서 1개를 골라서 1개가 맞을 확률
즉 0.33 근데 0.3333333333333333 이라네 왜 16번째 자리까지 나오지..
3개에서 2개를 골라 적어도 1개가 맞을 확률 1,2 그리고 2,3 만해도 2가 맞으니까 무조건 100% 당첨
이땐 1.0이라고 하네 또
'''
from itertools import permutations, combinations


# N = 수의 개수, M = 고르는 숫자의 수, K = 같아야하는 숫자의 개수
N, M, K = map(int, input().split())

arr = [a for a in range(1, N+1)]

total = 0
match = 0

for i in combinations(arr, M):
    for j in combinations(arr, M):
        total += 1
        collect = 0
        for k in j:
            if k in i:
                collect += 1
                if collect == K:
                    match += 1
                    break

result = round(match / total, 16)

print(result)
