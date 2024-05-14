#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 최대 시간, K = 과목 수
    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> dp(K, vector<int>(N+1, 0));
    
    for (int i=0; i<K; ++i) {
        int score, cost;
        cin >> score >> cost;
        
        for (int j=0; j<N+1; ++j) {
            if (i == 0) {
                if (j >= cost) {
                    dp[i][j] = score;
                }
            }
            else {
                if (j < cost) {
                    dp[i][j] = dp[i-1][j];
                }
                else if (j >= cost) {
                    dp[i][j] = max(dp[i-1][j-cost] + score, dp[i-1][j]);
                }
            }
        }
    }

    cout << dp[K-1][N];
    return 0;
}
