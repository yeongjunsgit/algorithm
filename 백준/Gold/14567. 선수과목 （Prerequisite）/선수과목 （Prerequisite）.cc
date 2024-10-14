#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.first < b.first;
    }  
};

int N, M;

vector<int> results;
priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> que;
vector<vector<int> > graph;

void bfs()
{
    vector<bool> is_in(N+1, false);
    
    while (!que.empty()) {
        int now = que.top().second;
        que.pop();
        
        for (int a : graph[now]) {
            if (results[a] < results[now] + 1) {
                results[a] = results[now] + 1;
                que.push({results[a], a});
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    results.resize(N+1, 1);
    graph.resize(N+1);
    
    int s, e;
    vector<bool> check_base(N+1, true);
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        check_base[e] = false;
        graph[s].push_back(e);
    }
    
    for (int i=1; i<=N; ++i) {
        if (check_base[i] == true) {
            que.push({1, i});
        }
    }
    
    bfs();

    for (int i=1; i<=N; ++i) {
        cout << results[i] << " ";
    }

    return 0;
}
