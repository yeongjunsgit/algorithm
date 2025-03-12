#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > graph;

void get_a_bus()
{
    for (int k=1; k<=N; ++k) {
        for (int i=1; i<=N; ++i) {
            for (int j=1; j<=N; ++j) {
                if (i != j) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (graph[i][j] != 10000001) {
                cout << graph[i][j] << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    graph.resize(N + 1, vector<int>(N + 1, 10000001));
    
    for (int i=1; i<=N; ++i) {
        graph[i][i] = 0;
    }
    
    int s, e, dist;
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        if (graph[s][e] > dist) {
            graph[s][e] = dist;
        }
    }
    
    get_a_bus();

    return 0;
}
