'''
피타고라스의 법칙 구현?
'''
import math

while True:
    l1, l2, l3 = map(int, input().split())
    if l1 == l2 == l3 == 0:
        break

    line_lis = [l1, l2, l3]
    max_l = max(l1, l2, l3)
    line_lis.remove(max_l)

    tmp_big = max_l ** 2
    another_line = 0
    for l in line_lis:
        another_line += l**2

    if tmp_big == another_line:
        print('right')
        
    else:
        print('wrong')
