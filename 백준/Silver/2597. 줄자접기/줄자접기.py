N = int(input())
color = []
for c in range(3):
    s, e = map(int, input().split())
    color.append([min(s, e), max(s, e)])

for i in range(3):
    x, y = color[i]
    if x == y:
        continue

    mid = (x + y) / 2

    if N - mid <= mid:
        N = mid
        for j in range(i, 3):
            left, right = color[j]
            if mid < left:
                left = mid - (left - mid)

            if mid < right:
                right = mid - (right - mid)

            color[j] = (min(left, right), max(left, right))
    else:
        N -= mid
        for k in range(i + 1, 3):
            left, right = color[k]

            left = mid - left if left < mid else left - mid

            right = mid - right if right < mid else right - mid

            color[k] = (min(left, right), max(left, right))

print(N)
