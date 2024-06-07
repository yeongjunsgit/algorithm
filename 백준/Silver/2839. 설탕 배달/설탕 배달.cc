#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> dp(N+1, -1);
    dp[0] = 0;
    
    for (int i=3; i<N+1; ++i) {
        if (dp[i-3] >= 0) {
            dp[i] = dp[i-3] + 1;
        } 
        
        if (i-5 >= 0) {
            if (dp[i-5] >= 0) {
                if (dp[i] == -1) {
                    dp[i] = dp[i-5] + 1;
                }
                else {
                    dp[i] = min(dp[i], dp[i-5] + 1);
                }
            }
        }
    }

    cout << dp[N];
    
    return 0;
}
