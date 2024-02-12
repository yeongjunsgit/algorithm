'''
직선상의 좌표에 점 들이 있다.
각 점들은 색깔을 가지고 있다.
현재 점에서 같은 색깔을 가진 가장 가까운 점으로 화살표를 그린다.
이럴 때 모든 화살표의 길이를 구하여라.
'''
'''
브루트 포스로 될거같은데?!
'''

# N = 점의 개수
N = int(input())

color_dict = {}

for n in range(N):
    point, color = map(int, input().split())
    if color not in color_dict:
        color_dict[color] = [point]

    else:
        color_dict[color].append(point)

result = 0

for i in range(1, N+1):
    if i in color_dict:
        color_dict[i].sort()
        for c in range(len(color_dict[i])):
            previous_node = c-1
            next_node = c+1
            arrow_point = int(1e9)

            if 0 <= previous_node < len(color_dict[i]):
                tmp = abs(color_dict[i][previous_node] - color_dict[i][c])
                if tmp < arrow_point:
                    arrow_point = tmp

            if 0 <= next_node < len(color_dict[i]):
                tmp_2 = abs(color_dict[i][next_node] - color_dict[i][c])
                if tmp_2 < arrow_point:
                    arrow_point = tmp_2

            if arrow_point != int(1e9):
                result += arrow_point

print(result)
