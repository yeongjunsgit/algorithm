#include <iostream>
#include <vector>

using namespace std;

int N, S, T;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        cin >> S >> T;
        vector<int> get_coin(N+2, 0); 
        vector<vector<int> > dp(T+1, vector<int>(N+2, -20000001) ); 
        for (int i=1; i<=N; ++i) {
            cin >> get_coin[i];
        }
        dp[0][0] = 0;
        
        for (int i=0; i<=N; ++i) {
            for (int j=0; j<T; ++j) {
                if (dp[j][i] == -20000001) continue;
                for (int k=1; k<=S; ++k) {
                    if (j+1 <= T && dp[j+1][min(N+1, i+k)] < dp[j][i] + get_coin[min(N+1, i+k)]) {
                        dp[j+1][i+k] = dp[j][i] + get_coin[min(N+1, i+k)];
                    }
                }
            }
        }
        
        int best_coin = -20000001;
        for (int i=1; i<=T; ++i) {
            best_coin = max(best_coin, dp[i][N+1]);
        }
        cout << best_coin << "\n";
        
    }

    return 0;
}

