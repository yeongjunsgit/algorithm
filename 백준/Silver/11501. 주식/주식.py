T = int(input())

for tc in range(1, T+1):
    N = int(input())
    arr = list(map(int, input().split()))
    earn_money = 0
    max_price = arr[-1]
    for i in range(N-2, -1, -1):
        if arr[i] < max_price:
            earn_money += (max_price - arr[i])

        elif arr[i] > max_price:
            max_price = arr[i]

    print(earn_money)