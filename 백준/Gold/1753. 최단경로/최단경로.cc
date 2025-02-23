#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define pll pair<int, int>

using namespace std;

int V, E, K;
unordered_map<int, unordered_map<int, int> > graph;

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.first > b.first;
    }
};

void find_dist()
{
    vector<int> visited(V+1, 20000001);
    visited[K] = 0;
    priority_queue<pll, vector<pll>, Compare> que;
    que.push({0, K});
    
    while (!que.empty()) {
        pll now = que.top();
        que.pop();
        
        if (now.first > visited[now.second]) {
            continue;
        }
        
        for (auto p : graph[now.second]) {
            int next_dist = now.first + p.second;
            if (visited[p.first] > next_dist) {
                visited[p.first] = next_dist;
                que.push({next_dist, p.first});
            }
        }
    }
    
    for (int i=1; i<=V; ++i) {
        if (visited[i] != 20000001) {
            cout << visited[i] << "\n";
        }
        else {
            cout << "INF" << "\n";
        }
    }
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> V >> E >> K;
    
    int s, e, dist;
    for (int i=0; i<E; ++i) {
        cin >> s >> e >> dist;
        
        if (graph[s].find(e) == graph[s].end()) {
            graph[s][e] = dist;
        }
        else {
            if (graph[s][e] > dist) {
                graph[s][e] = dist;
            }
        }
    }
    
    find_dist();

    return 0;
}
