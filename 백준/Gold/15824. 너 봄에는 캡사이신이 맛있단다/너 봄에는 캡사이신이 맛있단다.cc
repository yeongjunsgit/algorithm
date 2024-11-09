#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long result = 0;
vector<long long> numbers;
vector<long long> dp(300010, 1);

void get_scobill()
{
    int idx = N - 1;
    for (int i=N-1; i>0; --i) {
        // cout << (((dp[i] - 1) * numbers[i]) % 1000000007) << " " << (((dp[i] - 1) * numbers[idx - i]) % 1000000007) << "\n";
        
        result += (dp[i] - 1) * numbers[i] % 1000000007;
        result -= (dp[i] - 1) * numbers[idx - i] % 1000000007;
        // cout << tmp << "\n";
        result %= 1000000007;
    }
    
    result += 1000000007;
    result %= 1000000007;
    
    cout << result;
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    string data;
    getline(cin, data);
    istringstream iss(data);
    long long num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    
    dp[1] = 2;
    for (int i=2; i<=N; ++i) {
        dp[i] = dp[i-1] * 2;
        dp[i] %= 1000000007;
    }
    
    get_scobill();

    return 0;
}
