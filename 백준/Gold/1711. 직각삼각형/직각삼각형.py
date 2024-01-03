'''
2차원 평면에 N개의 점이 주어져있다. 이 중에서 3개의 점을 골랐을때,
직각삼각형이 되는 경우가 몇개나 있는지 구하여라.
'''
'''
점의 개수는 최대 1500개이다.
직각 삼각형이 되는 경우는? 
기준점과 x좌표가 똑같은점 1개, y좌표가 똑같은 점 1개 이어야한다.
해당 경우를 대각선의 경우도 생각해야 한다.
기울기를 구해야한다...
아니 피타고라스 정리로 간다 시간초과 진짜 너무 화가난다 왜???????????????????????????
이것마저 초과나진 않겠지
'''
import sys
input = sys.stdin.readline


# def search(main, sub1, sub2):
#     tmp_cnt = 0
#     # if main[0] != sub2[0] and main[1] != sub2[1] and main[0] != sub1[0] and main[1] != sub1[1]:
#     tmp_1 = (sub1[0] - main[0], sub1[1] - main[1])
#     tmp_2 = (sub2[0] - main[0], sub2[1] - main[1])
#
#     if tmp_1[0] * tmp_2[0] == 0:
#         if tmp_1[1] * tmp_2[1] == 0:
#             tmp_cnt += 1
#     else:
#         tmp_slope = (tmp_1[1] * tmp_2[1]) / (tmp_1[0] * tmp_2[0])
#
#         if tmp_slope == -1:
#             tmp_cnt += 1
#
#     return tmp_cnt

def patrol():
    global cnt
    for i in range(N-2):
        for j in range(i + 1, N-1):
            for k in range(j + 1, N):
                # 각 좌표간의 길이에서 피타고라스 정리를 이용해 빗변의 값을 구한다 (제곱이 된 상태)
                length_1 = (point[i][0] - point[j][0]) ** 2 + (point[i][1] - point[j][1]) ** 2
                length_2 = (point[i][0] - point[k][0]) ** 2 + (point[i][1] - point[k][1]) ** 2
                length_3 = (point[j][0] - point[k][0]) ** 2 + (point[j][1] - point[k][1]) ** 2

                # 이미 제곱이 되어 있으니 해당 값을 이용하여 피타고라스 정리의 조건에 맞는 경우가 있는지 찾아 있다면 개수 1개 증가
                if length_1 > length_2 and length_1 > length_3:
                    if length_2 + length_3 == length_1:
                        cnt += 1
                        continue
                elif length_2 > length_1 and length_2 > length_3:
                    if length_1 + length_3 == length_2:
                        cnt += 1
                        continue
                elif length_3 > length_1 and length_3 > length_2:
                    if length_1 + length_2 == length_3:
                        cnt += 1
                        continue


# N = 점의 개수
N = int(input())

point = []
cnt = 0
for n in range(N):
    a, b = map(int, input().split())

    point.append((a, b))

patrol()

print(cnt)
