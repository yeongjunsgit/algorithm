#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K, W;

vector<int> building_time;
vector<int> before_building;
vector<int> visited;
vector<vector<int> > up_graph;

void bfs(queue<int>& que)
{
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        
        visited[now] += building_time[now];
        
        if (now == W) {
            cout << visited[now] << "\n";
            return;
        }
        
        for (int a : up_graph[now]) {
            visited[a] = max(visited[now], visited[a]);
            
            before_building[a]--;
            if (before_building[a] == 0) {
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
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> K;
        cin.ignore();
        
        building_time.assign(1, 0);
        before_building.assign(N+1, 0);
        visited.assign(N+1, 0);
        up_graph.assign(N+1, vector<int>());
        
        string data;
        getline(cin, data);
        istringstream iss(data);
        int num;
        while (iss >> num) {
            building_time.push_back(num);
        }
        
        int s, e;
        for (int i=0; i<K; ++i) {
            cin >> s >> e;
            up_graph[s].push_back(e);
            before_building[e]++;
        }
        
        
        queue<int> que;
        
        for (int i=1; i<=N; ++i) {
            if (before_building[i] == 0) {
                que.push(i);
            }
        }
        
        cin >> W;
        
        if (before_building[W] == 0) {
            cout << building_time[W] << "\n";
        }
        else {
            bfs(que);
        }
        
    }

    return 0;
}
