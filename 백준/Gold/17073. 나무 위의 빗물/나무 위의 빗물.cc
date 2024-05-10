#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    double water;
    cin >> N >> water;
    
    vector<vector<int>> graph(N+1);
    
    for (int i=1; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    double leaf_node = 0.0;
    
    for (int i=2; i<=N; ++i) {
        if (graph[i].size() == 1) {
            leaf_node += 1.0;
        }
    }
    
    double result = round((water / leaf_node) * 1e10) / 1e10;
    
    cout << fixed << setprecision(10) << result;

    return 0;
}
