#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
struct Compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    vector<int> hp_cost;
    int num;
    
    istringstream iss(data);
    while (iss >> num) {
        hp_cost.push_back(num);
    }
    
    getline(cin, data);
    vector<int> happiness;
    
    istringstream iss_2(data);
    while (iss_2 >> num) {
        happiness.push_back(num);
    }
    
    vector<vector<int>> dp(N, vector<int>(100, 0));
    
    vector<pair<int, int>> friends;
    
    for (int i=0; i<N; ++i) {
        friends.push_back({hp_cost[i], happiness[i]});
    }
    
    sort(friends.begin(), friends.end(), Compare());

    for (int i=0; i<N; ++i) {
        pair<int, int> now = friends[i];
        if (i == 0) {
            for (int j=now.first; j<100; ++j){
                dp[i][j] = now.second;
            }
        }
        else {
            for (int k=0; k<100; ++k) {
                if (k < now.first) {
                    dp[i][k] = dp[i-1][k];
                }
                else if (k >= now.first) {
                    dp[i][k] = max(dp[i-1][k], dp[i-1][k-now.first] + now.second);
                }
            }
        }
    }

    cout << dp[N-1][99];
    
    return 0;
}
