import sys
input = sys.stdin.readline

# D = 탈출구까지의 거리, N = 돌섬의 개수, M = 제거 가능한 돌섬의 개수
D, N, M = map(int, input().split())

# 시작점과 끝점을 담은 stone_bridge 선언
stone_bridge = [0, D]

# 돌다리들을 전부 리스트에 담는다.
for n in range(N):
    stone = int(input())
    stone_bridge.append(stone)

stone_bridge.sort()

# 각 돌다리 사이의 거리를 distance에 담는다.
distance = []

for e in range(N+1):
    tmp = stone_bridge[e+1] - stone_bridge[e]
    distance.append(tmp)


# 이분 탐색 준비
start = 0
end = int(1e9)
result = 0

# 이분 탐색 시작
while start <= end:
    # 없애버린 돌다리를 세어줄 cnt 선언
    # 현재 뛰어온 거리를 담아줄 tmp 선언
    cnt = 0
    mid = (start + end) // 2
    tmp = 0

    # 모든 돌다리 사이의 거리를 순회하면서, tmp에 현재까지 넘어온 거리를 담는다.
    for i in range(len(distance)):
        tmp += distance[i]

        # 만약 지금 거리가 mid 보다 크거나 같다면
        # tmp를 0으로 초기화
        if tmp >= mid:
            tmp = 0
        # 만약 tmp가 mid보다 작다면 돌다리 1개를 삭제
        elif tmp < mid:
            cnt += 1

    # 반복이 끝난 후,
    else:
        # 만약, 없앤 돌다리 수가 M보다 크다면, 왼쪽 구간으로 간다.
        if cnt > M:
            end = mid - 1

        # 만약, 없앤 돌다리 수가 M보다 작거나 같다면, 오른쪽 구간으로 간다.
        # result에 현재 mid 값을 담는다.
        else:
            start = mid + 1
            result = mid

# 돌다리가 0개라면 현재 탈출구까지의 거리를 출력
if N == 0:
    print(D)
else:
    print(result)