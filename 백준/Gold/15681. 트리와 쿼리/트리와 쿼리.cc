#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;

vector<vector<int> > graph;
vector<int> childrens;

int bfs(int now, int before)
{
    int my_child = 1;
    
    if (graph[now].size() > 1 || now == R) {
        for (int a : graph[now]) {
            if (a != before) {
                int tmp = bfs(a, now);
                my_child += tmp;
            }
        }
        
    }
    childrens[now] = my_child;
    
    return my_child;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> R >> Q;
    
    graph.resize(N+1);
    childrens.resize(N+1, 0);
    
    int s, e;
    
    for (int i=0; i<N-1; ++i) {
        
        cin >> s >> e;
        
        graph[s].push_back(e);
        graph[e].push_back(s);
        
    }
    
    bfs(R, -1);
    
    for (int i=0; i<Q; ++i) {
        cin >> s;
        
        cout << childrens[s] << "\n";
        
    }

    return 0;
}
