#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, W;
vector<vector<int> > graph;

void floyd()
{
    for (int k=1; k<=N; ++k) {
        for (int i=1; i<=N; ++i) {
            for (int j=1; j<=N; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    for (int i=1; i<=N; ++i) {
        if (graph[i][i] < 0) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M >> W;
        int s, e, dist;
        graph.clear();
        graph.resize(N+1, vector<int>(N+1, 10001));
        
        for (int i=0; i<M; ++i) {
            cin >> s >> e >> dist;
            if (graph[s][e] > dist) graph[s][e] = dist;
            if (graph[e][s] > dist) graph[e][s] = dist;
        }
        
        for (int i=0; i<W; ++i) {
            cin >> s >> e >> dist;
            if (graph[s][e] > dist * -1) {
                graph[s][e] = dist * -1;
            } 
        }
        
        floyd();
        
    }

    return 0;
}
