#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int N, M;
int colors = 1;
vector<vector<pair<int, int> > > board;

vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int x, int y)
{
    int now_power = 1;
    queue<pair<int, int> > que;
    queue<pair<int, int> > passed;
    board[x][y] = {-1, colors};
    que.push({x, y});
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        passed.push(now);
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny].first == 0) {
                board[nx][ny] = {-1, colors};
                que.push({nx, ny});
                now_power++;
            }
        }
    }
    
    while (!passed.empty()) {
        pair<int, int> tmp = passed.front();
        passed.pop();
        board[tmp.first][tmp.second].first = now_power;
    }
    
    colors++;
    return;
}

void make_board()
{
    vector<vector<int> > result(N, vector<int>(M, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j].first == 1 && board[i][j].second == 0) {
                int now = 1;
                unordered_set<int> checked;
                for (int k=0; k<4; ++k) {
                    int nx = i + direction[k].first;
                    int ny = j + direction[k].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny].second != 0) {
                        if (checked.find(board[nx][ny].second) == checked.end()) {
                            checked.insert(board[nx][ny].second);
                            now += board[nx][ny].first;
                        }
                    }
                }
                
                result[i][j] = now % 10;
            }
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    string data;
    board.resize(N);
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        for (char a : data) {
            board[i].push_back({a - '0', 0});
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j].first == 0) {
                bfs(i, j);
            }
        }
    }
    
    make_board();

    return 0;
}
