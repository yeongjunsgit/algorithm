#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> dp;

long long check_A(long long now)
{
    if (dp.find(now) == dp.end()) {
        long long tmp = check_A(now / P) + check_A(now / Q);
        dp[now] = tmp;
        return tmp;
    }
    else {
        return dp[now];
    }
    
}

int main()
{
    cin >> N >> P >> Q;
    dp[0] = 1;
    
    long long result = check_A(N);
    
    cout << result;

    return 0;
}
