'''
상근이는 짱 부자라 집이 있다. 해당 집은 1미터 길이의 정육각형이 붙어있는 상태로 구성되어 있다
상근이는 여자친구를 위해 건물 외벽을 조명으로 장식하려고 한다.
상근이의 집이 주어질때 외벽에 설치하는 조명의 길이(미터)를 구하여라
단, 건물 안쪽의 빈땅 즉, 바깥에서 보이지 않는 벽은 조명을 설치하지 않는다.
'''
'''
정육각형으로 판단하는 bfs? dfs 정도로 생각하면 될것 같은데 구현쪽 느낌이 더강한것 같다.
홀수번째가 오른쪽으로 한칸 들어가있고, 짝수번째가 한칸 왼쪽으로 나와있다.
이걸 유의하면서 하면 될것 같다.
건물로 둘러싸인 땅처리는 어떻게 할까?
건물로 둘러싸인 땅이 꼭 1칸일거라는 보장이 없다 dfs를 이용해서 현재 1에서 모든 이어진 1을 방문하고, 
루프가 생긴다면 해당 땅안에 빈 땅이 들어 있는지 확인한다. 빈 땅이 있는지는 어떻게 확인할까?
건물은 연결되지않은 빈칸을 모두 라인에 더하고 땅일때는 dfs를 돌아 갇힌 땅인지를 판단하고 갇혀있다면 해당 땅이
건물과 인접한 개수만큼 뺀다!
'''
from collections import deque

odd_scan = [(0, 1), (1, 1), (1, 0), (0, -1), (-1, 0), (-1, 1)]
even_scan = [(0, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0)]

# N = 가로길이, M = 세로 길이
N, M = map(int, input().split())

area = [[-1] + list(map(int, input().split())) for _ in range(M)]

area = [[]] + area

lines = 0

visited = [[0] * (N+1) for _ in range(M+1)]

for m in range(1, M+1):
    for n in range(1, N+1):
        if visited[m][n] == 0:
            visited[m][n] = 1
            # 만약 홀수번째 줄이라면 오른쪽으로 한칸 들어간 것으로 판단.
            if area[m][n] == 1:
                if m % 2 == 1:
                    for o in odd_scan:
                        di, dj = o
                        nx = m + di
                        ny = n + dj

                        if 1 <= nx <= M and 1 <= ny <= N:
                            if area[nx][ny] == 0:
                                lines += 1
                        else:
                            lines += 1

                elif m % 2 == 0:
                    for e in even_scan:
                        di, dj = e
                        nx = m + di
                        ny = n + dj

                        if 1 <= nx <= M and 1 <= ny <= N:
                            if area[nx][ny] == 0:
                                lines += 1
                        else:
                            lines += 1

            elif area[m][n] == 0:
                near_buildings = 0
                is_covered = False
                que = deque()
                que.append((m, n))

                while que:
                    tm, tn = que.popleft()
                    if tm % 2 == 1:
                        for o in odd_scan:
                            di, dj = o
                            nx = tm + di
                            ny = tn + dj

                            if 1 <= nx <= M and 1 <= ny <= N:
                                if area[nx][ny] == 1:
                                    near_buildings += 1

                                elif area[nx][ny] == 0:
                                    if visited[nx][ny] == 0:
                                        que.append((nx, ny))
                                        visited[nx][ny] = 1
                            else:
                                is_covered = True

                    elif tm % 2 == 0:
                        for e in even_scan:
                            di, dj = e
                            nx = tm + di
                            ny = tn + dj

                            if 1 <= nx <= M and 1 <= ny <= N:
                                if area[nx][ny] == 1:
                                    near_buildings += 1

                                elif area[nx][ny] == 0:
                                    if visited[nx][ny] == 0:
                                        que.append((nx, ny))
                                        visited[nx][ny] = 1
                            else:
                                is_covered = True

                if is_covered is False:
                    lines -= near_buildings

print(lines)
