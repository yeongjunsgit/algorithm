#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

struct Compare
{
    bool operator()(const pair<pll, pll>& a, const pair<pll, pll>& b) {
        if (a.first.first == b.first.first) {
            return a.first.second > b.first.second;
        }
        return a.first.first > b.first.first;
    }
};

int N, M;
vector<vector<char> > board(50, vector<char>(50, ' '));
vector<vector<int> > near_trash(50, vector<int>(50, 0));
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
pll S, E;


pll bfs()
{
    priority_queue<pair<pll, pll>, vector<pair<pll, pll> >, Compare> que;
    que.push({{0, 0}, {S.first, S.second}});
    vector<vector<pll> > visited(N, vector<pll>(M, {9999999, 9999999}));
    visited[S.first][S.second] = {0, 0};
    
    while (!que.empty()) {
        pair<pll, pll> now = que.top();
        que.pop();
        
        if (now.first.first == visited[now.second.first][now.second.second].first) {
            if (now.first.second > visited[now.second.first][now.second.second].second) continue;
        }
        else if (now.first.first > visited[now.second.first][now.second.second].first) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now.second.first + directions[i].first;
            int ny = now.second.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (board[nx][ny] == 'F') {
                    return now.first;
                }
                else {
                    pll next_info = now.first;
                    if (board[nx][ny] == 'g') {
                        next_info.first++;
                    }
                    else {
                        if (near_trash[nx][ny] == 1) {
                            next_info.second++;
                        }
                    }
                    
                    if (visited[nx][ny].first > next_info.first || (visited[nx][ny].first == next_info.first && visited[nx][ny].second > next_info.second)) {
                        visited[nx][ny] = next_info;
                        que.push({next_info, {nx, ny}});
                    }
                }
            }
            
        }
    }
    
};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'S') S = {i, j};
            else if (board[i][j] == 'F') E = {i, j};
            else if (board[i][j] == 'g') {
                for (int k=0; k<4; ++k) {
                    int ni = i + directions[k].first;
                    int nj = j + directions[k].second;
                    
                    if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                        near_trash[ni][nj] = 1;
                    }
                }
            }
        }
    }
    
    pll result = bfs();
    
    cout << result.first << " " << result.second;

    return 0;
}
