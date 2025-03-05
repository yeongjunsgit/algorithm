/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N;
vector<vector<char> > board;
vector<vector<int> > visited, r_g_visited;
map<char, int> coloring = {{'R', 1}, {'G', 2}, {'B', 3}};
vector<pll> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int area_cnt = 0;
int BG_cnt = 0;

void paint_color(int x, int y, char color)
{
    int now_color = coloring[color];
    queue<pll> que;
    que.push({x, y});
    visited[x][y] = now_color;
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N && board[nx][ny] == color && visited[nx][ny] == 0) {
                visited[nx][ny] = now_color;
                que.push({nx, ny});
            }
        }
    }
    
    if (color == 'B') {
        BG_cnt++;
    }
    area_cnt++;
    
    return;
    
}

void painr_BG(int x, int y)
{
    queue<pll> que;
    que.push({x, y});
    r_g_visited[x][y] = 1;
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N && (board[nx][ny] == 'R' || board[nx][ny] == 'G') && r_g_visited[nx][ny] == 0) {
                r_g_visited[nx][ny] = 1;
                que.push({nx, ny});
            }
        }
    }
    
    BG_cnt++;
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    string data;
    visited.resize(N, vector<int>(N, 0));
    r_g_visited.resize(N, vector<int>(N, 0));
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        vector<char> one_line;
        for (char c : data) {
            one_line.push_back(c);
        }
        board.push_back(one_line);
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (visited[i][j] == 0) {
                paint_color(i, j, board[i][j]);
                if ((board[i][j] == 'R' || board[i][j] == 'G') && r_g_visited[i][j] == 0) {
                    painr_BG(i, j);
                }
            }
        }
    }
    
    cout << area_cnt << " " << BG_cnt;

    return 0;
}
