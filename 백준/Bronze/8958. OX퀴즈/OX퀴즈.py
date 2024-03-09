T = int(input())

for tc in range(1, T+1):
    test = list(input())

    result = 0
    chain = 0
    for t in test:
        if t == "O":
            result += (1 + chain)
            chain += 1

        if t == "X":
            chain = 0

    print(result)
