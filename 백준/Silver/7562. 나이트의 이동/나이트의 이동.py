import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def bfs(si, sy, ti, ty):
    global min_move
    di = [-2, -1, 1, 2, 2, 1, -1, -2]
    dj = [1, 2, 2, 1, -1, -2, -2, -1]
    que = [0] * (N**2)
    rear = 0
    front = -1
    que[rear] = (si, sy)
    visited = [[0] * N for _ in range(N)]
    visited[si][sy] = 1

    while rear != front:
        front += 1
        si, sy = que[front]

        if si == ti and sy == ty:
            if min_move > visited[si][sy]:
                min_move = visited[si][sy] - 1
            break
        else:
            for i in range(8):
                ni = si + di[i]
                nj = sy + dj[i]
                if 0 <= ni < N and 0 <= nj < N and visited[ni][nj] == 0:
                    rear += 1
                    que[rear] = (ni, nj)
                    visited[ni][nj] = visited[si][sy] + 1

T = int(input())

for tc in range(1, T+1):
    N = int(input())
    si, sy = map(int, input().split())
    ti, ty = map(int, input().split())
    min_move = N ** 2

    bfs(si, sy, ti, ty)
    print(min_move)