def perm(i, N):
    global cnt
    if i == N:
        if p[i - 1] == p[i - 2] == p[i - 3]:
            return
        score = 0
        for q in range(10):
            if arr[q] == p[q]:
                score += 1
        else:
            if score >= 5:
                cnt += 1

    else:
        if i < 3:
            for j in range(1, 6):
                p[i] = j
                perm(i + 1, N)
                p[i] = 0

        elif i >= 3:
            if p[i-1] == p[i-2] == p[i-3]:
                return
            else:
                for j in range(1, 6):
                    p[i] = j
                    perm(i + 1, N)
                    p[i] = 0

arr = list(map(int, input().split()))
cnt = 0
p = [0] * 10

perm(0, 10)

print(cnt)