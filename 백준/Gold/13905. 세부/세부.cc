#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, S, E;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> S >> E;
    
    vector<vector<pair<int, int>>> graph(N+1);
    
    int s, e, dist;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        
        graph[s].push_back({dist, e});
        graph[e].push_back({dist, s});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    vector<int> visited(N+1, 0);
    visited[S] = 999999999;
    
    que.push({999999999, S});
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        // 현재 값이 도착지에 저장된 최대무게보다 작다면 패스
        if (now.first < visited[E]) {
            continue;
        }
        if (now.first < visited[now.second]) {
            continue;
        }
        
        // 현재 위치에 연결된 곳이 있는지 확인
        if (graph[now.second].size() != 0) {
            // 있으면 연결된 곳을 전부 순회하여 확인
            for (int i=0; i<graph[now.second].size(); ++i) {
                // 만약 연결된 곳의 최대무게가 해당위치의 이전의 최대무게보다 크다면
                if (graph[now.second][i].first > visited[graph[now.second][i].second]) {
                    // 만약 현재 위치의 최대무게가 이동하고자하는 위치의 최대무게보다 크거나 같다면
                    if (now.first >= graph[now.second][i].first) {
                        // 이동한 위치의 최대무게를 기록하고 저장
                        visited[graph[now.second][i].second] = graph[now.second][i].first;
                        que.push({graph[now.second][i].first, graph[now.second][i].second});
                    }
                    // 이동하는 위치의 최대무게가 더 크다면
                    else {
                        // 현재 최대무게보다 커질 수는 없으니 현재 최대무게가 이동위치의 기록된 값보다 큰지 확인하고 크다면 기록하고 저장
                        if (now.first > visited[graph[now.second][i].second]) {
                            visited[graph[now.second][i].second] = now.first;
                            que.push({now.first, graph[now.second][i].second});
                        }
                    }
                }
            }
        }
    }
    
    cout << visited[E];

    return 0;
}
