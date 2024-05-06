#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, max_time;
    cin >> N >> max_time;
    
    vector<vector<int>> dp(N, vector<int>(max_time+1, 0));
    
    for (int n=0; n<N; ++n) {
        int cost, score;
        cin >> cost >> score;
        
        for (int i=0; i<max_time+1; ++i) {
            if (n == 0) {
                if (i >= cost) {
                    dp[n][i] = score;
                }
            }
            else {
                if (i < cost) {
                    dp[n][i] = dp[n-1][i];
                }
                else {
                    dp[n][i] = max(dp[n-1][i-cost] + score, dp[n-1][i]);
                }
            }
        }
    }
    
    cout << dp[N-1][max_time];
    

    return 0;
}
