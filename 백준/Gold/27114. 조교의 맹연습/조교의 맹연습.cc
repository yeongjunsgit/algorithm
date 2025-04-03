#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int numbers[3]; 
int K;
vector<int> directions = {3, 1, 2};

void lets_rock()
{
    vector<vector<int> > dp(K+1, vector<int>(4, -1));
    dp[0][0] = 0;
    for (int i=0; i<K; ++i) {
        for (int j=0; j<4; ++j) {
            if (dp[i][j] == -1) continue;
            
            for (int k=0; k<3; ++k) {
                int power = i + numbers[k];
                int next = (j + directions[k]) % 4;
                if (power <= K && (dp[power][next] == -1 || dp[power][next] > dp[i][j] + 1)) dp[power][next] = dp[i][j] + 1;
            }
            
        }
    }
    
    cout << dp[K][0];
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
       
    cin >> numbers[0] >> numbers[1] >> numbers[2] >> K;
    
    lets_rock();

    return 0;
}
