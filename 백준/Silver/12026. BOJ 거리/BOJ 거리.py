'''
보도블록이 있다.
해당 보도블록 위에는 'B', 'O', 'J'가 적혀있다.
맨 처음보도 블록은 무조건 B 가 적혀있고, B->O->J 순서대로 밟아서 끝까지 도착하려고 한다.
점프를 해서 다음 칸으로 넘어갈 수 있는데, 한 번 k칸 만큼 점프하면 k*k만큼의 에너지를 소모한다.
이럴때, N번째 블록에 도착 할 수 있는 경우의 최소 소모 에너지 값을 구하시오.
단, N번째 블록까지 도착할 수 없다면, -1을 출력한다.
'''
'''
DP?
'''
# N = 보도블럭의 길이
N = int(input())

block = list(input())

visited = [int(1e9)] * N
visited[0] = 0

for i in range(N):
    if visited[i] != int(1e9):
        if block[i] == 'B':
            idx = i+1
            while idx < N:
                if block[idx] == 'O':
                    tmp = idx - i
                    if (tmp ** 2) + visited[i] < visited[idx]:
                        visited[idx] = visited[i] + (tmp ** 2)
                idx += 1

        elif block[i] == 'O':
            idx_2 = i+1
            while idx_2 < N:
                if block[idx_2] == 'J':
                    tmp = idx_2 - i
                    if (tmp ** 2) + visited[i] < visited[idx_2]:
                        visited[idx_2] = visited[i] + (tmp ** 2)
                idx_2 += 1

        elif block[i] == 'J':
            idx_3 = i+1
            while idx_3 < N:
                if block[idx_3] == 'B':
                    tmp = idx_3 - i
                    if (tmp ** 2) + visited[i] < visited[idx_3]:
                        visited[idx_3] = visited[i] + (tmp ** 2)
                idx_3 += 1

if visited[N-1] != int(1e9):
    print(visited[N-1])

elif visited[N-1] == int(1e9):
    print('-1')
