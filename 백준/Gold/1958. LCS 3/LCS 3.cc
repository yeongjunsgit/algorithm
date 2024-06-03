#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string data_1, data_2, data_3;
    getline(cin, data_1);
    getline(cin, data_2);
    getline(cin, data_3);
    
    int N, M, K;
    N = data_1.size();
    M = data_2.size();
    K = data_3.size();

    vector<vector<vector<int>>> lcs(N+1, vector<vector<int>>(M+1, vector<int>(K+1, 0)));
    
    int result = 0;
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            for (int k=1; k<=K; ++k) {
                if (data_1[i-1] == data_2[j-1] && data_2[j-1] == data_3[k-1]) {
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                    if (lcs[i][j][k] > result) {
                        result = lcs[i][j][k];
                    }
                }
                else {
                    lcs[i][j][k] = max({lcs[i-1][j][k], lcs[i][j-1][k], lcs[i][j][k-1]});
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
