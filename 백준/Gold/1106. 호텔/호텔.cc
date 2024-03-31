#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

int main()
{
    int target, citys;
    cin >> target >> citys;
    
    int dp[1101];
    
    fill(dp+1, dp + 1101, 123456789);
    dp[0] = 0;
    
    int result = 123456789;
    
    vector<pair<int, int>> matching;
    
    for (int i=0; i<citys; ++i) {
        int cost, people;
        cin >> cost >> people;
        
        pair<int, int> match{cost, people};
        
        matching.push_back(match);

    }
    
    for (int j=0; j<citys; ++j) {
        for (int i=0; i<target; ++i) {
            dp[i + matching[j].second] = min(dp[i + matching[j].second], dp[i] + matching[j].first);
            
            if (i + matching[j].second >= target) {
                result = min(result, dp[i + matching[j].second]);
            }
        }
    }

    cout << result;

    return 0;
}