#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int T, N, M, O, F;
pll start_loca, end_loca;

vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool lets_move(vector<vector<int> >& board)
{
    vector<vector<int> > visited(N, vector<int>(M, -1));
    visited[start_loca.first][start_loca.second] = F;
    queue<pair<int, pll> > que;
    que.push({F, start_loca});
    
    while (!que.empty()) {
        int now_power = que.front().first;
        pll now = que.front().second;
        que.pop();
        if (now_power < visited[now.first][now.second]) continue;
        if (now_power == 0) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                int tmp = max(0, board[nx][ny] - board[now.first][now.second]);
                if (now_power - tmp >= 0 && visited[nx][ny] < now_power - 1) {
                    visited[nx][ny] = now_power - 1;
                    que.push({now_power - 1, {nx, ny}});
                }
            }
        }
    }
    
    if (visited[end_loca.first][end_loca.second] > -1) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N >> M >> O >> F >> start_loca.first >> start_loca.second >> end_loca.first >> end_loca.second;
        int x, y, h;
        vector<vector<int> > board(N, vector<int>(M, 0));
        start_loca.first -= 1; start_loca.second -= 1; end_loca.first -= 1; end_loca.second -= 1;
        for (int i=0; i<O; ++i) {
            cin >> x >> y >> h;
            board[x - 1][y - 1] = h;
        }
        
        if (lets_move(board) ) cout << "잘했어!!\n";
        else cout << "인성 문제있어??\n";
    }
    
    return 0;
}
