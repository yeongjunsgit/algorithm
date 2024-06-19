#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        int N;
        cin >> N;
        
        cin.ignore();
        
        vector<int> coins;
        string data;
        
        getline(cin, data);
        istringstream iss(data);
        int num;
        while (iss >> num) {
            coins.push_back(num);
        }
        
        int money;
        cin >> money;
        
        vector<vector<int>> dp(N, vector<int>(money+1, 0));
        dp[0][0] = 1;
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<=money; ++j) {
                if (i == 0) {
                    if (j % coins[i] == 0) {
                        dp[i][j] = 1;
                    }
                }
                else {
                    // 현재 코인 값보다 작은 돈이라면 이전의 값을 불러오기
                    if (j < coins[i]) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    // 
                    else {
                        for (int k=0; k<=j; k += coins[i]) {
                            if (dp[i - 1][j - k] != 0) {
                                dp[i][j] += dp[i - 1][j - k];
                            }
                        }
                    }
                }
            }
            bool hi = false;
        }
        
        cout << dp[N-1][money] << "\n";
        
        
    }

    return 0;
}
