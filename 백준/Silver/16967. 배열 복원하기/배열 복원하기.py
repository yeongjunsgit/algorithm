'''
H x W인 배열 A 와  (H+X) x (W+Y)인 배열 B 가 있다
배열 B는 배열 A와 배열 A를 아래로 X칸, 오른쪽으로 Y칸 이동시킨 배열을 겹쳐 만든 것이다.
수는 겹쳐지만 수가 합쳐진다.
즉, 배열 B에 들어있는 값을 아래 3개중 하나이다.
1. A와 이동한 A 둘다 해당하지 않는 값은 0이다.
2. 두개의 배열에 해당하면 두 값을 합한 값이다.
3. 두 배열 중 하나만 해당하면 해당 배열의 값이다.

이렇다 할때, 배열 B가 주어진다면 배열 A를 구하는 프로그램을 작성하라
'''
'''
뭐라하긴 애매한데 그냥 구현 같기도하네 안되려나?
주어진 A의 크기를 0,0부터 시작하여 그 이후에 0이 아닌 값이 나오는 기점을 x 값, y 값을 저장하고
그 기점을 기준으로 겹치는 부분은 기존 A의 0,0부터 더해주면 되려나?
'''
# N = 세로길이, M = 가로 길이, X = 아래로 이동하는 칸 수, Y = 오른쪽으로 이동하는 칸 수
N, M, X, Y = map(int, input().split())

arr_B = [list(map(int, input().split())) for _ in range(N+X)]

arr_A = [[0] * M for _ in range(N)]

for i in range(N):
    for j in range(M):
        if X <= i < N and Y <= j < M:
            tmp = arr_B[i][j] - arr_A[i-X][j-Y]
            arr_A[i][j] = tmp

        else:
            arr_A[i][j] = arr_B[i][j]

for k in range(N):
    print(*arr_A[k])
