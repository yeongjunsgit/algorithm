'''
확인해야 할것
1. 종료조건인가?
종료조건 : 게임판이 꽉찼을때, 누군가 승리조건을 달성 했을때,

2. 올바르게 종료되었는가?
X가 먼저 놓는 상황이 맞는가? (놓은 개수가 홀수이면 X가 무조건 1개 더 많아야 한다)
누군가 이겼는가? (판이 꽉차지 않고 끝났는데 아무도 이기지 않았으면 실패)

'''
# 8방향으로 가자!
go = [[0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1]]


while True:
    super_board = []
    result = 'valid'
    case = input()
    match = False
    X_win = False
    O_win = False
    if case == 'end':
        break
    else:
        board = list(case)

        for i in range(0, 9, 3):
            tmp = [board[i], board[i+1], board[i+2]]
            super_board.append(tmp)

        X_lis = []
        O_lis = []

        for j in range(3):
            for k in range(3):
                if super_board[j][k] == 'X':
                    X_lis.append([j, k])

                elif super_board[j][k] == 'O':
                    O_lis.append([j, k])

        use_X = len(X_lis)
        use_O = len(O_lis)
        used = use_O + use_X

        if used % 2 == 0:
            if use_X != use_O:
                result = 'invalid'

        elif used % 2 == 1:
            if use_X != use_O + 1:
                result = 'invalid'

        if result != 'invalid':
            can_over = False
            for x in X_lis:
                bx, by = x[0], x[1]
                for g in range(8):
                    tx, ty = go[g][0], go[g][1]
                    nx = bx + tx
                    ny = by + ty
                    if 0 <= nx < 3 and 0 <= ny < 3 and super_board[nx][ny] == 'X':
                        nnx = nx + tx
                        nny = ny + ty
                        if 0 <= nnx < 3 and 0 <= nny < 3 and super_board[nnx][nny] == 'X':
                            match = True
                            if can_over is False and used % 2 == 1:
                                can_over = True
                                X_win = True

            for o in O_lis:
                bx, by = o[0], o[1]
                for g in range(8):
                    tx, ty = go[g][0], go[g][1]
                    nx = bx + tx
                    ny = by + ty
                    if 0 <= nx < 3 and 0 <= ny < 3 and super_board[nx][ny] == 'O':
                        nnx = nx + tx
                        nny = ny + ty
                        if 0 <= nnx < 3 and 0 <= nny < 3 and super_board[nnx][nny] == 'O':
                            match = True
                            if can_over is False and used % 2 == 0:
                                can_over = True

                            if X_win is True:
                                can_over = False
                                result = 'invalid'

            if can_over is False:
                if used == 9 and use_X == 5 and use_O == 4:
                    if match is False:
                        result = 'valid'
                    else:
                        result = 'invalid'
                else:
                    result = 'invalid'

        print(result)
