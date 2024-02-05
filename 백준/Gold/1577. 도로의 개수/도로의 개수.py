'''
M * N 모양의 도시가 있다! 세준이는 0,0에서 살고있고, 학교는 M,N에 있다
세준이는 집에서 학교를 갈 수있는 루트가 몇개나 되는지 궁금하다!
단, 현재 도시에서 공사가 이루어지고 있어서, 공사 중인 길로는 지나갈 수가 없다!
이 점을 고려하여 개수를 구하자!
'''
'''
모든 루트를 구해야한다니까 아무래도 DFS 같은데?!
K도 50개 정도 주어진다니까 흠 괜찮을거 같은데?!
들린 도시 개수가 반드시 N+M이어야 한다고 한다...
그럼 bfs해야하나?
100 * 100인데 이거 bfs 돌리면 억겁의 시간이 걸려서 돌아갈 수도 있을것 같다.
그냥 dfs도 아님 이건 그냥 각 도로를 보고 발생하는 경우의수를 따져야할것 같다
어느 지점에 도착했을때 아무 도로도 막혀있지 않다면 현재 도달한 경우의 수의 다음 위치에 더한다.
만약 도로가 다 막혀있다면 해당 위치에서의 순회는 종료, 개수는 한개도 못 가진다.
이런 식으로 보면 될것 같은데?
'''

# N = 가로 길이, M = 세로 길이
N, M = map(int, input().split())

city = [[0] * (N+1) for _ in range(M+1)]
in_progress = set()
direction = [(0, 1), (1, 0)]

K = int(input())

for k in range(K):
    x1, y1, x2, y2 = map(int, input().split())
    in_progress.add((y1, x1, y2, x2))
    in_progress.add((y2, x2, y1, x1))

for i in range(M+1):
    for j in range(N+1):
        for t in range(2):
            di, dj = direction[t]
            nx = i + di
            ny = j + dj

            if 0 <= nx < M+1 and 0 <= ny < N+1:
                if (i, j, nx, ny) not in in_progress:
                    if i == 0 and j == 0:
                        city[nx][ny] = 1
                    else:
                        city[nx][ny] += city[i][j]

print(city[M][N])
