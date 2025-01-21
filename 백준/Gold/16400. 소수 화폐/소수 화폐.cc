#include <iostream>
#include <vector>

using namespace std;

int N;
int INF = 123456789;
vector<int> prime_num(40001, 0);
vector<int> dp(40001, 0);
vector<int> primes;

void find_prime()
{
    for (int i=2; i<=40000; ++i) {
        if (prime_num[i] == 0) {
            prime_num[i] = 1;
            primes.push_back(i);
            int tmp = 2;
            while (i * tmp <= 40000) {
                prime_num[i * tmp] = 2;
                tmp++;
            }
        }
    }
    
    return;
}

void make_dp()
{
    dp[0] = 1;
    
    for (int a : primes) {
        for (int i=a; i<40001; ++i) {
            dp[i] += dp[i-a];
            dp[i] %= INF;
        }
    }
    
    cout << dp[N];
    
    return;
}

int main()
{
    cin >> N;
    
    find_prime();
    make_dp();

    return 0;
}
