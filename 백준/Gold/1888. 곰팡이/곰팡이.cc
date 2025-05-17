#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, M, K;
vector<int> parents;
vector<vector<int> > board(100, vector<int>(100, 0)); 
vector<vector<pll> > visited(100, vector<pll>(100, {0, 0}));
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};


void lets_color_it(int base, int color, int x, int y)
{
    queue<pll> que;
    que.push({x, y});
    visited[x][y].first = color;
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny].first == 0 && board[nx][ny] == base) {
                visited[nx][ny].first = color;
                que.push({nx, ny});
            }
        }
    }
    
    return;
}


void draw_color()
{
    int coloring = 0;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j].first == 0 && board[i][j] != 0) {
                coloring++;
                lets_color_it(board[i][j], coloring, i, j);
            }
        }
    }
    K = coloring;
    return;
}

int find_root(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = find_root(parents[x]);
}

void union_root(int x, int y)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    
    if (r_x == r_y) return;
    if (r_x > r_y) swap(r_x, r_y);
    parents[r_y] = r_x;
    return;
}


bool check_connect(int now_turn)
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (visited[i][j].first != 0 && visited[i][j].second == now_turn) {
                for (int k=0; k<4; ++k) {
                    int nx = i + directions[k].first;
                    int ny = j + directions[k].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny].first != 0 && visited[nx][ny].first != visited[i][j].first) {
                        union_root(visited[i][j].first, visited[nx][ny].first);
                    }
                }
            }
        }
    }
    
    bool is_connect = true;
    
    for (int i=1; i<=K; ++i) {
        int tmp = find_root(i);
        if (tmp != 1) {
            is_connect = false;
            break;
        }
    }
    
    return is_connect;
}


int lets_move_out()
{
    parents.resize(K+1);
    for (int i=1; i<=K; ++i) {
        parents[i] = i;
    }
    
    int result = 0;
    bool start_check = check_connect(result);
    if (start_check) return result;
    
    while (true) {
        result++;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (visited[i][j].second == result - 1 && board[i][j] != 0) {
                    int col_start = max(0, i - board[i][j]);
                    int col_end = min(N - 1, i + board[i][j]);
                    int low_start = max(0, j - board[i][j]);
                    int low_end = min(M - 1, j + board[i][j]);
                    for (int p=col_start; p<=col_end; ++p) {
                        for (int q=low_start; q<=low_end; ++q) {
                            if (board[p][q] < board[i][j]) {
                                if (board[p][q] != 0) {
                                    union_root(visited[i][j].first, visited[p][q].first);
                                }
                                board[p][q] = board[i][j];
                                visited[p][q] = {visited[i][j].first, result};
                            }
                        }
                    }
                }
            }
        }
        
        bool now_result = check_connect(result);
        if (now_result) break;
    }
    
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        for (int j=0; j<M; ++j) {
            board[i][j] = data[j] - '0';
        }
    }
    
    draw_color();
    cout << lets_move_out();

    return 0;
}