#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    
    int N;
    cin >> N;
    
    vector<vector<int>> visited(N, vector<int>(N, 0));
    
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    
    visited[sx][sy] = 1;
    
    queue<pair<int, int>> que;
    que.push({sx, sy});
    
    vector<pair<int, int>> direction = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
    
    int result = -1;
    
    bool is_over = false;
    
    while (!que.empty()) {
        if (is_over == true) {
            break;
        }
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<6; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == 0) {
                if (nx == ex && ny == ey) {
                    result = visited[now.first][now.second];
                    is_over = true;
                    break;
                }
                else {
                    visited[nx][ny] = visited[now.first][now.second] + 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    
    cout << result;
    
    return 0;
}
