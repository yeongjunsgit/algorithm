#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<pll> > graph(4001);
vector<vector<int>> visited(3, vector<int>(4001, 999999999));

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.second.second > b.second.second;
    }
};

void find_moon()
{
    priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
    que.push({0, {1, 0}}); que.push({1, {1, 0}});
    
    while (!que.empty()) {
        int now_kind = que.top().first;
        int now = que.top().second.first;
        int move_speed = que.top().second.second;
        que.pop();
        if (now_kind == 0) {
            if (move_speed > visited[0][now]) continue;
        }
        else if (now_kind == 1) {
            if (move_speed > visited[2][now]) continue;
        }
        else {
            if (move_speed > visited[1][now]) continue;
        }
        
        for (auto a : graph[now]) {
            if (now_kind == 0) {
                if (visited[now_kind][a.first] > move_speed + a.second) {
                    visited[now_kind][a.first] = move_speed + a.second;
                    que.push({now_kind, {a.first, move_speed + a.second}});
                }
            }
            else if (now_kind == 1) {
                if (visited[now_kind][a.first] > move_speed + a.second / 2) {
                    visited[now_kind][a.first] = move_speed + a.second / 2;
                    que.push({2, {a.first, visited[now_kind][a.first]}});
                }
            }
            else {
                if (visited[now_kind][a.first] > move_speed + a.second * 2) {
                    visited[now_kind][a.first] = move_speed + a.second * 2;
                    que.push({1, {a.first, visited[now_kind][a.first]}});
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
    int s, e, dist;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({e, dist * 2});
        graph[e].push_back({s, dist * 2});
    }
    
    find_moon();
    
    int cnt = 0;
    for (int i=2; i<=N; ++i) {
        // cout << "Fox " << visited[0][i] << " Wolf one " << visited[1][i] << " Wolf two " << visited[2][i] << "\n";
        if (visited[0][i] < visited[1][i] && visited[0][i] < visited[2][i]) {
            cnt++;
        }
    }
    
    cout << cnt;

    return 0;
}
