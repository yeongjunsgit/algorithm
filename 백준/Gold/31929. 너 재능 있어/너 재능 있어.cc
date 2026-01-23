#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<int> win_score(1000), lose_score(1000);
vector<vector<int> > dp(1001, vector<int>(1001, -999999999));


int main()
{  
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> win_score[i];
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> lose_score[i];
    }
    cin >> K;
    dp[0][0] = 0;
    for (int i=0; i<=N; ++i) {
        for (int j=0; j<=M; ++j) {
            if (i + 1 <= N) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + win_score[i]);
            // cout << "현재 덧셈 연산으로 " << i << " " << j << "에서 " << dp[i+1][j] << "결과이다.\n";
            if (j + 1 <= M) {
                int safety_line;
                if (dp[i][j] >= 0) safety_line = (dp[i][j] / K) * K;
                else safety_line = (dp[i][j] / K - 1) * K;
                if (safety_line == dp[i][j]) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - lose_score[j]);
                    // cout << "현재 보호 실패 빼기 연산으로 " << i << " " << j << "에서" << dp[i][j+1] << "결과이다.\n";
                }
                else {
                    // cout << "현재 " << i << " " << j << "에서의 보호 구간은 " << safety_line << "이다.\n"; 
                    dp[i][j + 1] = max(dp[i][j + 1], max(safety_line, dp[i][j] - lose_score[j]) );
                    // cout << "현재 보호 빼기 연산으로 " << i << " " << j << "에서" << dp[i][j+1] << "결과이다.\n";
                }
            }
        }
    }
    
    cout << dp[N][M];

    return 0;
}
