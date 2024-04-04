#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>


using namespace std;

int main()
{
    int start, over;
    cin >> start >> over;
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph;
    
    for (int j=0; j<N+1; ++j) {
        vector<int> lines;
        graph.push_back(lines);
    }
    
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }  
    
    int visited[N+1];
    fill(visited, visited + N + 1, 1000000);
    
    visited[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    
    que.push({0, start});
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        // cout << now.first << " " << now.second << "\n";
        que.pop();
        if (visited[now.second] < now.first) {
            continue;
        }
        
        if (graph[now.second].size() != 0) {
            for (int g=0; g<graph[now.second].size(); ++g) {
                int next_node = graph[now.second][g];
                if (visited[next_node] > visited[now.second] + 1) {
                    visited[next_node] = visited[now.second] + 1;
                    que.push({visited[next_node], next_node});
                }
            }
        }
    }
    
    if (visited[over] == 1000000){
        cout << "-1";
    }
    
    else{
        cout << visited[over];
    }

    return 0;
}
