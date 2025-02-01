#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> weight, value;

void backpack()
{
    vector<vector<int> > dp(N, vector<int>(K+1, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<=K; ++j) {
            if (i == 0) {
                if (j >= weight[i]) dp[i][j] = value[i];
            }
            else {
                if (j < weight[i]) dp[i][j] = dp[i-1][j];
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[i]] + value[i]);
                }
            }
        }
    }
    
    cout << dp[N-1][K];
    
    return;
}

int main()
{
    cin >> N >> K;
    
    int w, v;
    for (int i=0; i<N; ++i) {
        cin >> w >> v;
        weight.push_back(w);
        value.push_back(v);
    }

    backpack();

    return 0;
}
