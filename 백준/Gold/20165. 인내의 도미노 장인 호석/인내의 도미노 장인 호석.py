'''
도미노 배틀을 진행한다.
2차원 배열에서 동서남북으로 도미노를 넘어뜨린다.
넘어뜨린 도미노의 높이 -1 만큼 해당 방향으로 모든 도미노가 넘어진다.
도미노의 연쇄작용 또한 있다.
수비팀도 있으며 수비팀은 공격을 진행 한 후 어떤 한 도미노를 다시 일으킨다.
주어지는 보드 판과 각 라운드에서 진행되는 커맨드가 주어질때,
결과를 출력하여라.
'''
'''
구현!
'''


def drop(x, y, d, h):
    global score
    di, dj = command_direction[d]

    for i in range(1, h):
        nx = x + (di * i)
        ny = y + (dj * i)

        if 0 <= nx < N and 0 <= ny < M:
            if up_down[nx][ny] == 'S':
                up_down[nx][ny] = 'F'
                score += 1
                if board[nx][ny] > 1 and i + board[nx][ny] > height-1:
                    drop(nx, ny, d, board[nx][ny])


# N = 세로 길이, M = 가로 길이, R = 라운드 수
N, M, R = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]
up_down = [['S'] * M for _ in range(N)]

command_direction = {'E': (0, 1), 'W': (0, -1), 'S': (1, 0), 'N': (-1, 0)}

score = 0

for r in range(R):
    tax, tay, direction = input().split()
    lx, ly = map(int, input().split())
    ax = int(tax)
    ay = int(tay)

    height = board[ax-1][ay-1]

    if up_down[ax-1][ay-1] == 'S':
        up_down[ax-1][ay-1] = 'F'
        score += 1
        drop(ax-1, ay-1, direction, height)

    if up_down[lx-1][ly-1] == 'F':
        up_down[lx-1][ly-1] = 'S'

print(score)
for j in range(N):
    print(*up_down[j])
