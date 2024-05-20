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
    vector<int> price;
    price.push_back(0);
    
    while (iss >> num) {
        price.push_back(num);
    }
    
    vector<int> dp(N+1, 9999999999);
    dp[0] = 0;
    
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<i; ++j) {
            dp[i] = min(dp[j] + price[i-j], dp[i]);
        }
    }
    
    cout << dp[N];

    return 0;
}
