#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int> > can_money, need_time;

void make_dp()
{
    vector<vector<int> > DP(N, vector<int>(M+1, -1));
    if (need_time[0].first <= M) DP[0][need_time[0].first] = max(DP[0][need_time[0].first], can_money[0].first);
    if (need_time[0].second <= M) DP[0][need_time[0].second] = max(DP[0][need_time[0].second], can_money[0].second);
    int result = 0;
    
    for (int i=1; i<N; ++i) {
        pair<int, int> now_money = can_money[i];
        pair<int, int> now_time = need_time[i];
        
        for (int j=0; j<=M; ++j) {
            if (j - now_time.first >= 0 && DP[i-1][j - now_time.first] != -1) {
                DP[i][j] = max(DP[i][j], DP[i-1][j - now_time.first] + now_money.first);
            }
            if (j - now_time.second >= 0 && DP[i-1][j - now_time.second] != -1) {
                DP[i][j] = max(DP[i][j], DP[i-1][j - now_time.second] + now_money.second);
            }
        }
    }
    
    for (int i=0; i<=M; ++i) {
        result = max(result, DP[N-1][i]);
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    can_money.resize(N + 1); need_time.resize(N + 1);
    int t1, m1, t2, m2;
    
    for (int i=0; i<N; ++i) {
        cin >> t1 >> m1 >> t2 >> m2;
        can_money[i] = {m1, m2};
        need_time[i] = {t1, t2};
    }
    
    make_dp();

    return 0;
}
