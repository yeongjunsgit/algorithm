N = int(input())
M = int(input())
arr = list(map(int, input().split()))

in_list = []
cnt = 1
for i in arr:
    if len(in_list) != N:
        for j in range(len(in_list)):
            if in_list[j][0] == i:
                in_list[j][1] += 1
                break
        else:
            in_list.append([i, 1, cnt])
            cnt += 1

    else:
        for j in range(len(in_list)):
            if in_list[j][0] == i:
                in_list[j][1] += 1
                break
        else:
            min_vote = M + 1
            min_idx = -1
            min_cnt = 0
            for k in range(len(in_list)-1, -1, -1):
                if min_vote >= in_list[k][1]:
                    if min_vote > in_list[k][1]:
                        min_vote = in_list[k][1]
                        min_idx = k
                        min_cnt = in_list[k][2]

                    else:
                        if min_cnt > in_list[k][2]:
                            min_idx = k
                            min_cnt = in_list[k][2]
            else:
                in_list[min_idx] = [i, 1, cnt]
                cnt += 1

result = []
for r in range(len(in_list)):
    result.append(in_list[r][0])

result.sort()

print(*result)