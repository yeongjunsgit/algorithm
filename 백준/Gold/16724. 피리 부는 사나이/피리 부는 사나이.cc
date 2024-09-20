#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<vector<char> > graph;
vector<vector<int> > visited;
map<char, pair<int, int> > directions;
int cnt = 0;
int result = 0;

void dfs(int x, int y)
{
    int nx = x + directions[graph[x][y]].first;
    int ny = y + directions[graph[x][y]].second;
    
    if (visited[nx][ny] != 0) {
        if (visited[nx][ny] == cnt) {
            result++;
        }
        return;
    }
    else {
        visited[nx][ny] = cnt;
        dfs(nx, ny);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    directions['U'] = {-1, 0};
    directions['D'] = {1, 0};
    directions['L'] = {0, -1};
    directions['R'] = {0, 1};
    
    cin >> N >> M;
    visited.resize(N, vector<int>(M, 0));
    
    string data;
    
    for (int i=0; i<N; ++i) {
        vector<char> one_line;
        cin >> data;
        for (char c : data) {
            one_line.push_back(c);
        }
        graph.push_back(one_line);
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 0) {
                cnt++;
                visited[i][j] = cnt;
                dfs(i, j);
            }
        }
    }

    cout << result;
    
    return 0;
}
