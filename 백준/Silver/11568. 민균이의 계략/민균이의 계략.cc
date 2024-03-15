#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> cards(N);
    for (int i=0; i < N; ++i) {
        cin >> cards[i];
    };
    
    vector<int> dp(N);
    dp[0] = 1;
    
    for (int j=1; j < N; ++j) {
        int last_best = 0;
        for (int k=0; k < j; ++k) {
            if (dp[k] > last_best && cards[j] > cards[k]) {
                last_best = dp[k];
            }
        }
        
        dp[j] = last_best + 1;
    }
    
    int result = 0;
    for (int r=0; r < N; ++r) {
        if (dp[r] > result) {
            result = dp[r];
        }
    }
    
    cout << result;

    return 0;
}