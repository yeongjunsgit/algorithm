#include <iostream>
#include <vector>

using namespace std;

int N;
long long result = 0, num;
vector<long long> Ah_time(100001, 0), cool_time(100001, 0), scores(100001, 0), dp(100001, 0);


int binary_check(long long now, int maximum)
{
    int start = 0, end = maximum, catching = 0;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (Ah_time[mid] < now) {
            start = mid + 1;
            catching = mid;
        }
        else {
            end = mid - 1;
        }
    }
    
    return catching;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> Ah_time[i];
    }
    for (int i=1; i<=N; ++i) {
        cin >> num;
        cool_time[i] = Ah_time[i] - num;
    }
    for (int i=1; i<=N; ++i) {
        cin >> scores[i];
    }
    
    for (int i=1; i<=N; ++i) {
        int idx = binary_check(cool_time[i], i);
        dp[i] = max(dp[i-1], scores[i] + dp[idx]);
        result = max(result, dp[i]);
    }
    
    cout << result;

    return 0;
}