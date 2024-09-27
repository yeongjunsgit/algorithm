#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int> > board(501, vector<int>(501, 0));
vector<vector<int> > visited(501, vector<int>(501, 250001));
vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Compare{
    bool operator()(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
        return a.first > b.first; 
    }
};

void bfs()
{
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, Compare> que;
    que.push({0, {0, 0}});
    visited[0][0] = 0;
    
    while (!que.empty()) {
        pair<int, pair<int, int> > now = que.top();
        que.pop();
        
        if (visited[now.second.first][now.second.second] < now.first) {
            continue;
        }
        
        for (int i=0; i<4; ++i) {
            int nx = now.second.first + direction[i].first;
            int ny = now.second.second + direction[i].second;
            
            if (0 <= nx && nx < 501 && 0 <= ny && ny < 501) {
                if (board[nx][ny] == 2) {
                    continue;
                }
                else if (board[nx][ny] == 1) {
                    if (visited[nx][ny] > visited[now.second.first][now.second.second] + 1) {
                        que.push({visited[now.second.first][now.second.second] + 1, {nx, ny}});
                        visited[nx][ny] = visited[now.second.first][now.second.second] + 1;
                    }
                }
                
                else if (board[nx][ny] == 0) {
                    if (visited[nx][ny] > visited[now.second.first][now.second.second]) {
                        que.push({visited[now.second.first][now.second.second], {nx, ny}});
                        visited[nx][ny] = visited[now.second.first][now.second.second];
                    }
                }
            }
        }
    }
    
    return;

}

void painting(int sx, int sy, int ex, int ey, int color)
{
    if (sx > ex) {
        swap(sx, ex);
    }
    if (sy > ey) {
        swap(sy, ey);
    }
    
    for (int i=sx; i<=ex; ++i) {
        for (int j=sy; j<=ey; ++j) {
            board[i][j] = color;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    int sx, sy, ex, ey;
    for (int k=0; k<N; ++k) {
        cin >> sx >> sy >> ex >> ey;
        painting(sx, sy, ex, ey, 1);
    }
    
    cin >> M;
    for (int k=0; k<M; ++k) {
        cin >> sx >> sy >> ex >> ey;
        painting(sx, sy, ex, ey, 2);
    }
    
    bfs();
    
    if (visited[500][500] == 250001) {
        cout << -1;
    }
    else {
        cout << visited[500][500];
    }

    return 0;
}
