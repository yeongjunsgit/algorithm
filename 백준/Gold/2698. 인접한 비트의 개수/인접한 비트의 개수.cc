// 이 문제는 처음 봤을때도 알고리즘이 이렇다 할게 떠오르지 않았다... 브루트포스는 절대 아닌거 같고..
// 구현으로 하나씩 움직이는 것도 뭔가 불확실해보이고.. 계속 고민하다가 알고리즘 분류를 봤는데도 도저히
// 어떻게 풀지 생각이 안나서 결국 블로그를 참고했다...
// 푸는 방법은 의외로 간단했는데, dp를 [수열의 길이][인접한 비트의 개수][현재 마지막 비트의 값] 으로 선언하는 것이다.
// 이렇게 하면 현재 i의 길이를 가지는 수열에서 인접한 비트의 개수가 k개일때 마지막 비트의 값에 따라 i+1의 길이에 값을 더할 수 있다.
// 만약 끝이 0이라면 뒤에 0을 붙이고 k값이 그대로 가는 방법, 뒤에 1을 붙이고 k값이 그대로 가는 방법
// 만약 끝이 1이라면 뒤에 0을 붙이고 k값이 그대로 가는 방법, 뒤에 1을 붙이고 k+1로 값을 더해가는 방법이다.
// 이를 dp로 구현하였다! 흠.. 더 정진하자..!

#include <iostream>
#include <vector>

using namespace std;

int T, N, K, s, e;

vector<vector<vector<long long> > > dp(101, vector<vector<long long> >(101, vector<long long>(2, 0) ) );

void make_DP()
{
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    
    for (int i=1; i<100; ++i) {
        for (int j=0; j<100; ++j) {
            if (dp[i][j][0] > 0) {
                dp[i+1][j][0] += dp[i][j][0];
                dp[i+1][j][1] += dp[i][j][0];
            }
            if (dp[i][j][1] > 0) {
                dp[i+1][j][0] += dp[i][j][1];
                dp[i+1][j+1][1] += dp[i][j][1];
            }
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    make_DP();
    for (int t=0; t<T; ++t) {
        cin >> s >> e;
        long long tmp = 0;
        tmp += dp[s][e][0] + dp[s][e][1];
        
        cout << tmp << "\n";
    }

    return 0;
}
