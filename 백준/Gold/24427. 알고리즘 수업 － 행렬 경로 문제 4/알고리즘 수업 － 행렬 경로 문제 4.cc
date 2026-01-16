#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, P;
vector<vector<vector<int> > > dp(2, vector<vector<int> >(1001, vector<int>(1001, 0) ) );
vector<vector<int> > board(1001, vector<int>(1001)), special_loca(1001, vector<int>(1001, 0));
vector<pll> directions = {{0, 1}, {1, 0}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> P;
    int s, e;
    for (int i=0; i<P; ++i) {
        cin >> s >> e;
        special_loca[s][e] = 1;
    }
    
    dp[0][1][1] = board[1][1];
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            for (int k=0; k<2; ++k) {
                int nx = i + directions[k].first;
                int ny = j + directions[k].second;
                if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                    if (dp[0][i][j] > 0) {
                        if (special_loca[nx][ny] == 0) dp[0][nx][ny] = max(dp[0][nx][ny], dp[0][i][j] + board[nx][ny]);
                        else dp[1][nx][ny] = max(dp[1][nx][ny], dp[0][i][j] + board[nx][ny]);
                    }
                    if (dp[1][i][j] > 0) {
                        dp[1][nx][ny] = max(dp[1][nx][ny], dp[1][i][j] + board[nx][ny]);
                    }
                }
            }
        }
    }
    
    cout << dp[1][N][N];

    return 0;
}
