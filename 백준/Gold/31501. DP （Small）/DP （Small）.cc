#include <iostream>
#include <vector>

using namespace std;

int N, Q, command;
vector<int> difficult_rate(3001), left_power(3001, 1), right_power(3001, 1);


void connect_root()
{
    for (int i=2; i<=N; ++i) {
        int best_pick = 0;
        for (int j=i-1; j>0; --j) {
            if (difficult_rate[i] > difficult_rate[j]) {
                best_pick = max(best_pick, left_power[j]);
                // cout << "현재 나는 " << i << "이고, 지금 힘은 " << left_power[j] << "이고, 현재 최대는 " << best_pick << "이야\n";
            }
        }
        left_power[i] += best_pick;
    }
    
    for (int i=N-1; i>=1; --i) {
        int best_pick = 0;
        for (int j=i+1; j<=N; ++j) {
            if (difficult_rate[i] < difficult_rate[j]) {
                best_pick = max(best_pick, right_power[j]);
                // cout << "현재 나는 " << i << "이고, 지금 힘은 " << right_power[j] << "이고, 현재 최대는 " << best_pick << "이야\n";
            }
        }
        right_power[i] += best_pick;
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i=1; i<=N; ++i) {
        cin >> difficult_rate[i];
    }

    connect_root();
    
    for (int i=0; i<Q; ++i) {
        cin >> command;
        cout << left_power[command] + right_power[command] - 1 << "\n";
    }
    
    return 0;
}
