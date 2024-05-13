#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct element {
    int dist;
    int now_loca;
    bool min_joon;
};

struct Compare {
    bool operator()(const element& a, const element& b ) const {
            return a.dist < b.dist;
    }
};

int main()
{
    
    int V, E, P;
    cin >> V >> E >> P;
    
    vector<vector<pair<int, int>>> graph(V+1, vector<pair<int, int>>());
    
    for (int i=0; i<E; ++i) {
        int a, b, dist;
        cin >> a >> b >> dist;
        
        graph[a].push_back({dist, b});
        graph[b].push_back({dist, a});
    
    }
    
    priority_queue<element, vector<element>, Compare> que;
    
    que.push({0, 1, false});
    
    vector<int> visited(V+1, 1000000);
    visited[1] = 0;
    
    string result = "GOOD BYE";
    int min_dist = 1000000;
    bool escape = false;
    
    if (P == 1) {
        result = "SAVE HIM";
    }
    
    while (!que.empty()) {
        element now = que.top();
        que.pop();
        
        if (now.dist > visited[V]) {
            continue;
        }
        
        else if (now.now_loca == V && now.dist == visited[V] && visited[V] !=1000000) {
            if (now.min_joon == true) {
                escape = true;
                continue;
            }
        } 
        
        if (graph[now.now_loca].size() > 0) {
            for (int i=0; i<graph[now.now_loca].size(); ++i) {
                pair<int, int> next_info = graph[now.now_loca][i];
                int next_node = next_info.second;
                int next_dist = now.dist + next_info.first;
                
                if (next_dist > visited[V]) {
                    continue;
                }
                
                if (visited[next_node] >= next_dist) {
                    if (next_node == V) {
                        if (next_node == P) {
                            que.push({next_dist, next_node, true});
                            if (visited[next_node] > next_dist) {
                                min_dist = next_dist;
                                escape = false;
                            }
                        }
                        else {
                            que.push({next_dist, next_node, now.min_joon});
                            if (visited[next_node] > next_dist) {
                                min_dist = next_dist;
                                escape = false;
                            }
                        }
                    }
                    else {
                        if (next_node == P) {
                            que.push({next_dist, next_node, true});
                        }
                        else {
                            que.push({next_dist, next_node, now.min_joon});
                        }
                    }
                    visited[next_node] = next_dist;
                }
            }
        }
    }
    
    if (escape == true) {
        result = "SAVE HIM";
    }
    
    cout << result;

    return 0;
}

