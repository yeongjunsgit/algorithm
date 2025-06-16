#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, start_loca, end_loca;
vector<vector<pll> > graph(10001);

struct Compare {
    bool operator()(const pll& a, const pll& b) {
        return a.first < b.first;
    }
};

int lets_go()
{
    vector<int> visited(N + 1, 0);
    visited[start_loca] = 1000000001;
    priority_queue<pll, vector<pll>, Compare> que;
    que.push({1000000001, start_loca});
    
    while (!que.empty()) {
        pll now = que.top();
        que.pop();
        if (visited[now.second] > now.first || visited[end_loca] > now.first) continue;
        
        for (pll p : graph[now.second]) {
            if (visited[p.first] < min(p.second, now.first) && visited[end_loca] < min(p.second, now.first)) {
                visited[p.first] = min(p.second, now.first);
                que.push({visited[p.first], p.first});
            }
        }
    }
    
    return visited[end_loca];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int s, e, dist;
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({e, dist});
        graph[e].push_back({s, dist});
    }
    cin >> start_loca >> end_loca;
    
    cout << lets_go();

    return 0;
}
