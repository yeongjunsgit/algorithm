'''
스타는 별을 가두는 장치를 만들어 본인이 가지고 있는 별을 보관하려고 한다.
N x M 의 격자가 있으며 각 칸에는 양의 정수가 적혀있다.
첫 번째 열의 원하는 칸에 별을 올려두고, 별이 아래 과정에 따라 이동한다
1. 바라보고 있는 방향으로 별이 놓은 칸에 적힌 수만큼 이동한다.
2. 별이 바라보고 방향이 시계 방향으로 90도 돌아간다.

위의 절차를 계속해서 반복하면서 별이 무한히 격자 안에서 맴돈다면
별을 가둔것이고, 중간에 격자 밖으로 나가면, 별을 가두는데 실패한 것이다.

어느 칸에 별을 올려야 별을 가둘 수 있는지 찾아주자!
'''
'''
모든 첫번째 열에서 탐색을 진행하면 될 것 같은데
일단 해볼까?
'''
# N = 세로 길이, M = 가로 길이
N, M = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]

direction = [(0, 0), (0, 1), (1, 0), (0, -1), (-1, 0)]

catch_star = []

for n in range(N):
    x, y = n, 0
    di = 1
    visited = [[0] * M for _ in range(N)]
    visited[x][y] = 1

    while True:
        nx = x + (direction[di][0] * board[x][y])
        ny = y + (direction[di][1] * board[x][y])

        if 0 <= nx < N and 0 <= ny < M:
            next_di = (di + 1) % 5
            if visited[nx][ny] != 0:
                if visited[nx][ny] == next_di:
                    catch_star.append(n)
                    break
                else:
                    visited[nx][ny] = next_di
                    x = nx
                    y = ny
                    di = next_di
            else:
                visited[nx][ny] = next_di
                x = nx
                y = ny
                di = next_di
        else:
            break

catch_star.sort()
print(len(catch_star))
for c in catch_star:
    print(c+1, end=' ')
