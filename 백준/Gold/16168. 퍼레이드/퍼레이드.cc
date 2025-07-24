#include <iostream>
#include <vector>

using namespace std;

int V, E;
vector<vector<int> > graph(3001);
bool visited[3001];
vector<int> degree(3001, 0);

void lets_move(int now)
{
    visited[now] = true;
    for (int a : graph[now]) {
        if (!visited[a]) lets_move(a);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    int s, e;
    for (int i=0; i<E; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
        degree[e]++;
        degree[s]++;

    }
    
    lets_move(1);
    
    for (int i=1; i<=V; ++i) {
        if (!graph[i].empty() && !visited[i]) {
            cout << "NO";
            return 0;
        }
    }
    
    int odd_cnt = 0;
    for (int i=1; i<=V; ++i) {
        if (degree[i] % 2 != 0) odd_cnt++;
    }
    
    if (odd_cnt == 0 || odd_cnt == 2) cout << "YES";
    else cout << "NO";

    return 0;
}
