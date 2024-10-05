#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<pair<long long, int> > > graph;
vector<long long> visited;
long long result = 0;

// struct Compare {
//     bool operator()(const pair<long long, int>& a, const pair<long long, int>& b) {
//         return a.first > b.first;
//     }
// };

void bfs()
{
    queue<pair<long long, int> > que;
    que.push({0, 1});
    
    while (!que.empty()) {
        pair<long long, int> now = que.front();
        que.pop();
        if (now.first < visited[now.second]) {
            continue;
        }
        
        for (auto a : graph[now.second]) {
            long long now_dist = now.first + a.first;
            if (visited[a.second] == 0) {
                visited[a.second] = now_dist;
                que.push({now_dist, a.second});
                if (visited[a.second] > result) {
                    result = visited[a.second];
                }
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    graph.resize(N+1);
    visited.resize(N+1, 0);
    
    int s, e;
    long long dist;
    for (int i=1; i<N; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({dist, e});
        graph[e].push_back({dist, s});
    }
    
    bfs();

    return 0;
}
