'''
홍준이는 소트 게임을 하려고 한다. 소트 게임은 1부터 N까지 정수로 이루어진 N자리의 순열을 이용한다.
이 게임에선 K가 주어진다. 어떤 수를 뒤집으면 그 수로부터 오른쪽으로 K개의 수를 뒤접어야 한다.
예를 들어, 순열이 5 4 3 2 1 이었고, K가 3일 때, 4를 뒤집으면 5 2 3 4 1이 된다. 반드시 K개의 수를
뒤집어야 하기 때문에, 처음 상태에서 2나 1을 선택하는 것은 불가능하다.

입력으로 들어온 순열을 오름차순으로 만들려고 한다. 게임을 최대한 빨리 끝내고 싶을 때, 수를 최소 몇개
선택해야 하는지 구해보자!
'''
'''
...? 대체 뭔 문제일까
브루트 포스부터 해보자??? 아니 되나 이게...?
N이 2 <= N <= 8 정도라서 잘하면 될수도 있긴한데...
그리디 같기도 하고? 일단... 해보자
근데 안되는 경우는 -1을 출력해야 하는데... 어떻게 안되는 경우를 판단할까?
딕셔너리에 여태 나왔던 경우의 수를 저장해서 또 나오면 pq에 넣지 말자!
'''
import heapq


def switch(arr, idx, moving):
    tmp_arr = arr.copy()
    tmp_idx = idx
    for a in range(idx+K-1, idx-1, -1):
        tmp_arr[a] = arr[tmp_idx]
        tmp_idx += 1

    key_word = ''.join(tmp_arr)

    if key_word not in answer_dict:
        answer_dict[key_word] = 1
        heapq.heappush(pq, [moving, tmp_arr])


# N = 순열의 크기, K = 한번에 뒤집히는 길이
N, K = map(int, input().split())

arr = list(input().split())
answer = sorted(arr)
cnt = -1
answer_dict = {}
pq = []
heapq.heappush(pq, [0, arr])

while pq:
    moved, now_arr = heapq.heappop(pq)

    if answer == now_arr:
        cnt = moved
        break

    for i in range(N-K+1):
        switch(now_arr, i, moved+1)

print(cnt)
