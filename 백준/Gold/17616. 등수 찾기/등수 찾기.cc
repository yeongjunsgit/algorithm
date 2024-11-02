#include <iostream>
#include <vector>

using namespace std;

int N, M, X;
vector<vector<int> > upper_graph;
vector<vector<int> > lower_graph;
vector<int> visited;
int tmp = 0;

void dfs(vector<vector<int> >& graph, int now)
{
    for (int a : graph[now]) {
        if (visited[a] == 0) {
            visited[a] = 1;
            tmp++;
            dfs(graph, a);
        }
    }

    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> X;
    int s, e;
    upper_graph.resize(N+1);
    lower_graph.resize(N+1);
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        
        upper_graph[e].push_back(s);
        lower_graph[s].push_back(e);
        
    }
    
    int max_grade = 1;
    int min_grade = N;
    visited.resize(N+1, 0);
    dfs(upper_graph, X);
    int upper_size = tmp;
    visited.resize(N+1, 0);
    tmp = 0;
    dfs(lower_graph, X);
    int lower_size = tmp;
    
    cout << max_grade + upper_size << " " << min_grade - lower_size;

    return 0;
}
