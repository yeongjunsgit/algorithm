'''
재환이는 1xN 크기의 미로에 갇혀있다. 미로는 1x1크기의 칸으로 이루어져 있고, 각 칸에는 정수가 하나 쓰여있다.
i번째 칸에 쓰여 있는 수를 Ai라고 했을 때, 재환이는 Ai이하만큼 오른쪽으로 떨어진 칸으로 한 번에 점프할 수 있다.
예를 들어 현재 위치에 적힌 수가 4라면 해당 칸으로 부터 1, 2, 3, 4 만큼 갈 수 있다.
현재 재환이는 미로의 왼쪽 끝에 있고, 가장 오른쪽 끝 칸으로 가려고 한다. 점프를 최소로 해서 해당 위치로 갈 수
있는 횟수를 구하여라. 만약 갈 수 없다면 -1 을 출력한다.
'''
'''
브루트 포스 같다 백트래킹을 좀 섞으면 될듯?!
'''
from collections import deque

# N = 미로의 크기
N = int(input())

labyrinth = list(map(int, input().split()))

visited = [-1] * N

visited[0] = 0

que = deque()
que.append([0, 0])

while que:
    moved, now = que.popleft()
    next_move = moved + 1
    for n in range(1, labyrinth[now]+1):
        next_node = now + n
        if next_node < N:
            if visited[next_node] == -1:
                visited[next_node] = next_move
                que.append([next_move, next_node])

            else:
                if visited[next_node] > next_move:
                    visited[next_node] = next_move
                    que.append([next_move, next_node])


print(visited[N-1])
