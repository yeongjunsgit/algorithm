# DFS!!!!!!!!!

T = int(input())

# 이동 방향 선언
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

for tc in range(1, T+1):
    M, N, K = map(int, input().split())
    arr = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]       # 방문기록을 남길 visited 2차원 배열 선언
    white_bug = 0
    stack_x = [0] * M * N
    stack_y = [0] * M * N
    top = -1

    for k in range(K):                          # 배추를 arr에 1으로 심어줌
        x, y = map(int, input().split())
        arr[y][x] = 1

    for i in range(N):
        for j in range(M):
            if arr[i][j] == 1 and visited[i][j] == 0:
                visited[i][j] = 1
                top += 1
                stack_x[top] = i
                stack_y[top] = j
                while True:
                    cant_move = 0
                    for p in range(4):
                        ni = stack_x[top] + di[p]
                        nj = stack_y[top] + dj[p]
                        if 0 <= ni <= N-1 and 0 <= nj <= M-1:
                            if arr[ni][nj] == 1 and visited[ni][nj] == 0:
                                visited[ni][nj] = 1
                                top += 1
                                stack_x[top] = ni
                                stack_y[top] = nj

                            else:
                                cant_move += 1

                        else:
                            cant_move += 1

                    if cant_move == 4:
                        top -= 1

                    if top == -1:
                        white_bug += 1
                        break
    print(white_bug)