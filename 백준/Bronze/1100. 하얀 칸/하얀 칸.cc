#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char> > board;

int result = 0;

vector<pair<int, int> > direction = {{0, 1}, {1, 0}};

void bfs()
{
    queue<pair<int, int> > que;
    que.push({0, 0});
    vector<vector<int> > visited(8, vector<int>(8, -1));
    visited[0][0] = 0;
    if (board[0][0] == 'F') {
        result++;
    }
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<2; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && visited[nx][ny] == -1) {
                visited[nx][ny] = (visited[now.first][now.second] + 1) % 2;
                que.push({nx, ny});
                if (visited[nx][ny] == 0 && board[nx][ny] == 'F') {
                    result++;
                }
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    string data;
    for (int i=0; i<8; ++i) {
        cin >> data;
        vector<char> one_line;
        for (char c : data) {
            one_line.push_back(c);
        }
        board.push_back(one_line);
    }
    
    bfs();

    return 0;
}