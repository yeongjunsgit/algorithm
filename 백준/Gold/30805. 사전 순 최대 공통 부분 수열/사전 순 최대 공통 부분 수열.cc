#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
vector<int> one, two;
vector<int> result;
pair<int, int> loca;

int find_idx(vector<int> arr, int target)
{
    if (arr.size() == 0) {
        return 1;
    }
    
    int idx = 0;
    for (int a : arr) {
        if (target > a) {
            break;
        }
        idx++;
    }
    
    return idx;
}

void LCS()
{
    vector<vector<pair<int, vector<int> > > > dp(N+1, vector<pair<int, vector<int> > >(M+1, {0, vector<int>(0, 0)}));
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            if (one[i-1] == two[j-1]) {
                dp[i][j].first = dp[i-1][j-1].first + 1;
                int idx = find_idx(dp[i-1][j-1].second, one[i-1]);
                dp[i][j].second = dp[i-1][j-1].second;
                if (idx >= dp[i-1][j-1].second.size()) {
                    dp[i][j].second.push_back(one[i-1]);
                }
                else {
                    dp[i][j].second[idx] = one[i-1];
                    while (dp[i][j].second.size() - 1 > idx) {
                        dp[i][j].second.pop_back();
                    } 
                }
                if (result < dp[i][j].second) {
                    result = dp[i][j].second;
                }
            }
            else {
                if (dp[i-1][j].second > dp[i][j-1].second) {
                    dp[i][j].first = dp[i-1][j].first;
                    dp[i][j].second = dp[i-1][j].second;
                }
                else {
                    dp[i][j].first = dp[i][j-1].first;
                    dp[i][j].second = dp[i][j-1].second;
                }
            }
        }
    }
    
    cout << result.size() << "\n";
    for (int a : result) {
        cout << a << " ";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int num;
    for (int i=0; i<N; ++i) {
        cin >> num;
        one.push_back(num);
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> num;
        two.push_back(num);
    }
    
    LCS();
    

    return 0;
}