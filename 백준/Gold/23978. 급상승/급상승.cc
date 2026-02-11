#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long N, K;
vector<long long> super_days(1000000);
long long llMAX = LLONG_MAX;

bool check_money(long long now)
{
    long long tmp = (now + 1) * now / 2;
    for (int i=0; i<N-1; ++i) {
        long long now_down = min(now, super_days[i+1] - super_days[i]);
        long long now_plus = now * now_down;
        long long danger_line = llMAX - now_plus;
        if (danger_line <= tmp) return true;
        else tmp += now_plus;
        tmp -= (now_down - 1) * now_down / 2;
    }
    // cout << now << " " <<  tmp << "\n";
    return tmp >= K;
}



long long binary_check()
{
    long long start = 1, end = 2000000000;
    
    while (start <= end) {
        long long mid = (start + end) / 2ll;
        bool is_ok = check_money(mid);
        
        if (is_ok) end = mid - 1;
        else start = mid + 1;
    }
    
    return start;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        cin >> super_days[i];
    }
    
    cout << binary_check();

    return 0;
}

