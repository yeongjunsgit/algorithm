#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    vector<long long> numbers;
    string data;
    
    getline(cin, data);
    istringstream iss(data);
    long long num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    vector<long long> dp(N, -100000001);
    vector<long long> dp_skip(N, -100000001);
    
    long long result = -100000001;
    
    for (int i=0; i<N; ++i) {
        if (i == 0) {
            dp[i] = max(numbers[0], -100000001LL);
        }
        
        else {
            dp[i] = max(dp[i-1] + numbers[i], numbers[i]);
            dp_skip[i] = max(dp[i-1], dp_skip[i-1] + numbers[i]);
        }
        
        result = max({result, dp[i], dp_skip[i]});
    }
    
    cout << result;

    return 0;
}
