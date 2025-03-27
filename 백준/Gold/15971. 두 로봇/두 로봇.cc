#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, S, E;
vector<vector<pll> > graph;

void dfs()
{
    vector<int> stacker, passed_length;
    stacker.push_back(S);
    vector<int> visited(N+1, 0);
    visited[S] = 1;
    while (stacker.back() != E) {
        int now = stacker.back();
        for (pll p : graph[now]) {
            if (visited[p.first] == 0) {
                visited[p.first] = 1;
                stacker.push_back(p.first);
                passed_length.push_back(p.second);
                break;
            }
        }
        if (stacker.back() == now) {
            stacker.pop_back();
            passed_length.pop_back();
        }
    }
    
    int max_length = 0;
    int total = 0;
    for (int a : passed_length) {
        total += a;
        max_length = max(max_length, a);
    }
    
    cout << total - max_length;
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> S >> E;
    graph.resize(N+1);
    int s, e, dist;
    for (int i=0; i<N - 1; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({e, dist});
        graph[e].push_back({s, dist});
    }
    if (N > 1) {
        dfs();    
    }
    else {
        cout << 0;
    }

    return 0;
}
