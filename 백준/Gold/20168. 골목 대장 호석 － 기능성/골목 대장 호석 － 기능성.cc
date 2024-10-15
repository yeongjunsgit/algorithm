#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, A, B, C;
vector<vector<pair<int, int> > > graph;

struct my_node {
    int left_money;
    int loca;
    int max_power;
};

struct Compare {
    bool operator()(const my_node& a, const my_node& b) {
        return a.left_money < b.left_money;
    }
};

void bfs()
{
    int result = 10001;
    priority_queue<my_node, vector<my_node>, Compare> que;
    que.push({C, A, 0});
    
    while (!que.empty()) {
        my_node now = que.top();
        que.pop();
        if (now.max_power > result) {
            continue;
        }
        
        for (auto a : graph[now.loca]) {
            if (now.left_money - a.first >= 0) {
                int next_money = now.left_money - a.first;
                int next_power = max(now.max_power, a.first);
                if (a.second == B) {
                    result = min(result, next_power);
                }
                else {
                    que.push({next_money, a.second, next_power});
                }
            }
        }
    }
    
    if (result == 10001) {
        cout << -1;
    }
    else {
        cout << result;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> A >> B >> C;
    
    graph.resize(N+1);
    int s, e, dist;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({dist, e});
    }
    
    bfs();

    return 0;
}
