#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    string data;
    getline(cin, data);
    istringstream iss(data);
    int num;
    vector<int> numbers;
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    vector<vector<long long>> dp(N-1, vector<long long>(21));
    vector<vector<long long>> number_dp(N-1, vector<long long>(21));
    
    dp[0][numbers[0]] = 1;
    
    for (int i=1; i<N-1; ++i) {
        for (int j=0; j<21; ++j){
            if (dp[i-1][j] != 0) {
                if (j + numbers[i] <= 20) {
                    dp[i][j+numbers[i]] += dp[i-1][j];
                }
                if (j - numbers[i] >= 0) {
                    dp[i][j-numbers[i]] += dp[i-1][j];
                }
            }
        }
    }
    
    cout << dp[N-2][numbers[numbers.size()-1]];

    return 0;
}
