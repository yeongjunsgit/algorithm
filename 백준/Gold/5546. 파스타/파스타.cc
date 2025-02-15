#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<vector<int> > > dp;
vector<int> must_p;

void eat_pasta()
{
    for (int i=1; i<=N; ++i) {
        if (must_p[i] != -1) {
            if (i == 1) {
                dp[must_p[i]][0][i] = 1;
            }
            else {
                for (int j=0; j<3; ++j) {
                    if (j != must_p[i]) {
                        for (int k=0; k<2; ++k) {
                            dp[must_p[i]][0][i] += dp[j][k][i - 1]; 
                        }
                        dp[must_p[i]][0][i] %= 10000; 
                        
                    }
                    else {
                        dp[must_p[i]][1][i] += dp[must_p[i]][0][i-1];
                        dp[must_p[i]][1][i] %= 10000;
                    }
                }
            }
        }
        else {
            if (i == 1) {
                for (int j=0; j<3; ++j) {
                    dp[j][0][i] = 1;
                }
            }
            else {
                for (int j=0; j<3; ++j) {
                    for (int k=0; k<3; ++k) {
                        if (j == k) {
                            // cout << "나는 " << j << "소스를 한번 더 먹어서" << dp[j][0][i - 1] << "을 " << dp[j][1][i] << "에 더할거야" << "\n";
                            dp[j][1][i] += dp[j][0][i - 1];
                            dp[j][1][i] %= 10000;
                        }
                        else {
                            for (int p=0; p<2; ++p) {
                                // cout << "나는 " << dp[k][p][i-1] << "을 " << dp[j][0][i] << "에 더할거야" << "\n";
                                dp[j][0][i] += dp[k][p][i-1];
                            }
                            dp[j][0][i] %= 10000;
                        }
                    }
                }
            }
        }
        for (int j=0; j<3; ++j) {
            for (int k=0; k<2; ++k) {
                // cout << i << "일에 " << j << "번 소스를 " << k << "번 먹은 경우는 " << dp[j][k][i] << "\n";
            }
        }
        
    }
    
    int result = 0;
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<2; ++j) {
            result += dp[i][j][N];
        }
    }
    result %= 10000;
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> K;
    dp.resize(3, vector<vector<int> >(2, vector<int>(N+1, 0)));
    must_p.resize(N+1, -1);
    int d, p;
    for (int i=0; i<K; ++i) {
        cin >> d >> p;
        must_p[d] = p - 1;
    }
    
    eat_pasta();

    return 0;
}
