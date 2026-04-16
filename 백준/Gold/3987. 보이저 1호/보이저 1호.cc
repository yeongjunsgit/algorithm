#include <iostream>
#include <vector>
#include <map>

#define pll pair<int, int>

using namespace std;

int N, M, X, Y;
vector<vector<char> > board(502, vector<char>(502));
vector<pll> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
map<pair<char, int>, int> change_directions = {
    {{'\\', 0}, 3}, {{'\\', 2}, 1}, {{'\\', 1}, 2}, {{'\\', 3}, 0},  
    {{'/', 0}, 1}, {{'/', 2}, 3}, {{'/', 1}, 0}, {{'/', 3}, 2},  
}; 

map<int, char> dir_check = {{0, 'U'}, {1, 'R'}, {2, 'D'}, {3, 'L'}};

int dfs(int x, int y, int start_dir)
{
    vector<vector<vector<int> > > visited(501, vector<vector<int> >(501, vector<int>(4, 0)));
    int now_direction = start_dir, cnt = 0;
    while (true) {
        while (true) {
            x += directions[now_direction].first;
            y += directions[now_direction].second;
            // cout << start_dir << " {" << x << ", " << y << "}\n";
            cnt++;
            if ((0 == x || x == N+1 || 0 == y || y == M+1) || board[x][y] == 'C') {
                return cnt;
            }
            else if (board[x][y] != '.') {
                break;
            }
        }
        if (visited[x][y][now_direction] == 0) {
            visited[x][y][now_direction] = 1;
            now_direction = change_directions[{board[x][y], now_direction}];
        }
        else {
            return -1;
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> X >> Y;
    int result = 0, best_dir = -1;
    for (int i=0; i<4; ++i) {
        int tmp = dfs(X, Y, i);
        if (tmp == -1) {
            result = -1;
            best_dir = i;
            break;
        }
        else if (tmp > result) {
            result = tmp;
            best_dir = i;
        }
    }
    
    cout << dir_check[best_dir] << "\n";
    if (result == -1) {
        cout << "Voyager";
    }
    else {
        cout << result;
    }

    return 0;
}
