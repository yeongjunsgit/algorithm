from collections import deque

N, X = map(int, input().split())

arr = list(map(int, input().split()))
check = deque()

for x in range(X):
    check.append(arr[x])

cnt = 1

max_lis = sum(check)
tmp_lis = max_lis

for i in range(X, N):
    k = check.popleft()
    check.append(arr[i])
    if k > arr[i]:
        tmp_lis -= k
        tmp_lis += arr[i]
        continue
    else:
        tmp_lis -= k
        tmp_lis += arr[i]
        if max_lis < tmp_lis:
            max_lis = tmp_lis
            cnt = 1
        elif max_lis == tmp_lis:
            cnt += 1

if max_lis == 0:
    print('SAD')
else:
    print(max_lis)
    print(cnt)