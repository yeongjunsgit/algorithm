#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > DP(10001, vector<int>(501, -1));
vector<int> dist(10001);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
        cin >> dist[i];
    }
    DP[1][1] = dist[1];
    DP[1][0] = 0;
    
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<=M; ++j) {
            if (DP[i][j] != -1) {
                if (i != N && j != M) {
                    DP[i + 1][min(M, j + 1)] = max(DP[i][j] + dist[i + 1], DP[i + 1][min(M, j + 1)]);
                    // cout << "{" << i + 1 << ", " << min(M, j + 1) << "} = " << DP[i + 1][min(M, j + 1)] << "\n";
                }
                if (i + max(1, j) <= N) {
                    DP[i + max(1, j)][0] = max(DP[i][j], DP[i + max(1, j)][0]);
                    // cout << "{" << i + max(1, j) << ", " << 0 << "} = " << DP[i + max(1, j)][0] << "\n";
                }
            }
        }
    }
    
    cout << DP[N][0];

    return 0;
}