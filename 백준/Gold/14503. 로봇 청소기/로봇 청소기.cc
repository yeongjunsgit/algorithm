#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, x, y, dir;
vector<vector<int> > board;
vector<pll> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void run_robot()
{
    int result = 0;
    
    while (true) {
        if (board[x][y] == 0) {
            board[x][y] = 2;
            result++;
        }
        bool is_dust = false;
        
        for (int i=0; i<4; ++i) {
            int tx = x + directions[i].first;
            int ty = y + directions[i].second;
            
            if (0 <= tx && tx < N && 0 <= ty && ty < M && board[tx][ty] == 0) {
                is_dust = true;
                break;
            }
        }
        
        if (is_dust == false) {
            int back_point = (dir + 2) % 4;
            int nx = x + directions[back_point].first;
            int ny = y + directions[back_point].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] != 1) {
                x = nx;
                y = ny;
            }
            else {
                break;
            }
        }
        else {
            int next_dir = (dir + 3) % 4;
            dir = next_dir;
            int nx = x + directions[next_dir].first;
            int ny = y + directions[next_dir].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    cin >> x >> y >> dir;

    int num;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> num;
            board[i][j] = num;
        }
    }
    
    run_robot();

    return 0;
}
