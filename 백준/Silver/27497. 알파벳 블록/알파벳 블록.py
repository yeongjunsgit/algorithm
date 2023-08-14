import sys
input = sys.stdin.readline
print = sys.stdout.write
from collections import deque

T = int(input())

make_word = deque()
stack_num = [0]

for tc in range(1, T+1):
    C = input().split()
    if C[0] == '1':
        stack_num.append('1')
        make_word.append(C[1])

    elif C[0] == '2':
        make_word.appendleft(C[1])
        stack_num.append('2')

    elif C[0] == '3':
        if stack_num[-1] == '2':
            make_word.popleft()
            stack_num.pop()

        elif stack_num[-1] == '1':
            make_word.pop()
            stack_num.pop()

if make_word:
    print(''.join(make_word))

else:
    print('0')