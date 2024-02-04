'''
그냥 순열을 돌리면 될까나
그런데 숫자를 주면 뒤에서 부터 연산해주는 프로그램으로짜면 최적화가 잘될것 같은데
그냥 순열던지면 터지겠다...
위의 방법으로 풀어야할듯!
숫자일때, 순열일때를 구하는 함수를 만들자!
사전순과  1부터N까지의 특징을  이용하며ㆍ
순서를 예상할 수 있다!
'''


def find_arr(num):
    used = set()
    for u in range(1, N+1):
        used.add(u)
    tmp_arr = [0] * N

    for i in range(N):
        now_num = min(used)
        if num > factorials[N-1-i] and N-1-i != 0:
            while num > factorials[N-1-i]:
                num -= factorials[N-1-i]
                while True:
                    now_num += 1
                    if now_num in used:
                        break

        if now_num in used:
            tmp_arr[i] = now_num
            used.discard(now_num)
        else:
            while True:
                now_num += 1
                if now_num in used:
                    break
            tmp_arr[i] = now_num
            used.discard(now_num)

    return tmp_arr


def find_num(arr):
    used = set()
    for u in range(1, N+1):
        used.add(u)
    tmp_num = 1

    for j in range(N):
        for k in range(1, arr[j]):
            if k in used:
                tmp_num += factorials[N-1-j]

        else:
            used.discard(arr[j])

    return [tmp_num]


N = int(input())

question = list(map(int, input().split()))

command = question[0]
content = question[1:]

if N > 1:
    factorials = [0] * N
    factorials[1] = 1

    for f in range(2, N):
        factorials[f] = factorials[f-1] * f

    result = 0

    if command == 1:
        result = find_arr(content[0])
    elif command == 2:
        result = find_num(content)

    print(*result)

else:
    print("1")
