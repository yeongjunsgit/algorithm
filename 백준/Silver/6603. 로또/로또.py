import sys
input = sys.stdin.readline
# print = sys.stdout.write

def perm(s, F, N):
    if s == F:
        tmp = p.copy()
        table.append(tmp)
        return

    else:
        for i in range(N):
            if used[i] == 0:
                if s != 0:
                    if numbers[i] > p[s-1]:
                        p[s] = numbers[i]
                        used[i] = 1
                        perm(s+1, F, N)
                        used[i] = 0
                else:
                    p[s] = numbers[i]
                    used[i] = 1
                    perm(s + 1, F, N)
                    used[i] = 0
while True:
    lotto = list(map(int, input().split()))

    if lotto == [0]:
        break
    else:
        k = lotto[0]
        numbers = []
        for n in range(1, k+1):
            numbers.append(lotto[n])

    p = [0] * 6
    used = [0] * k
    table = []
    perm(0, 6, len(numbers))

    for r in range(len(table)):
        print(*table[r])
    print()