#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> prime_dp(4000000, -1);
vector<int> prime_nums;

void make_prime()
{
    prime_dp[1] = 0;
    for (int i=2; i<=4000000; ++i) {
        if (prime_dp[i] == -1) {
            prime_dp[i] = 0;
            prime_nums.push_back(i);
        }
        int idx = 2;
        while (true) {
            if (i * idx > 4000000) {
                break;
            }
            prime_dp[i * idx] = 0;
            
            idx++;
            
        }
    }
    return;
}

void check_prime()
{
    int M = prime_nums.size();
    for (int i=0; i<M; ++i) {
        int make_num = 0;
        
        for (int j=i; j<M; ++j) {
            make_num += prime_nums[j];
            
            if (make_num <= 4000000) {
                prime_dp[make_num]++;
            }
            else {
                break;
            }
        }
    }
    
    return;
}

int main()
{
    cin >> N;
    make_prime();
    check_prime();
    
    
    cout << prime_dp[N];

    return 0;
}
