#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int start_node;

bool dfs(vector<vector<int>>& graph, vector<int>& visited, vector<bool>& in_circle, int now, int before) {
    for (auto a : graph[now]) {
        if (a != before && visited[a] == -1) {
            visited[a] = 1;
            bool make_circle = dfs(graph, visited, in_circle, a, now);
            visited[a] = -1;
            
            if (make_circle == true) {
                if (in_circle[now] != true) {
                    in_circle[now] = true;
                    return true;
                }
            }
        }
        
        else if (a != before && visited[a] == 1) {
            in_circle[a] = true;
            start_node = a;
            in_circle[now] = true;
            return true;
        }
        
    }
    return false;
}

void bfs(vector<vector<int>> graph, vector<int>& circle_visited, vector<bool>& in_circle) {
    queue<int> que;
    que.push(start_node);
    circle_visited[start_node] = 0;
    
    while(!que.empty()) {
        int node = que.front();
        que.pop();
        
        for (auto a : graph[node]) {
            if (in_circle[a] == true && circle_visited[a] == -1) {
                circle_visited[a] = 0;
                que.push(a);
            }
            
            else if (in_circle[a] == false && circle_visited[a] == -1) {
                circle_visited[a] = circle_visited[node] + 1;
                que.push(a);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    vector<vector<int>> graph(N+1);
    vector<int> visited(N+1, -1);
    vector<int> circle_visited(N+1, -1);
    vector<bool> in_circle(N+1, false);
    
    int s, e;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    dfs(graph, visited, in_circle, 1, -1);
    bfs(graph, circle_visited, in_circle);

    for (int i=1; i <= N; ++i) {
        cout << circle_visited[i] << " ";
    }

    return 0;
}
