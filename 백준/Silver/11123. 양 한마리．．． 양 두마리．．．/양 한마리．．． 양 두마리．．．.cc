#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<int>>& visited, vector<vector<char>>& farm, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = 1;
    
    while(!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && farm[nx][ny] == '#' && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                que.push({nx, ny});
            }
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        
        vector<vector<char>> farm;
        
        string data;
        for (int i=0; i<N; ++i) {
            cin >> data;
            vector<char> one_line;
            for (char c : data) {
                one_line.push_back(c);
            }
            farm.push_back(one_line);
        }
    
        int result = 0;
        vector<vector<int>> visited(N, vector<int>(M, 0));
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (farm[i][j] == '#' && visited[i][j] == 0) {
                    bfs(visited, farm, i, j);
                    result += 1;
                }
            }
        }
        
        cout << result << "\n";
    }

    return 0;
}
