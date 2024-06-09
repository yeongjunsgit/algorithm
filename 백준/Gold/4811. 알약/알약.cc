#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    
    vector<long long> dp(31, 0);
    dp[0] = 1;
    
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        
        if (dp[N] == 0) {
            for (int i=0; i<=N; ++i) {
                if (dp[i] == 0) {
                    for (int j=0; j<i; ++j) {
                        dp[i] += dp[j] * dp[i-1-j];
                    }
                }
            }
        }
        
        cout << dp[N] << "\n";
    }

    return 0;
}
