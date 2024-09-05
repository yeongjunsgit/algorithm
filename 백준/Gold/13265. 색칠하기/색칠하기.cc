#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M;

bool bfs(vector<vector<int> >& graph, int start) 
{
    queue<int> que;
    que.push(start);
    vector<int> visited(N+1, 0);
    visited[start] = 1;
    
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        int color = visited[now];
        
        if (graph[now].size() > 0) {
            for (int a : graph[now]) {
                if (visited[a] == 0) {
                    if (color == 1) {
                        visited[a] = 2;
                    }
                    else {
                        visited[a] = 1;
                    }
                    que.push(a);
                }
                else {
                    if (visited[a] == color) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        
        int s, e;
        vector<vector<int> > graph(N+1);
        int start = -1;
        
        for (int i=0; i<M; ++i) {
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
            
            if (start == -1) {
                start = s;
            }
        }
        
        bool result = bfs(graph, start);
        
        if (result == true) {
            cout << "possible" << "\n";
        }
        else {
            cout << "impossible" << "\n";
        }
        
    }

    return 0;
}
