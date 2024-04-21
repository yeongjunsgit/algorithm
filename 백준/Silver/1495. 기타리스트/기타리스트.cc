#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    // N = 곡의 개수, S = 시작 볼륨, M = 변할수 있는 볼륨의 최대 값
    // 즉, 볼륨은 0 <= 현재볼륨 <= M의 범위안에서만 움직여야한다. 
    int N, S, M;
    cin >> N >> S >> M;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    vector<int> change_volumn;
    
    while (iss >> num) {
        change_volumn.push_back(num);
    }
    
    vector<vector<bool>> dp(N+1, vector<bool>(M+1, false));
    dp[0][S] = true;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M+1; ++j) {
            if (dp[i][j] == true) {
                if (j + change_volumn[i] <= M) {
                    dp[i+1][j + change_volumn[i]] = true;
                }
                if (j - change_volumn[i] >= 0) {
                    dp[i+1][j - change_volumn[i]] = true;
                }
            }
        }
    }
    
    int result = -1;
    
    for (int i=0; i<M+1; ++i) {
        if (dp[N][i] == true) {
            result = i;
        }
    }

    cout << result;

    return 0;
}
