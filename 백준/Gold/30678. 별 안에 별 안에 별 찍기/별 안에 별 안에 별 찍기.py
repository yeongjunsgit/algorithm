'''
별안에 별을 찍어야한다... 주어지는 패턴대로 별을 만들어야하며
N - 1의 별의 크기로 주어지는 패턴을 찍어내야 한다.
'''
'''
흠... 어렵네 어떻게 해야할까?
일단 구현 아닐까?
'''

def star_location(num, line):
    blank_size = size[num - 1]
    my_line = line % (size[num])
    if num == 1:
        if my_line == 1 or my_line == 2:
            print(' ' * (blank_size * 2), end='')
            print('*', end='')
            print(' ' * (blank_size * 2), end='')

        elif my_line == 3:
            print('*****', end='')

        elif my_line == 4:
            print(' ' * blank_size, end='')
            print('***', end='')
            print(' ' * blank_size, end='')
        elif my_line == 0:
            print(' ' * blank_size, end='')
            print('*', end='')
            print(' ' * blank_size, end='')
            print('*', end='')
            print(' ' * blank_size, end='')

    else:
        if 0 < my_line <= (blank_size * 2):
            print(' ' * (blank_size * 2), end='')
            star_location(num-1, line)
            print(' ' * (blank_size * 2), end='')

        elif (blank_size * 2) < my_line <= (blank_size * 3):
            for b in range(5):
                star_location(num-1, line)

        elif (blank_size * 3) < my_line <= (blank_size * 4):
            print(' ' * blank_size, end='')
            for l in range(3):
                star_location(num-1, line)
            print(' ' * blank_size, end='')

        elif (blank_size * 4) < my_line <= (blank_size * 5) or my_line == 0:
            print(' ' * blank_size, end='')
            star_location(num-1, line)
            print(' ' * blank_size, end='')
            star_location(num-1, line)
            print(' ' * blank_size, end='')


# N = 별의 크기
N = int(input())
if N == 0:
    print('*')

else:
    size = [0] * (N+1)

    for n in range(N+1):
        size[n] = 5 ** n

    for i in range(1, size[N]+1):
        star_location(N, i)
        print()
