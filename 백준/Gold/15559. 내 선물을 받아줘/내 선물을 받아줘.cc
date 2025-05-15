#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
vector<vector<char> > board(1000, vector<char>(1000, ' '));
vector<vector<int> > visited(1000, vector<int>(1000, 0));
unordered_map<char, pair<int, int> > directions = {{'N', {-1, 0}}, {'S', {1, 0}}, {'W', {0, -1}}, {'E', {0, 1}}};

int coloring = 0;

int lets_move(int color, int x, int y)
{
    visited[x][y] = color;
    pair<int, int> next_loca = directions[board[x][y]];
    int nx = x + next_loca.first;
    int ny = y + next_loca.second;

    if (visited[nx][ny] == 0) {
        visited[nx][ny] = color;
        int tmp_color = lets_move(color, nx, ny);
        visited[x][y] = tmp_color;
        return tmp_color;
    }
    else {
        visited[x][y] = visited[nx][ny];
        return visited[x][y];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 0) {
                int tmp = lets_move(coloring + 1, i, j);
                if (tmp == coloring + 1) coloring++;
            }
        }
    }
    
    cout << coloring;
    
    return 0;
}
