#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
    cin >> N;
    // 0 = L을 쓴곳, 1 = L 안쓴곳, 안쪽의 0 = A 연속 0개, 1 = A 연속 1개, 2 = A 연속 2개 
    vector<vector<vector<int> > > dp(2, vector<vector<int > >(3, vector<int>(N, 0)));
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    dp[1][0][0] = 1;

    
    for (int i=1; i<N; ++i) {
        // L을 안쓴 곳
        dp[0][0][i] = (dp[0][0][i-1] + dp[0][1][i-1] + dp[0][2][i-1]) % 1000000;
        dp[0][1][i] = dp[0][0][i-1] % 1000000;
        dp[0][2][i] = dp[0][1][i-1] % 1000000;
        
        // L 쓴 곳
        dp[1][0][i] = (dp[1][0][i-1] + dp[1][1][i-1] + dp[1][2][i-1] + dp[0][0][i-1] + dp[0][1][i-1] + dp[0][2][i-1]) % 1000000;
        dp[1][1][i] = dp[1][0][i-1] % 1000000;
        dp[1][2][i] = dp[1][1][i-1] % 1000000;
    }
    
    int result = 0;
    for (int i=0; i<3; ++i) {
        result += dp[0][i][N-1];
        result += dp[1][i][N-1];
    }
    
    cout << result % 1000000;

    return 0;
}
