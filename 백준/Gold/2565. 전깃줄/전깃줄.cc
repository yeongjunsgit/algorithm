#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}  


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> liner;
    
    for (int i=0; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        
        liner.push_back({s, e});
    }
    
    sort(liner.begin(), liner.end(), Compare);

    int longest = 0;
    int dp[N]{0};
    dp[0] = 1;
    
    for (int i=1; i<N; ++i) {
        for (int j=i-1; j>=0; --j) {
            if (liner[i].second > liner[j].second) {
                if (dp[i] < dp[j]) {
                    dp[i] = dp[j];
                }
            }
        }
        
        dp[i] += 1;
        
        if (longest < dp[i]) {
            longest = dp[i];
        }
    }
    
    cout << N - longest;
    
    return 0;
}