#include <iostream>
#include <vector>

using namespace std;

string one, two;

int result = 0;

void lcs()
{
    int N = one.size();
    int M = two.size();
    vector<vector<int> > dp(N+1, vector<int>(M+1, 0));
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            if (one[i-1] == two[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (result < dp[i][j]) {
                    result = dp[i][j];
                }
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    cout << result;
    
    return;
    
}

int main()
{
    cin >> one >> two;
    
    lcs();

    return 0;
}
