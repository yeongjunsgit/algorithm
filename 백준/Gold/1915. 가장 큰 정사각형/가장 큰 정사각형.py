'''
다이나믹 하다
'''

check_lis = [[-1, 0], [0, -1], [-1, -1]]

# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())
arr = [list(map(int, input())) for _ in range(N)]

visited_1 = [[0] * M for _ in range(N)]
result = 0

for n in range(N):
    for m in range(M):
        if arr[n][m] == 1:
            visited_1[n][m] = 1
            if result < 1:
                result = 1
            cnt = 0
            check = []
            for t in range(3):
                di, dj = check_lis[t]
                nx = n + di
                ny = m + dj
                if 0 <= nx < N and 0 <= ny < M and arr[nx][ny] == 1:
                    cnt += 1
                    check.append(visited_1[nx][ny])
                else:
                    break
            else:
                if cnt == 3:
                    visited_1[n][m] = min(check) + 1
                    if visited_1[n][m] > result:
                        result = visited_1[n][m]
print(result * result)