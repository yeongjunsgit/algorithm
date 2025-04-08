#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int> > board, DP;
int wall_type, x1, y1, x2, y2;
vector<pair<int, int> > directions = {{0, 0}, {1, 0}, {0, 1}};

bool check_wall(int x, int y, int dir)
{
    if (wall_type == 0) {
        return true;
    }
    else if (wall_type == 1 && dir == 1) {
        if (x == x1 && y1 <= y && y < y2) {
            return false;
        }
        return true;
    }
    else if (wall_type == 2 && dir == 2){
        if (y == y1 && x1 <= x && x < x2) {
            return false;
        }
        return true;
    }
    return true;
}

void lets_go()
{
    vector<vector<int> > visited(N, vector<int>(M, 0));
    visited[0][0] = 1;
    DP[0][0] = board[0][0];
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 1) {
                for (int k=1; k<=2; ++k) {
                    int nx = i + directions[k].first;
                    int ny = j + directions[k].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        bool is_ok = check_wall(nx, ny, k);
                        if (is_ok == true) {
                            DP[nx][ny] = max(DP[nx][ny], DP[i][j] + board[nx][ny]);
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    
    if (visited[N-1][M-1] == 1) {
        cout << DP[N-1][M-1];
    }
    else {
        cout << "Entity";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    DP.resize(N, vector<int>(M, -10000001));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    
    // 0 = 벽이 없음, 1 = 가로 벽, 2 = 세로 벽
    if (x1 == x2 && y1 == y2) {
        wall_type = 0;
    }
    else if (x1 == x2) {
        wall_type = 1;
        if (y1 > y2) swap(y1, y2);
    }
    else {
        wall_type = 2;
        if (x1 > x2) swap(x1, x2);
    }
    
    lets_go();

    return 0;
}
