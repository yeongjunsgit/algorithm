#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<vector<int> > graph;
vector<int> visited;
priority_queue<int, vector<int>, greater<int> > que;

void bfs()
{
    while (!que.empty()) {
        int now = que.top();
        que.pop();
        cout << now << " ";
        
        for (int a : graph[now]) {
            visited[a]--;
            if (visited[a] == 0) {
                que.push(a);
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int s, e;
    graph.resize(N+1);
    visited.resize(N+1, 0);
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        visited[e]++;
    }
    
    for (int i=1; i<=N; ++i) {
        if (visited[i] == 0) {
            que.push(i);
        }
    }
    
    bfs();
    
    return 0;
}
