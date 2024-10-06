#include <iostream>
#include <vector>

using namespace std;

int T, N, M;

int dfs(vector<vector<pair<int, int> > >& graph, int before, int now)
{
    if (graph[now].size() == 1 && now != 1) {
        return graph[now][0].first;
    }
    else if (graph[now].size() > 1 && now != 1) {
        int tmp = 0;
        int now_bridge = 0;
        for (auto a : graph[now]) {
            if (a.second != before) {
                tmp += dfs(graph, now, a.second);
            }
            else {
                now_bridge = a.first;
            }
        }
        
        return min(tmp, now_bridge);
    } 
    
    else {
        int result = 0;
        for (auto a : graph[now]) {
            result += dfs(graph, now, a.second);
        }
        
        cout << result << "\n";
        
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        
        vector<vector<pair<int, int> > > graph(N+1);
        int s, e, dist;
        for (int i=0; i<M; ++i) {
            cin >> s >> e >> dist;
            
            graph[s].push_back({dist, e});
            graph[e].push_back({dist, s});

        }
        
        dfs(graph, -1, 1);
        
    }

    return 0;
}
