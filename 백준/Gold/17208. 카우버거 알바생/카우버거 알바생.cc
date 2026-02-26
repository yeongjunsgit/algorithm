#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, M, K, s, e, result = 0;
vector<pll> orders(101);
vector<vector<vector<int> > > dp(101, vector<vector<int> >(301, vector<int>(301, -1)));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i=1; i<=N; ++i) {
        cin >> s >> e;
        orders[i] = {s, e};
    }
    dp[0][0][0] = 0;
    for (int i=1; i<=N; ++i) {
        pll now = orders[i];
        for (int j=0; j<=M; ++j) {
            for (int k=0; k<=K; ++k) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                int nx = j - now.first;
                int ny = k - now.second;
                if (nx >= 0 && ny >= 0) {
                    if (dp[i-1][nx][ny] != -1) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][nx][ny] + 1);
                    }
                }
                if (i == N) {
                    result = max(result, dp[i][j][k]);
                }
            }
        }
    }
    cout << result;
    
    return 0;
}
