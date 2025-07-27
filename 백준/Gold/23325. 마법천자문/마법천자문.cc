#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> numbers = {{'+', 10}, {'-', 1}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data; cin >> data;
    int N = data.size();
    vector<vector<int> > dp(2, vector<int>(200001, -999999999));
    dp[0][0] = numbers[data[0]];
    
    for (int i=1; i<N; ++i) {
        int tmp = numbers[data[i]];
        if (dp[1][i-1] != -999999999 && dp[0][i-2] != -999999999) {
            if (dp[1][i-1] == 0) dp[0][i] = max(dp[0][i], dp[0][i-2] + tmp);
            else dp[0][i] = max(dp[0][i], dp[0][i-2] - tmp);
        }
        if (data[i] == '-' && data[i-1] == '+') {
            tmp += 10;
            if (i == 1) dp[0][i] = tmp;
            else {
                if (dp[1][i-2] != -999999999 && dp[0][i-3] != -999999999) {
                    if (dp[1][i-2] == 0) dp[0][i] = max(dp[0][i], dp[0][i-3] + tmp);
                    else dp[0][i] = max(dp[0][i], dp[0][i-3] - tmp);
                }
            }
        }
        if (data[i] == '-') dp[1][i] = 1;
        else dp[1][i] = 0;
    }
    
    cout << dp[0][N-1];

    return 0;
}
