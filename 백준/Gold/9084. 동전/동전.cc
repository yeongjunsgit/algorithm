#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for (int i=0; i<T; ++i) {
        int N;
        cin >> N;
        
        cin.ignore();
        
        vector<int> numbers;
        string data;
        
        getline(cin, data);
        istringstream iss(data);
        
        
        int target;
        cin >> target;
        
        long long dp[target+1]{0};
        dp[0] = 1;
        
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }
        
        for (int j=0; j<N; ++j) {
            for (int i=numbers[j]; i<target+1; ++i) {
                dp[i] += dp[i-numbers[j]];
            }
        }
        
        cout << dp[target] << "\n";
        
        
    }

    return 0;
}