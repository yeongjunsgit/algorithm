#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int N;
vector<vector<int> > board(1001, vector<int>(1001, 0)), visited(1001, vector<int>(1001, 1000000000));
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Compare
{
    bool operator()(pair<int, pll>& a, pair<int, pll>& b) {
        return a.first > b.first;
    }
};



void bfs()
{
    priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
    visited[1][1] = 0;
    que.push({0, {1, 1}});
    
    while (!que.empty()) {
        int now_price = que.top().first;
        pll now = que.top().second;
        que.pop();
        if (now_price > visited[now.first][now.second]) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (1 <= nx && nx <= N && 1 <= ny && ny <= N) {
                int next_price = max(now_price, abs(board[now.first][now.second] - board[nx][ny]));
                if (next_price < visited[N][N] && visited[nx][ny] > next_price) {
                    visited[nx][ny] = next_price;
                    que.push({next_price, {nx, ny}});
                }
            }
            
        }
    }
    
    
    return;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> board[i][j];
        }
    }

    bfs();
    
    cout << visited[N][N];

    return 0;
}
