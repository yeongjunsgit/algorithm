#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> use_hp(1001), get_score(1001);

int lets_play()
{
    vector<vector<int> > DP(N+1, vector<int>(101, -1));
    DP[0][100] = 0;
    
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<=100; ++j) {
            if (DP[i-1][j] >= 0) {
                DP[i][min(100, j + K)] = max(DP[i][min(100, j + K)], DP[i-1][j]);
                
                if (min(100, j + K) - use_hp[i] >= 0) {
                    DP[i][min(100, j + K) - use_hp[i]] = max(DP[i][min(100, j + K) - use_hp[i]], DP[i-1][j] + get_score[i]);
                }
            }
        }
    }
    
    int tmp = 0;
    for (int i=0; i<=100; ++i) {
        tmp = max(tmp, DP[N][i]);
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=1; i<=N; ++i) {
        cin >> get_score[i];
    }
    for (int i=1; i<=N; ++i) {
        cin >> use_hp[i];
    }
    
    cout << lets_play();

    return 0;
}
