'''
각각의 박스에 시작했을때와 현재 박스 크기를 저장한다.
순회할때 해당 인덱스의 박스가 들어갈 수 있는지를 판단하면 어떨까
'''
'''
뒤에있는 박스중 자기 자신에게 넣을 수 있는 박스들을 비교해 최대값을
본인에게 넣는다?
'''
N = int(input())
boxes = list(map(int, input().split()))

stack_box = [0] * N

for i in range(N):
    if i == 0:
        stack_box[i] = 1
        continue
    else:
        tmp = boxes[i]
        max_box = 1
        for j in range(i):
            if tmp > boxes[j]:
                tmp_box = 1 + stack_box[j]
                if max_box < tmp_box:
                    max_box = tmp_box
        else:
            stack_box[i] = max_box

print(max(stack_box))