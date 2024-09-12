#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    int result = 0;
    cin >> N;
    cin.ignore();

    string data;
    int num;
    getline(cin, data);
    vector<int> numbers(N+1, 0);
    istringstream iss(data);
    int idx = 1;
    
    while (iss >> num) {
        if (idx == 1) {
            numbers[idx] = num;
        }
        else {
            numbers[idx] = numbers[idx - 1] + num;
        }
        idx++;
    }

    cin >> K;

    vector<vector<int> > dp(4, vector<int>(N+1, 0));

    for (int i=1; i<4; ++i) {
        for (int j=i*K; j<=N; ++j) {
            // 이전 값과 비교해서 현재 위치에서 K개를 더한값에 K개 뒤의 위치의 최대값을 더했을 때 더큰 값으로 선택
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-K] + (numbers[j] - numbers[j-K]));
        }
    }
    
    cout << dp[3][N];
    
    return 0;
}
