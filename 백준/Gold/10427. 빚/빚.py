'''
민균이는 빚을 갚아야 한다. 최근 1~4000번 돈을 빌렸고 해당 돈들의 액수가 주어진다.
돈을 갚을때에는 랜덤하게 숫자를 몇개 정하여 정해진 숫자들중 가장 큰값에 정한 숫자들의 개수를 곱한 값에
모든 정해진 숫자들을 다 더한 값을 뺀 값을 추가적으로 갚아야한다
민균이는 해당 값을 최소로 갚고싶다.
1~N번까지의 숫자를 정했을 때 각각의 경우에서 발생하는 모든 최소값을 더했을 때의 값을 구하라
'''
'''
처음 생각나는건 수열 or 조합 근디 4000개라서 터질수도 있을 것 같은데
가장 작은 값을 어떻게 구해야할까?
수열 조합으로하면 무조건 터질듯?
dp 아니면 슬라이딩 윈도우 같은데 슬라이딩 윈도우는 무리같다 꼭 연속된 값을 가지는게 아니니까
흠 dp로 하기도 좀 애매한게 같은 값이 나오면 해당 값은 0이된다. 그 후 다음 값을 생각하려면 가장 가까운
값을 찾아야하는데 이게 될까?
이분탐색? 흠 이분탐색을 한다면 어떻게 해야할까?
이것도 구간자체가 연속되지 않는데 흠
정렬? 정렬하고 슬라이딩 윈도우 한다?
나쁘지 않을지도?
'''
from collections import deque

# T = 테스트 케이스의 개수
T = int(input())

for tc in range(1, T+1):
    arr = list(map(int, input().split()))
    N = arr[0]
    arr.pop(0)
    arr.sort()
    result = 0
    for n in range(2, N+1):
        min_cost = int(2e9)
        que = deque()
        for a in range(n):
            que.append(arr[a])

        idx = n
        all_cost = sum(que)

        while idx != N+1:
            tmp = que[-1]
            now_cost = (tmp * n) - all_cost
            if now_cost == 0:
                min_cost = 0
                break
            else:
                if min_cost > now_cost:
                    min_cost = now_cost

            ex = que.popleft()
            all_cost -= ex
            if idx < N:
                que.append(arr[idx])
                all_cost += arr[idx]
            idx += 1

        result += min_cost

    print(result)
