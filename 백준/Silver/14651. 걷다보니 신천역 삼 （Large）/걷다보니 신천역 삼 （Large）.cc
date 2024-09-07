/*
각 자리의 수의 모든 합이 3의 배수인 수는 3의 배수라고 한다!
우와! (배수 판정법 나무위키)
이를 이용해서 DP로 풀어볼까?
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<long long> > dp(N+1, vector<long long>(4, 0));
    dp[1] = {0, 1, 1, 0};
    
    for (int i=1; i<N; ++i) {
        for (int j=1; j<4; ++j) {
            for (int k=0; k<3; ++k) {
                int tmp = j + k;
                if (tmp >= 4) {
                    tmp -= 3;
                }
                dp[i+1][tmp] += dp[i][j];
            }
            
        }
        
        for (int j=1; j<4; ++j) {
            dp[i+1][j] %= 1000000009;
        }
    }
    
    cout << dp[N][3];

    return 0;
}
