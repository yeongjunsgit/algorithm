#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<pair<int, pll> > ills;
vector<vector<vector<int> > > DP(100, vector<vector<int> >(51, vector<int>(51, -1)));

struct Compare {
    bool operator()(const pll& a, const pll& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

void make_dp()
{
    DP[0][0][0] = 0;
    for (int i=0; i<M; ++i) {
        pll now = ills[i].second;
        int now_danger = ills[i].first;
        if (i == 0) {
            DP[i][now.first][now.second] = now_danger;
        }
        else {
            for (int j=0; j<=50; ++j) {
                for (int k=0; k<=50; ++k) {
                    DP[i][j][k] = max(DP[i][j][k], DP[i-1][j][k]);
                    
                    if (j - now.first >= 0 && k - now.second >= 0 && DP[i-1][j - now.first][k - now.second] != -1) {
                        DP[i][j][k] = max(DP[i][j][k], DP[i-1][j - now.first][k - now.second] + now_danger);
                    }
                } 
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int red, blue, danger;
    for (int i=0; i<M; ++i) {
        cin >> red >> blue >> danger;
        ills.push_back({danger, {red, blue}});
    }
    
    make_dp();
    priority_queue<pll, vector<pll>, Compare> que;
    
    for (int i=1; i<=N; ++i) {
        cin >> red >> blue;
        que.push({i, max(0, DP[M-1][red][blue])});
    }
    
    while (!que.empty()) {
        cout << que.top().first << " " << que.top().second << "\n";
        que.pop();
    }

    return 0;
}
