#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, a, b, A = 0, B = 0;
long long X, K;
vector<pll> friends(80);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> X;
    vector<vector<int> > dp(K + 1, vector<int>(16001, 0));
    dp[0][0]= 1;
    for (int i=0; i<N; ++i) {
        cin >> a >> b;
        
        for (int j=K; j>=1; --j) {
            for (int q=16000; q>=a; --q) {
                if (dp[j - 1][q - a] == 1) dp[j][q] = 1;
            }
        }
    }
    
    long long result = -1, base = X * K / 2;
    for (int i=0; i<16001; ++i) {
        if (dp[K][i] == 1) {
            if (result == -1 || abs(base - i) <= abs(base - result)) {
                result = i;
            }
        }
    }
    
    cout << result * (X * K - result);

    return 0;
}
