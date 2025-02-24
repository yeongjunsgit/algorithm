#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char> > board; 
vector<vector<bool> > visited;
vector<pair<int, int> > directions = {{-1, 1}, {0, 1}, {1, 1}};
int result = 0;


bool make_pipe(pair<int, int> now)
{
    visited[now.first][now.second] = true;
    
    if (now.second == M - 1) {
        result++;
        return true;
    }
    
    bool is_connect = false;
    
    for (int i=0; i<3; ++i) {
        int nx = now.first + directions[i].first;
        int ny = now.second + directions[i].second;
        if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == '.' && visited[nx][ny] == false) {
            is_connect = make_pipe({nx, ny});
            if (is_connect == true) {
                break;
            }
        }
    }
    
    return is_connect;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;
    board.resize(N, vector<char>(M));
    visited.resize(N, vector<bool>(M, false));
    string data;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        for (int j=0; j<M; ++j) {
            board[i][j] = data[j];
        }
    }
    
    for (int i=0; i<N; ++i) {
        make_pipe({i, 0});
    }
    
    cout << result;

    return 0;
}
