'''
숫자 9개가 있을때, 해당 값을 오름차순이나 내림차순으로 정렬한 값의 5번째 있는 숫자를 중앙값이라고 한다.
이미지 I는 R x C인 2차원 픽셀이다. 각 픽셀에는 어두운 정도 V값이 적혀있다.
필터는 이미지에 있는 노이즈를 제거하는 필터이다. 필터의 크기는 3 x 3 이고, 이미지의 중앙값을 찾으면서 잡음을 제거한다.
이렇게 필터링 하면서 중앙값을 찾아갈 때, 주어지는 T값보다 크거나 같은 픽셀 값을 가지는 중앙값의 개수를 구하여라!
'''
'''
필터링을 구현한 후 단순 순회 하여 브루트 포스 돌리면 될듯??
'''


def filtering(x, y):
    tmp_cnt = 0
    tmp_lis = [image[x][y]]

    for e in range(8):
        di, dj = directions[e]
        nx = x + di
        ny = y + dj

        if 0 <= nx < R and 0 <= ny < C:
            tmp_lis.append(image[nx][ny])

    tmp_lis.sort()
    middle = tmp_lis[4]

    if middle >= T:
        tmp_cnt = 1

    return tmp_cnt


directions = [(0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]

# R = 세로 길이, C = 가로 길이
R, C = map(int, input().split())

image = [list(map(int, input().split())) for _ in range(R)]

T = int(input())

cnt = 0

for i in range(1, R-1):
    for j in range(1, C-1):
        cnt += filtering(i, j)

print(cnt)
