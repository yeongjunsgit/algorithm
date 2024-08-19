#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void make_over(vector<long long>& dp) {
    int idx = 1;
    long long sumsum = 3;
    while (sumsum < pow(10, 9)) {
        dp[idx] = sumsum;
        sumsum *= 2;
        sumsum += (3+idx);
        idx += 1;
    }
    
    return;
}

int main()
{
    long long N;
    cin >> N;
    
    long long m_num = 0;
    long long now_turn = 0;
    
    vector<long long> dp(28, 0);
    
    make_over(dp);
    N--;
    
    int idx = 27;
    
    while (dp[1] <= N) {
        for (int i=idx; i>=1; --i) {
            if (dp[i] < N) {
                N -= dp[i];
                if (N != 0) {
                    N -= (3+i);
                }
                idx = i-1;
                break;
            }
            else if (dp[i] == N) {
                N -= dp[i];
                break;
            }
        }
    }
    
    if (N == 0) {
        cout << 'm';
    }
    else {
        cout << 'o';
    }

    return 0;
}
