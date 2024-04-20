#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int INF = 1000000007;
    
    int dp[N+1]{0};
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i=2; i<N+1; ++i) {
        dp[i] += dp[i-1];
        
        if (i-M >= 0) {
            dp[i] += dp[i-M];
        }
        dp[i] %= INF;
    }
    
    cout << dp[N];

    return 0;
}
