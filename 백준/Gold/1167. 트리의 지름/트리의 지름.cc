#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>
#define INF 1000000001

using namespace std;

int N;
vector<vector<pll> > graph;

pll bfs(int start)
{
    int tmp = 0, tmp_dist = 0;
    
    queue<pll> que;
    que.push({start, 0});
    vector<int> visited(N+1, INF);
    visited[start] = 0;
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        if (visited[now.first] < now.second) {
            continue;
        }
        
        for (pll p : graph[now.first]) {
            int next = p.first;
            int next_dist = p.second + now.second;
            if (visited[next] > next_dist) {
                visited[next] = next_dist;
                que.push({next, next_dist});
                if (tmp_dist < next_dist) {
                    tmp_dist = next_dist;
                    tmp = next;
                }
            }
        }
    }
    
    return {tmp, tmp_dist};
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    graph.resize(N+1);
    
    int s, e, dist;
    for (int i=0; i<N; ++i) {
        cin >> s;
        int ways = 0;
        while (true) {
            cin >> e;
            if (e == -1) {
                break;
            }
            cin >> dist;
            graph[s].push_back({e, dist});
            ways++;
        }
    }
    
    pll tmp_point = bfs(1);
    pll result = bfs(tmp_point.first);
    
    cout << result.second;

    return 0;
}
