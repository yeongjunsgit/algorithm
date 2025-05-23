#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board(20, (vector<int>(20, 0)));
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


pll bfs(vector<vector<int> >& visited, int x, int y, int def_mode)
{
    int base = board[x][y], cnt = 1, rainbow_cnt = 0;
    set<pll> rainbow_blocks;
    queue<pll> que;
    que.push({x, y});
    if (def_mode == 1) board[x][y] = -2;
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (def_mode == 0) {
                if (0 <= nx && nx < N && 0 <= ny && ny < N && ((visited[nx][ny] == 0 && board[nx][ny] == base) || (board[nx][ny] == 0 && rainbow_blocks.find({nx, ny}) == rainbow_blocks.end() ) ) ) {
                    if (board[nx][ny] == base) visited[nx][ny] = 1;
                    else {
                        rainbow_blocks.insert({nx, ny});
                        rainbow_cnt++;
                    }
                    cnt++;
                    que.push({nx, ny});
                } 
            }
            else {
                if (0 <= nx && nx < N && 0 <= ny && ny < N && (board[nx][ny] == base || board[nx][ny] == 0) ) {
                    board[nx][ny] = -2;
                    que.push({nx, ny});
                }
            }
        }
    }
    
    return {cnt, rainbow_cnt};
}


void gravity()
{
    vector<vector<int> > tmp_board(20, (vector<int>(20, -2)));
    
    for (int i=N-1; i>=0; --i) {
        for (int j=0; j<N; ++j) {
            if (board[i][j] >= 0) {
                pll best_loca = {i, j};
                for (int k=i; k<=N - 1; ++k) {
                    if (tmp_board[k][j] == -2) {
                        best_loca = {k, j};
                    }
                    else break;
                }
                tmp_board[best_loca.first][best_loca.second] = board[i][j];
            }
            if (board[i][j] == -1) {
                tmp_board[i][j] = -1;
            }
        }
    }
    
    board = tmp_board;
    return;
}


void rotate_gravity()
{
    vector<vector<int> > tmp_board(20, (vector<int>(20, -2)));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (board[i][j] >= 0) {
                pll best_loca = {N-1-j, i};
                for (int k=N - 1 - j; k<=N - 1; ++k) {
                    if (tmp_board[k][i] == -2) {
                        best_loca = {k, i};
                    }
                    else break;
                }
                tmp_board[best_loca.first][best_loca.second] = board[i][j];
            }
            if (board[i][j] == -1) {
                tmp_board[N-1-j][i] = -1;
            }
        }
    }
    
    board = tmp_board;
    return;
}


int search_group()
{
    int result = 0;
    while (true) {
        int max_size = 0, max_rainbow = 0;
        pll max_loca = {-1, -1};
        vector<vector<int> > visited(20, (vector<int>(20, 0)));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (board[i][j] > 0 && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    pll tmp = bfs(visited, i, j, 0);
                    if (max_size < tmp.first) {
                        max_size = tmp.first;
                        max_rainbow = tmp.second;
                        max_loca = {i, j};
                    }
                    else if (max_size == tmp.first) {
                        if (max_rainbow < tmp.second) {
                            max_rainbow = tmp.second;
                            max_loca = {i, j};
                        }
                        else if (max_rainbow == tmp.second) {
                            if (max_loca.first < i) {
                                max_loca = {i, j};
                            }
                            else if (max_loca.first == i) {
                                if (max_loca.second < j) {
                                    max_loca.second = j;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        if (max_size > 1) {
            bfs(visited, max_loca.first, max_loca.second, 1);
            result += max_size * max_size;
            gravity();
            rotate_gravity();
        }
        else break;
        
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << search_group();

    return 0;
}

