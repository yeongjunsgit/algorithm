'''

영재는 심마니다. 현재산에 있는 강가에 있는 돌무더기 끝에 산삼이 있다는 첩보를 얻었다.

영재는 돌무더기를 점프하여 건너려고 한다

영재는 점프, 수퍼점프, 필살 하이퍼점프가 있다.

점프와 수퍼점프는 각각 돌무더기의 위치에 따라 소모하는 에너지가 다르다

필살 하이퍼점프는 탐색 중 단 한번만 사용할 수 있으며 K만큼의 에너지를 소모한다.

영재가 산삼까지 도달하기위해 최소로 에너지를 소모하는 경우의 값을 구하여라

'''

'''

visited 에 현재 위치에 도달하기 소모한 에너지를 기록하자!

단, 하이퍼점프는 단 한번만 쓸 수 있으니

따로 배열을 만들어 관리하자

그럼 될듯!?

'''

def jump(now, now_cost, ishyper):

    normal, super = cost[now]

    

    if now + 1 <= N:

        normal_cost = now_cost + normal

        if ishyper is False:

            if visited[now + 1] > normal_cost:

                visited[now+1] = normal_cost

                

        else:

            if use_hyper[now+1] > normal_cost:

                use_hyper[now+1] = normal_cost

                

    if now + 2 <= N:

        super_cost = now_cost + super

        if ishyper is False:

            if visited[now + 2] > super_cost:

                visited[now + 2] = super_cost

                

        else:

            if use_hyper[now + 2] > super_cost:

                use_hyper[now + 2] = super_cost

                

    if ishyper is False:

        if now + 3 <= N:

            hyper_cost = now_cost + K

            

            if use_hyper[now+3] > hyper_cost:

                use_hyper[now+3] = hyper_cost

          

# N = 돌 무더기의 개수

N = int(input())

visited = [int(1e9)] * (N+1)

use_hyper = [int(1e9)] * (N+1)

cost = [[] for _ in range(N)]

for n in range(1, N):

    a, b = map(int, input().split())

    cost[n] = [a, b]

K = int(input())

visited[1] = 0

for i in range(1, N):

    jump(i, visited[i], False)

    jump(i, use_hyper[i], True)

result = min(visited[N], use_hyper[N])

print(result)

