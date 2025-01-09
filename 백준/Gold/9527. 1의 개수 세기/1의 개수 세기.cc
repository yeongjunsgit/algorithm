#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long A, B;

vector<long long> dp(54, 0);

long long check_one(long long num)
{
    if (num == 0) {
        return 0;
    }
    
    long long now_ones = 1;
    int power = 0;
    long long now = 1;
    dp[0] = 1;
    while (true) {
        long long next = now * 2;
        if (next == 2) {
            now = next;
            now_ones++;
            power++;
            dp[1] = 2;
        }
        else if (next <= num) {
            now_ones *= 2;
            now_ones += now - 1;
            power++;
            now = next;
            if (dp[power] == 0) {
                dp[power] = now_ones;
            }
        }
        else {
            long long gap = num - now;
            long long gap_now = 0;
            int depth = 0;
            while (gap >= 1) {
                long long compare = 1;
                int gap_power = 0;
                while ((compare * 2) <= gap) {
                    gap_power++;
                    compare *= 2;
                }
                gap -= compare;
                gap_now += dp[gap_power];
                gap_now += compare * depth;
                depth++;
            }
            
            now_ones += gap_now + (num - now); 
            break;
        }
    }
    
    return now_ones;
    
}

int main()
{
    cin >> A >> B;
    long long result = 0;
    
    long long target = 0;
    target += check_one(B) - check_one(A - 1);

    cout << target;

    return 0;
}
