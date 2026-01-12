#include <iostream>
#include <vector>

using namespace std;

int M;
vector<long long> N_event(100000), goal_cnt(100000);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> N_event[i];
    }
    for (int i=0; i<M; ++i) {
        cin >> goal_cnt[i];
    }
    
    // 각 상황을 필기하며 보니 특정 규칙성이 있는걸 찾아내었다 해당 규칙은 행사값 n이 있을때
    // n * (구매해야하는 수) = 목표 개수  * (n-1) + 1 (단, 목표 개수  * (n-1) + 1 % n == 0이 아니면 1개추가)
    // 의 식이 성립하는 것을 찾았다.
    // 이외에 예외 조건이 있는데 1+1은 1개만 사도 무한히 가질 수 있기 때문에 1+1은 무조건 1을 출력한다.
    // 또한, 목표 개수보다 행사값이 크면 혜택을 받을 수 없으므로 그냥 목표 개수를 출력하면 된다.
    for (int i=0; i<M; ++i) {
        if (goal_cnt[i] != 0 && N_event[i] == 1) cout << 1 << " ";
        else {
            if (goal_cnt[i] < N_event[i]) cout << goal_cnt[i] << " ";
            else {
                long long tmp = goal_cnt[i] * (N_event[i] - 1ll) + 1ll, result = tmp / N_event[i];
                if (tmp % N_event[i] != 0) result++;
                
                cout << result << " ";
            }
        }
    }
    

    return 0;
}
