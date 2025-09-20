#include <iostream>

#define INF 1000000007

using namespace std;
int N;
int dp[101][10][2][3];

int main()
{
    cin >> N;
    if (N == 1) cout << 10;
    else {
        int result = 0;
        for (int i=1; i<10; ++i) {
            dp[2][i][0][1] = 1;
            dp[2][i-1][1][1] = 1;
        }
        for (int i=3; i<=N; ++i) {
            for (int j=0; j<=9; ++j) {
                if (j != 0) {
                    dp[i][j][0][1] = ((((dp[i][j][0][1] + dp[i-1][j-1][1][0]) % INF + dp[i-1][j-1][1][1]) % INF + dp[i-1][j-1][1][2]) % INF + dp[i-1][j-1][0][0]) % INF;
                    dp[i][j][0][2] = dp[i-1][j-1][0][1];
                }
                if (j != 9) {
                    dp[i][j][1][1] = ((((dp[i][j][1][1] + dp[i-1][j+1][0][0]) % INF + dp[i-1][j+1][0][1]) % INF + dp[i-1][j+1][0][2]) % INF + dp[i-1][j+1][1][0]) % INF;
                    dp[i][j][1][2] = dp[i-1][j+1][1][1];
                }
            }
        }
        for (int i=0; i<=9; ++i) {
            for (int j=0; j<3; ++j) {
                result = (result + dp[N][i][0][j]) % INF;
                result = (result + dp[N][i][1][j]) % INF;
            }
        }
        cout << result;
    }

    return 0;
}