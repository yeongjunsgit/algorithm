#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int> > graph;
vector<int> believe_time;
vector<pair<int, int> > visited;
queue<int> que;

void spread_rumor()
{
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        
        for (int a : graph[now]) {
            if (believe_time[a] == -1) {
                visited[a].first += 1;
                visited[a].second = max(visited[a].second, believe_time[now]);
                if (visited[a].first >= graph[a].size() / 2.0) {
                    believe_time[a] = visited[a].second + 1;
                    que.push(a);
                }
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    graph.resize(N+1);
    believe_time.resize(N+1, -1);
    visited.resize(N+1, {0, -1});
    
    string data;
    int num;
    
    for (int i=1; i<=N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        
        while (iss >> num) {
            if (num != 0) {
                graph[i].push_back(num);
            }
        }
    }
    
    cin >> M;
    cin.ignore();
    getline(cin, data);
    istringstream iss(data);
    
    while (iss >> num) {
        believe_time[num] = 0;
        que.push(num);
    }
    
    spread_rumor();
    
    for (int i=1; i<=N; ++i) {
        cout << believe_time[i] << " ";
    }

    return 0;
}
