'''
1부터 N까지의 수를 오름차순으로 쓴 수열이 있다.
해당 수 안에 '+', '-', ' '(공백)을 숫자 사이에 삽입하자 (공백은 숫자를 서로 이어 붙이는것을 뜻한다.)
그렇게 만든 수식의 결과 값이 0이 되도록 하는 모든 수식을 찾는 프로그램을 작성하라!
'''
'''
생각해보자 0이 되려면 x-y = 0 즉, x = y가 되는 조건을 만족해야 한다.
흠...... 근데 수끼리 연결이 가능한게 킹받는데
어케 풀어야할까?
그냥 경우의수 브루트포스 돌려버려?
'''
import heapq


def perm(s):
    if s == N:
        tmp_sum = arr[0]
        for i in range(len(pq)):
            # 연산자가 - 면
            if pq[i] == '-':
                # 해당 연산자의 뒤따라오는 연산자가 공백인지 확인
                if i + 1 < len(pq):
                    if pq[i+1] == ' ':
                        # 공백이면 두숫자를 이어주고 다음 연산자도 공백인지 확인
                        tmp = arr[i+1] * 10 + arr[i+2]

                        idx = 2
                        while True:
                            if i + idx < len(pq):
                                if pq[i + idx] == ' ':
                                    tmp = tmp * 10 + arr[i + idx + 1]
                                    idx += 1
                                # 다음 연산자가 공백이 아니라면 탈출
                                else:
                                    break
                            else:
                                break
                    else:
                        tmp = arr[i + 1]
                else:
                    tmp = arr[i + 1]

                tmp_sum -= tmp

            elif pq[i] == '+':
                if i + 1 < len(pq):
                    # 해당 연산자의 뒤따라오는 연산자가 공백인지 확인
                    if pq[i + 1] == ' ':
                        # 공백이면 두숫자를 이어주고 다음 연산자도 공백인지 확인
                        tmp = arr[i + 1] * 10 + arr[i + 2]

                        idx = 2
                        while True:
                            if i + idx < len(pq):
                                if pq[i + idx] == ' ':
                                    tmp = tmp * 10 + arr[i + idx + 1]
                                    idx += 1
                                # 다음 연산자가 공백이 아니라면 탈출
                                else:
                                    break
                            else:
                                break
                    else:
                        tmp = arr[i + 1]
                else:
                    tmp = arr[i + 1]

                tmp_sum += tmp

            elif pq[i] == ' ':
                if i == 0:
                    tmp_sum = 0
                    tmp = arr[i] * 10 + arr[i + 1]
                    idx = 1
                    while True:
                        if i + idx < len(pq):
                            if pq[i + idx] == ' ':
                                tmp = tmp * 10 + arr[i + idx + 1]
                                idx += 1
                            # 다음 연산자가 공백이 아니라면 탈출
                            else:
                                break
                        else:
                            break

                    tmp_sum += tmp

        if tmp_sum == 0:
            tmp_word = ''
            for a in range(N):
                tmp_word += str(arr[a])
                if a != N-1:
                    tmp_word += pq[a]
            heapq.heappush(make_list, tmp_word)

    else:
        pq.append(' ')
        perm(s+1)
        pq.pop()
        pq.append('-')
        perm(s+1)
        pq.pop()
        pq.append('+')
        perm(s+1)
        pq.pop()


T = int(input())

for tc in range(1, T+1):
    N = int(input())
    arr = []
    for n in range(1, N+1):
        arr.append(n)

    pq = []
    make_list = []
    perm(1)

    while make_list:
        word = heapq.heappop(make_list)
        print(word)
    print()

