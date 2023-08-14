# 1. try, expect를 이용한다.
# 2. 끝까지 다지우면 , YES
# 3. 도중에 못지우면,  No

T = int(input())

for tc in range(1, T+1):
    arr = list(input())
    N = len(arr)
    stack = [0] * N
    top = -1
    result = 'YES'

    # 순회하면서 열린 괄호는 스택에 넣고, 닫힌 괄호는 스택에 열린 괄호가 있다면 top -1하고, 열린괄호가 없다면 NO를 출력
    for i in range(N):
        if arr[i] == ')':
            if stack[top] == '(':
                top -= 1
            else:
                result = 'NO'
                break

        elif arr[i] == '(':
            top += 1
            stack[top] = arr[i]
    # 만약 순회가 끝난후 모든 스택을 제거하지 못했다면, NO 반환
    else:
        if top != -1:
            result = 'NO'

    # 결과출력
    print(result)

