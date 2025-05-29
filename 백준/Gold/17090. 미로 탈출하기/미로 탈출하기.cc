#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;
vector<vector<char> > board(500, vector<char>(500));
unordered_map<char, pair<int, int> > directions = {{'U', {-1, 0}}, {'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}};


int dfs(vector<vector<int> >& visited, int x, int y)
{
    int nx = x + directions[board[x][y]].first;
    int ny = y + directions[board[x][y]].second;
    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
        if (visited[nx][ny] == 0) {
            visited[x][y] = 1;
            visited[x][y] = dfs(visited, nx, ny);
        }
        else if (visited[nx][ny] == -1 || visited[nx][ny] == 1) {
            visited[x][y] = -1;
        }
        else if (visited[nx][ny] == 2) {
            visited[x][y] = 2;
        }
    }
    else {
        visited[x][y] = 2;
    }

    return visited[x][y];
    
}


int lets_move()
{
    int result = 0;
    vector<vector<int> > visited(N, vector<int>(M, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                int tmp = dfs(visited, i, j);
                if (tmp == 2) result++;
            }
            else if (visited[i][j] == 2) {
                result++;
            }
        }
    }
    
    return result;
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
    
    cout << lets_move();
    
    return 0;
}
