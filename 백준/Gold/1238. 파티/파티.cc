#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>
#define INF 2000001
using namespace std;

vector<vector<pll> > graph;

int N, M, X;
int result = 0;

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.first > b.first;
    }
};


void go_to_party(int start)
{
    vector<int> visited(N+1, INF);
    visited[start] = 0;
    priority_queue<pll, vector<pll>, Compare> que;
    que.push({0, start});
    
    while (!que.empty()) {
        pll now = que.top();
        que.pop();
        
        if (now.first > visited[X]) {
            continue;
        }
        
        for (pll p : graph[now.second]) {
            int next_dist = now.first + p.first;
            if (visited[X] > next_dist && visited[p.second] > next_dist) {
                que.push({next_dist, p.second});
                visited[p.second] = next_dist;
            }
        }
    }
    
    que.push({visited[X], X});
    vector<int> next_visited(N+1, INF);
    next_visited[X] = visited[X];
    
    while (!que.empty()) {
        pll now = que.top();
        que.pop();
        
        if (now.first > next_visited[start]) {
            continue;
        }
        
        for (pll p : graph[now.second]) {
            int next_dist = now.first + p.first;
            if (next_visited[start] > next_dist && next_visited[p.second] > next_dist) {
                que.push({next_dist, p.second});
                next_visited[p.second] = next_dist;
            }
        }
    }
    
    if (result < next_visited[start]) {
        result = next_visited[start];
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> X;
    graph.resize(N+1);
    
    int s, e, dist;
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        
        graph[s].push_back({dist, e});
    }
    
    for (int i=1; i<=N; ++i) {
        go_to_party(i);
    }
    
    cout << result;

    return 0;
}
