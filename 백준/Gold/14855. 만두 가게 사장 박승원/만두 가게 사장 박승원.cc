#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;
int N, M, sc, sd, K = 0;
vector<pll> mandu;

void make_mandu()
{
    vector<vector<int> > DP(K, vector<int>(1001, -1));
    int result = N / sc * sd;
    if (K > 0) {
        DP[0][0] = 0;
        for (int i=0; i<K; ++i) {
            pll now = mandu[i];
            if (i == 0) {
                DP[i][now.first] = now.second;
            }
            else {
                for (int j=0; j<=N; ++j) {
                    DP[i][j] = max(DP[i][j], DP[i-1][j]);
                    if (j - now.first >= 0 && DP[i-1][j-now.first] != -1) {
                        DP[i][j] = max(DP[i][j], DP[i-1][j-now.first] + now.second);
                    }
                }
            }
        }
        
        for (int i=0; i<=N; ++i) {
            int special_mandu = (N - i) / sc * sd;
            if (DP[K-1][i] == -1) {
                result = max({result, 0, special_mandu});
            }
            else {
                result = max(result, DP[K-1][i] + special_mandu);
            }
        }
    }
    
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> sc >> sd;
    int total, need, nc, price;
    for (int i=0; i<M; ++i) {
        cin >> total >> need >> nc >> price;
        int piece = total / need;
        
        for (int j=0; j<piece; ++j) {
            mandu.push_back({nc, price});
        }
        K += piece;
    }
    
    make_mandu();

    return 0;
}
