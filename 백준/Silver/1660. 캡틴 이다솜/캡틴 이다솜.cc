#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> costs;

    int num = 1;
    int sum_num = 0;
    int pre_num = 0;

    while (true) {
        sum_num += num;
        if (pre_num < N) {
            costs.push_back(sum_num + pre_num);
            num += 1;
            pre_num += sum_num;
        }
        else {
            break;
        }
    }
    
    vector<int> dp(N+1, 1000000);
    dp[0] = 0;
    
    for (int i=1; i<N+1; ++i) {
        for (int j=0; j<costs.size(); ++j) {
            if (costs[j] <= i) {
                dp[i] = min(dp[i-costs[j]] + 1, dp[i]);
                
            } 
            else {
                break;
            }
        }
    }
    
    cout << dp[N];

    return 0;
}

