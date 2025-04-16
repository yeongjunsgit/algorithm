#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int N;
vector<int> buildings, left_view, right_view, left_dp, right_dp;

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.first > b.first;
    }
};

int dfs(int x, vector<int>& target_lis, vector<int>& target_dp)
{
    if (target_dp[x] != -1) {
        return target_dp[x] + 1;
    }
    
    if (target_lis[x] == 0) {
        target_dp[x] = 0;
        return 1;
    }
    else {
        target_dp[x] = dfs(target_lis[x], target_lis, target_dp);
        return target_dp[x] + 1;
    }
}

void lets_see()
{
    for (int i=1; i<=N; ++i) {
        if (right_dp[i] == -1) {
            dfs(i, right_view, right_dp);
        }
    }
    for (int i=N; i>=1; --i) {
        if (left_dp[i] == -1) {
            dfs(i, left_view, left_dp);
        }
    }
    
    for (int i=1; i<=N; ++i) {
        if (left_dp[i] + right_dp[i] == 0) {
            cout << 0 << "\n";
        }
        else {
            int left_loca = 999999, right_loca = 999999, near_loca;
            if (left_view[i] != 0) {
                left_loca = i - left_view[i];
            }
            if (right_view[i] != 0) {
                right_loca = right_view[i] - i;
            }
            if (left_loca > right_loca) near_loca = right_view[i];
            else near_loca = left_view[i];
            
            cout << left_dp[i] + right_dp[i] << " " << near_loca << "\n";
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    left_view.resize(N+1, 0); right_view.resize(N+1, 0); buildings.resize(N+1, 0); right_dp.resize(N+1, -1); left_dp.resize(N+1, -1);
    priority_queue<pll, vector<pll>, Compare> que, m_que;
    
    for (int i=1; i<=N; ++i) {
        cin >> buildings[i];
        if (que.empty()) {
            que.push({buildings[i], i});
        }
        else {
            while (!que.empty() && que.top().first < buildings[i]) {
                pll now = que.top();
                que.pop();
                right_view[now.second] = i;
            }
            que.push({buildings[i], i});
        }
    }
    
    
    for (int i=N; i>=1; --i) {
        if (m_que.empty()) {
            m_que.push({buildings[i], i});
        }
        else {
            while (!m_que.empty() && m_que.top().first < buildings[i]) {
                pll now = m_que.top();
                m_que.pop();
                left_view[now.second] = i;
            }
            m_que.push({buildings[i], i});
        }
    }
    
    lets_see();
    

    return 0;
}
