#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
int N;

void bfs(int& answer, vector<int> info, int now, int sheep, int wolves)
{
    if (sheep != 0 && sheep == wolves) {
        return;
    }
    
    if (info[now] == 0) {
        sheep++;
    }
    else {
        wolves++;
    }
    
    answer = max(sheep, answer);
    
    for (int a : graph[now]) {
        visited[a] = true;
    }
    
    for (int i=0; i<N; ++i) {
        if (visited[i] == true) {
            visited[i] = false;
            bfs(answer, info, i, sheep, wolves);
            visited[i] = true;
        }
    }
    
    for (int a : graph[now]) {
        visited[a] = false;
    }
    
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    N = info.size();
    graph.resize(N);
    visited.resize(N, false);
    
    for (vector<int> v : edges) {
        graph[v[0]].push_back(v[1]);
    }
    
    bfs(answer, info, 0, 0, 0);
    
    return answer;
}