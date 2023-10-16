'''
상근이는 부자라서 전세기를 빌리고 친구가 10억명이나 된다
한국인구수보다 많네 어이x
입국심사대가 10만개나 있는 오스트레일리아는 부자들이 놀러가기 딱 좋은것 같다
그럼 시간이 금인 이 친구들이 어떻게해야 빠르게 입국심사를 끝내고 호화로운 여행을 갈 수 있을까?
'''
'''
테스트케이스 10억개 정도다? 그럼 그냥 이분탐색이 떠오른다.
그냥 단순한 이분 탐색은 아니다. 어떻게 해야 가장 빠른데로 들어갈 수 있을까?
시간을 제시하고, 해당 시간을 이분하여 찾자
음... 일단 ㄱㄱ
'''
import sys
input = sys.stdin.readline

N, M = map(int, input().split())

check_times = []

# 주어지는 소모 시간 값을 check_time에 담음
for m in range(N):
    tmp = int(input())
    check_times.append(tmp)

# 받은 값들을 정렬
check_times.sort()

# 가장 오래걸리는 시간이 M번만큼 이루어지는게 최악의 시간으로 생각
max_time = check_times[-1] * M

# start와 end를 지정하고 결과값을 담을 result 선언
start = 0
end = max_time
result = 0

# 이분탐색 시작
while start <= end:
    cnt = 0
    mid = (start + end) // 2

    # 시간들을 순회하면서, mid일때 해당 창구에서 얼마나 많은 사람을 보낼 수 있는지 확인
    for i in check_times:
        cnt += (mid // i)

    # 만약 여행온 사람 수보다 많이 체크할 수 있다면 result에 mid 값을 담고고
    # 왼쪽 구간으로 이동
    if cnt >= M:
        end = mid - 1
        result = mid
    # cnt 개수가 모자라면 오른쪽 구간으로 이동
    elif cnt < M:
        start = mid + 1

print(result)