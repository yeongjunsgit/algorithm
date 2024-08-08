#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, K;

void check_this_room(vector<vector<pair<int, int>>>& graph, vector<int>& friends, int& min_dist, int& most_close, int now) {
    vector<int> visited(N+1, 99999999);
    visited[now] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>> que;
    que.push({0, now});
    
    while (!que.empty()) {
        pair<int, int> my_loca = que.top();
        que.pop();
        
        if (graph[my_loca.second].size() != 0) {
            for (auto p : graph[my_loca.second]) {
                int next_node = p.second;
                int next_dist = my_loca.first + p.first;
                
                if (visited[next_node] > next_dist) {
                    visited[next_node] = next_dist;
                    que.push({next_dist, next_node});
                }
            }
        }
    }
    
    int tmp = 0;
    
    for (int i=0; i<K; ++i) {
        tmp += visited[friends[i]];
    }
    
    if (min_dist > tmp) {
        min_dist = tmp;
        most_close = now;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        int s, e, dist;
        vector<vector<pair<int, int>>> graph(N+1);
        for (int i=0; i<M; ++i) {
            cin >> s >> e >> dist;
            graph[s].push_back({dist, e});
            graph[e].push_back({dist, s});
        }
        
        cin >> K;
        vector<int> friends;
        int person;
        for (int k=0; k<K; ++k) {
            cin >> person;
            friends.push_back(person);
        }
        
        int min_dist = 99999999;
        int most_close = 0;
        
        for (int i=1; i<=N; ++i) {
            check_this_room(graph, friends, min_dist, most_close, i);
        }
        
        cout << most_close << "\n";
        
    }

    return 0;
}
