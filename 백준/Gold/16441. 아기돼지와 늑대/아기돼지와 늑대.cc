#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<char> > board(100, vector<char>(100, ' '));
vector<vector<int> > visited(100, vector<int>(100, 0));
queue<pll> wolves;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void find_safe()
{
    while (!wolves.empty()) {
        pll now = wolves.front();
        wolves.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] != '#') {
                if (board[nx][ny] == '.' && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    wolves.push({nx, ny});
                }
                else if (board[nx][ny] == '+') {
                    while (board[nx][ny] == '+') {
                        nx += directions[i].first;
                        ny += directions[i].second;
                    }
                    
                    if (board[nx][ny] == '#') {
                        nx -= directions[i].first;
                        ny -= directions[i].second;
                    }
                    if (visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        wolves.push({nx, ny});
                    }
                }
            } 
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j] == '.' && visited[i][j] == 0) {
                cout << 'P';
            }
            else {
                cout << board[i][j];
            }
        }
        cout << "\n";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'W') {
                wolves.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    
    find_safe();

    return 0;
}
