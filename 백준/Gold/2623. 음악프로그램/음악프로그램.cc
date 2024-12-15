#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> result, get_power;
vector<vector<int> > graph;

void bfs()
{
    queue<int> que;
    
    for (int i=1; i<=N; ++i) {
        if (get_power[i] == 0) {
            que.push(i);
        }
    }
    
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        result.push_back(now);
        
        for (auto a : graph[now]) {
            get_power[a]--;
            if (get_power[a] == 0) {
                que.push(a);
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
    cin.ignore();
    
    graph.resize(N+1);
    get_power.resize(N+1, 0);
    
    int num, now, before;
    
    for (int i=0; i<M; ++i) {
        before = 0;
        now = 0;
        num = 0;
        cin >> num;
        if (num == 0) continue;
        cin >> before;
        if (num == 1) continue;
        
        for (int j=1; j < num; ++j) {
            cin >> now;
            graph[before].push_back(now);
            get_power[now]++;
            before = now;
        } 
    }
    
    bfs();

    if (result.size() != N) {
        cout << 0;
    }
    else {
        for (int a : result) {
            cout << a << "\n";
        }
    }

    return 0;
}
