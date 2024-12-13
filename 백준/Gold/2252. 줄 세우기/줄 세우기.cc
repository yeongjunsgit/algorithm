#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;

vector<bool> used;
vector<bool> is_print;
vector<unordered_map<int, int> > graph;

void dfs(int now)
{
    if (is_print[now] == false) {
        
        is_print[now] = true;
        
        for (auto a : graph[now]) {
            dfs(a.first);
        }
        cout << now << " ";
        
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    int s, e;
    
    used.resize(N+1, false);
    is_print.resize(N+1, false);
    graph.resize(N+1);
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        
        used[s] = true;
        graph[e][s] = 1;
        
    }
    
    for (int i=1; i<=N; ++i) {
        if (used[i] == false) {
            used[i] = true;
            dfs(i);
        }
    }

    return 0;
}
