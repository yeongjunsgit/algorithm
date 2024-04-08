#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long dp[1001][1001]{};
    
    dp[1][1] = 1;

    for (int i=2; i<1001; ++i) {
        if (i==2 || i == 3) {
            dp[i][1] = 1;
        }
        if (i - 1 > 0) {
            for (int j=1; j<i; ++j) {
                if (dp[i-1][j] != 0) {
                    dp[i][j+1] += dp[i-1][j];
                }
            }
        }
        if (i - 2 > 0) {
            for (int j=1; j<i; ++j) {
                if (dp[i-2][j] != 0) {
                    dp[i][j+1] += dp[i-2][j];
                }
            }
        }
        if (i - 3 > 0) {
            for (int j=1; j<i; ++j) {
                if (dp[i-3][j] != 0) {
                    dp[i][j+1] += dp[i-3][j];
                }
            }
        }
        
        for (int k=1; k<i+1; ++k) {
            if (dp[i][k] != 0){
                dp[i][k] %= 1000000009;
            }
        }
        
    }
    
    
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        int target, range;
        cin >> target >> range;
        
        long long result = 0;
        
        for (int i=0; i<range+1; ++i) {
            result += dp[target][i];
        }
        
        result %= 1000000009;
        
        cout << result << "\n";
    }
    

    return 0;
}
