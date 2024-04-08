#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int dp[N][3]{};
    
    for (int i=0; i<N; ++i) {
        int R, G, B;
        cin >> R >> G >> B;
        
        if (i == 0) {
            dp[i][0] = R;
            dp[i][1] = G;
            dp[i][2] = B;
        }
        else {
            dp[i][0] = R + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = G + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = B + min(dp[i-1][0], dp[i-1][1]);
        }
        
    }
    
    int result = *min_element(dp[N-1], dp[N-1] + 3);
    
    cout << result;

    return 0;
}