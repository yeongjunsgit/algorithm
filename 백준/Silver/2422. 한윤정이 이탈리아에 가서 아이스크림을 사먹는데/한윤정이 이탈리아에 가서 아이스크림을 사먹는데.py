'''
윤정이와 친구들은 이탈리아로 방학 여행을 갔다. 이탈리아는 덥다.
그래서 윤정이와 친구들은 아이스크림을 사먹기로 했다. 아이스크림 가게에는 N종류의 아이스크림이 있다.
모든 아이스크림은 1부터 N까지 번호가 매개져있다.
어떤 종류의 아이스크림을 함께 먹으면, 맛이 아주 형편없어진다. 따라서 윤정이는 이러한 경우를 피하면서
아이스크림을 3가지 선택하려고 한다. 이때, 선택하는 방법이 몇 가지인지 구하려고 한다.
'''
'''
서로 연결되지 않은 3개의 조합이 몇개인지를 구하라는 문제인 것 같은데??
'''
def perm(arr, banned, moved):
    global cnt
    if moved == 3:
        cnt += 1
        return

    for j in range(1, N+1):
        if j not in arr and j not in banned and visited[j] == 0:
            new_banned = banned.union(graph[j])
            new_arr = arr + [j]

            perm(new_arr, new_banned, moved+1)


# N = 아이스크림의 수, M = 먹으면 안되는 조합의 수
N, M = map(int, input().split())

graph = [set() for _ in range(N+1)]

cnt = 0

for m in range(M):
    s, e = map(int, input().split())

    graph[s].add(e)
    graph[e].add(s)

visited = [0] * (N+1)

for i in range(1, N+1):
    visited[i] = 1
    perm([i], graph[i], 1)

print(cnt // 2)
