#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> dp(1000001, pow(2, 30));

int main()
{
    int N;
    cin >> N;

    dp[1] = 0;
    
    for (int i=2; i<=N; ++i) {
        dp[i] = min(dp[i-1] + 1, dp[i]);
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        }
        
        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        }
    }
    
    cout << dp[N];
    
    return 0;
}
