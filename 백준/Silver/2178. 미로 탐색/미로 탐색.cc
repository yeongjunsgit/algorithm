#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> board;
    
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        vector<int> one_line;
        for (char c : data) {
            one_line.push_back(c - '0');
        }
        board.push_back(one_line);
    }
    
    queue<pair<int, int>> que;
    vector<vector<int>> visited(N, vector<int>(M, -1));
    que.push({0, 0});
    visited[0][0] = 0;
    
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool is_over = false;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (visited[nx][ny] == -1 && board[nx][ny] == 1) {
                    visited[nx][ny] = visited[now.first][now.second] + 1;
                    if (nx == N-1 && ny == M-1) {
                        is_over = true;
                        break;
                    }
                    else {
                        que.push({nx, ny});
                    }
                }
            }
        }
        
        if (is_over == true) {
            break;
        }
    }
    
    cout << visited[N-1][M-1] + 1;

    return 0;
}
