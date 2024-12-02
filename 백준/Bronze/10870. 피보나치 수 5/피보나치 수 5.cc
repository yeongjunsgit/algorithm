#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> dp(N+1, 0);
    
    for (int i=1; i<=N; ++i) {
        if (i == 1) {
            dp[i] = 1;
        }
        else {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
    }
    
    cout << dp[N];

    return 0;
}
