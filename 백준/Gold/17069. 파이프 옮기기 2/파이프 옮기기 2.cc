#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > board(32, vector<int>(32) );
vector<vector<vector<long long> > > dp(32, vector<vector<long long> >(32, vector<long long>(3, 0) ) );

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
        }
    }
    dp[0][1][0] = 1;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            // 벽이 아닐때
            if (board[i][j] == 0) {
                // 가로 파이프
                if (dp[i][j][0]) {
                    if (j + 1 < N && board[i][j+1] == 0) {
                        dp[i][j+1][0] += dp[i][j][0];
                    }
                    if (j + 1 < N && i + 1 < N && board[i][j+1] == 0 && board[i+1][j+1] == 0 && board[i+1][j] == 0) {
                        dp[i+1][j+1][1] += dp[i][j][0];
                    }
                }
                // 대각선 파이프
                if (dp[i][j][1]) {
                    if (j + 1 < N && board[i][j+1] == 0) {
                        dp[i][j+1][0] += dp[i][j][1];
                    }
                    if (j + 1 < N && i + 1 < N && board[i][j+1] == 0 && board[i+1][j+1] == 0 && board[i+1][j] == 0) {
                        dp[i+1][j+1][1] += dp[i][j][1];
                    }
                    if (i + 1 < N && board[i+1][j] == 0) {
                        dp[i+1][j][2] += dp[i][j][1];
                    }
                }
                // 세로 파이프
                if (dp[i][j][2]) {
                    if (i + 1 < N && board[i+1][j] == 0) {
                        dp[i+1][j][2] += dp[i][j][2];
                    }
                    if (j + 1 < N && i + 1 < N && board[i][j+1] == 0 && board[i+1][j+1] == 0 && board[i+1][j] == 0) {
                        dp[i+1][j+1][1] += dp[i][j][2];
                    }
                }
            }
        }
    }
    
    long long result = dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2];
    
    cout << result;

    return 0;
}
