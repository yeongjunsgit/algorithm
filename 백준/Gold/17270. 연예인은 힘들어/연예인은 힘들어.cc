#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// V = 약속 장소의 개수, M = 길의 개수, J = 지현이의 위치, S = 성하의 위치
int V, M, J, S;

vector<vector<int> > dist_graph;

void prouid()
{
    for (int i=1; i<=V; ++i) {
        dist_graph[i][i] = 0;
    }
    
    for (int k=1; k<=V; ++k) {
        for (int i=1; i<=V; ++i) {
            for (int j=1; j<=V; ++j) {
                dist_graph[i][j] = min(dist_graph[i][k] + dist_graph[k][j], dist_graph[i][j]);
                // cout << i << " " << j << " " << k << " " << dist_graph[i][j] << "\n";
            }
        }
    }
    
    int result = 100000000;
    vector<int> best_loca;
    int best_node = V+1;
    int near_from_J = 100000000;
    
    for (int i=1; i<=V; ++i) {
            if (i != J && i != S) {
                int tmp = dist_graph[J][i] + dist_graph[S][i];
                if (result > tmp) {
                    result = tmp;
            }
        }
    }
    
    for (int i=1; i<=V; ++i) {
        if (i != J && i != S) {
            int tmp = dist_graph[J][i] + dist_graph[S][i];
            
            if (result == tmp && dist_graph[J][i] <= dist_graph[S][i] && near_from_J > dist_graph[J][i]) {
                near_from_J = dist_graph[J][i];
            }
        }
    }
    
    for (int i=1; i<=V; ++i) {
        if (i != J && i != S) {
            int tmp = dist_graph[J][i] + dist_graph[S][i];
            if (result == tmp && dist_graph[J][i] == near_from_J) {
                best_loca.push_back(i);
            }
        }
    }
    
    for (int i : best_loca) {
        if (dist_graph[J][i] <= dist_graph[S][i]) {
            if (best_node > i) {
                best_node = i;
            }
        }
    }
    
    if (best_node == V+1) {
        cout << -1;
    }
    else {
        cout << best_node;
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> M;
    int s, e, dist;
    dist_graph.resize(V+1, vector<int>(V+1, 100000000));
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        
        if (dist_graph[s][e] > dist) {
            dist_graph[s][e] = dist;
        }
        if (dist_graph[e][s] > dist) {
            dist_graph[e][s] = dist;
        }
        
    }
    
    cin >> J >> S;
    
    prouid();

    return 0;
}
