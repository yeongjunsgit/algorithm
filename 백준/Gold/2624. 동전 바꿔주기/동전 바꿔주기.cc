#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int T, K;
vector<pll> value_cnt;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T >> K;
    int value, cnt;
    for (int k=0; k<K; ++k) {
        cin >> value >> cnt;
        value_cnt.push_back({value, cnt});
    }
    vector<long long> dp(T+1, 0);
    dp[0] = 1;
    for (auto a : value_cnt) {
        for (int i=T; i>=0; --i) {
            if (dp[i] > 0) {
                for (int j=1; j<=a.second; ++j) {
                    if (i + a.first * j > T) break;
                    dp[i + a.first * j] += dp[i];
                }
            }
        }
    }
    
    cout << dp[T];
    

    return 0;
}
