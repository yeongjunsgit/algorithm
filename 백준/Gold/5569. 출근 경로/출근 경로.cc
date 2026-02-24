#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<vector<vector<int> > > > dp(2, vector<vector<vector<int> > >(2, vector<vector<int> >(100, vector<int>(100, 0) ) ) );
vector<pll> directions = {{1, 0}, {0, 1}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    // 0 = 전환 가능, 1 = 전환 불가능 
    dp[0][0][1][0] = 1;
    dp[0][1][0][1] = 1;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            for (int k=0; k<2; ++k) {
                // 전환 가능일 경우
                if (k == 0) {
                    for (int q=0; q<2; ++q) {
                        
                        if (dp[k][q][i][j] <= 0) continue;
                        
                        for (int p=0; p<2; ++p) {
                            int nx = i + directions[p].first;
                            int ny = j + directions[p].second;
                            if (nx < N && ny < M) {
                                if (p == q) {
                                    dp[0][p][nx][ny] += dp[k][q][i][j];
                                    dp[0][p][nx][ny] %= 100000;
                                }
                                else {
                                    dp[1][p][nx][ny] += dp[k][q][i][j];
                                    dp[1][p][nx][ny] %= 100000;
                                }
                            }
                        }
                    }
                }
                // 불가능일 경우
                else {
                    for (int q=0; q<2; ++q) {
                        int nx = i + directions[q].first;
                        int ny = j + directions[q].second;
                        if (nx < N && ny < M) {
                            dp[0][q][nx][ny] += dp[k][q][i][j];
                            dp[0][q][nx][ny] %= 100000;
                        }
                    }
                }
            }
            
        }
    }
    
    int result = (dp[0][0][N-1][M-1] + dp[0][1][N-1][M-1] + dp[1][0][N-1][M-1] + dp[1][1][N-1][M-1]) % 100000;
    
    cout << result;


    return 0;
}
