#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M, H;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> H;
    cin.ignore();
    
    vector<vector<int>> blocks;
    int num;
    string data;
    vector<int> dp(H+1, 0);
    dp[0] = 1;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        while (iss >> num) {
            one_line.push_back(num);
            
            if (i == 0) {
                dp[num] = 1;
            }
        }
        blocks.push_back(one_line);
    }
    
    for (int i=1; i<N; ++i) {
        vector<int> tmp_dp(H+1, 0);
        for (int j=0; j<blocks[i].size(); ++j) {
            tmp_dp[blocks[i][j]] += 1;
            for (int k=1; k<H+1; ++k) {
                if (dp[k] > 0) {
                    if (k+blocks[i][j] <= H) {
                        tmp_dp[k+blocks[i][j]] += dp[k];
                    }
                    else {
                        break;
                    }
                }
            }
            
        }
        
        for (int h=1; h<=H; ++h) {
            if (tmp_dp[h] > 0) {
                dp[h] += tmp_dp[h];
                dp[h] %= 10007;
            }
        }
        
    }
    
    cout << dp[H];

    return 0;
}
