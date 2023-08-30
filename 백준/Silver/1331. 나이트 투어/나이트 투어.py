board = [[0] * 6 for _ in range(6)]
visitied = [[0] * 6 for _ in range(6)]
si = 0
sj = 0
ni = 0
nj = 0
di = [1, 1, 2, 2, -1, -1, -2, -2]
dj = [-2, 2, -1, 1, 2, -2, 1, -1]
result = 'Invalid'
for r in range(36):
    if r == 0:
        command = list(input())
        if command[0] == 'A':
            command[0] = 0

        elif command[0] == 'B':
            command[0] = 1

        elif command[0] == 'C':
            command[0] = 2

        elif command[0] == 'D':
            command[0] = 3

        elif command[0] == 'E':
            command[0] = 4

        elif command[0] == 'F':
            command[0] = 5

        si = command[0]
        sj = int(command[1]) - 1

        zi = si
        zj = sj

    else:
        command = list(input())
        if command[0] == 'A':
            command[0] = 0

        elif command[0] == 'B':
            command[0] = 1

        elif command[0] == 'C':
            command[0] = 2

        elif command[0] == 'D':
            command[0] = 3

        elif command[0] == 'E':
            command[0] = 4

        elif command[0] == 'F':
            command[0] = 5

        for z in range(8):
            nzi = zi + di[z]
            nzj = zj + dj[z]
            if 0 <= nzi < 6 and 0 <= nzj < 6:
                if nzi == command[0] and nzj == int(command[1]) - 1:
                    visitied[command[0]][int(command[1])-1] = 1
                    zi = nzi
                    zj = nzj
                    if r == 35:
                        ni = command[0]
                        nj = int(command[1]) - 1

else:
    cnt = 0
    for d in range(8):
        fi = ni + di[d]
        fj = nj + dj[d]

        if 0 <= fi < 6 and 0 <= fj < 6:
            if fi == si and fj == sj:
                visitied[fi][fj] = 1
                for t in range(6):
                    for c in range(6):
                        if visitied[t][c] == 1:
                            cnt += 1

                else:
                    if cnt == 36:
                        result = 'Valid'

print(result)