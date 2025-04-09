#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int N, M;

vector<vector<int> > visited, board;
vector<pair<int, int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int result = 0, color = 0;
unordered_map<int, int> color_power;

void bfs(int x, int y, int num_type)
{
    if (num_type == 0) {
        visited[x][y] = -1;
        unordered_set<int> connected;
        int tmp = 1;
        for (int i=0; i<4; ++i) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 1) {
                connected.insert(visited[nx][ny]);
            }
        }
        for (auto a : connected) {
            tmp += color_power[a];
        }
        result = max(result, tmp);
        // cout << x << " " << y << " " << tmp << "\n";
        
    }
    else {
        color++;
        int cnt = 1;
        queue<pair<int, int> > que;
        que.push({x, y});
        visited[x][y] = color;
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            for (int i=0; i<4; ++i) {
                int nx = now.first + directions[i].first;
                int ny = now.second + directions[i].second;
                
                if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 1 && visited[nx][ny] == 0) {
                    cnt++;
                    que.push({nx, ny});
                    visited[nx][ny] = color;
                }
            }
        }
        color_power[color] = cnt;
    }
    
    return;
}

void check_power()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 0 && board[i][j] == 1) {
                bfs(i, j, 1);
            }
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 0 && board[i][j] == 0) {
                bfs(i, j, 0);
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    visited.resize(N, vector<int>(M, 0));
    board.resize(N, vector<int>(M, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    
    check_power();
    
    cout << result;
    
    return 0;
}
