#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num;
    cin >> N;
    int result = -400000001;
    vector<vector<int> > DP(5, vector<int>(10000001, -400000001));
    DP[0][0] = 0;
    
    for (int i=1; i<=N; ++i) {
        cin >> num;
        DP[0][i] = 0;
        for (int j=1; j<5; ++j) {
            DP[j][i] = max(DP[j][i], DP[j][i-1]);
            if (j == 1 || j == 3) {
                if (DP[j-1][i-1] != -400000001) {
                    DP[j][i] = max(DP[j][i], DP[j-1][i-1] - num);
                    // cout << DP[j][i] << "\n";
                }
            }
            else {
                if (DP[j-1][i-1] != -400000001) {
                    DP[j][i] = max(DP[j][i], DP[j-1][i-1] + num);
                    // cout << DP[j][i] << "\n";
                    if (j == 4) {
                        // cout << "나는" << i << "번째의 4임 " << DP[j][i] << "\n";
                        result = max(result, DP[j][i]);
                    }
                }
            }
        }
    }
    
    cout << result;

    return 0;
}