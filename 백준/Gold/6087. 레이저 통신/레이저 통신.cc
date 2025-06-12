#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
pll S = {-1, -1}, E;
vector<vector<char> > board(101, vector<char>(101, ' '));
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.first > b.first;
    }
};

int mirror_mirror()
{
    vector<vector<int> > visited(M, vector<int>(N, 99999999));
    visited[S.first][S.second] = 0;
    priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
    que.push({-1, {S.first, S.second}});
    
    while (!que.empty()) {
        int now_mirror = que.top().first;
        pll now = que.top().second;
        que.pop();
        
        if (visited[now.first][now.second] < now_mirror) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now.first;
            int ny = now.second;
            while (true) {
                nx += directions[i].first;
                ny += directions[i].second;
                if (0 <= nx && nx < M && 0 <= ny && ny < N && board[nx][ny] != '*') {
                    if (visited[nx][ny] > now_mirror + 1) {
                        visited[nx][ny] = now_mirror + 1;
                        que.push({now_mirror + 1, {nx, ny}});
                    }
                    else if (visited[nx][ny] == now_mirror + 1) continue;
                    else break;
                }
                else break;
            }
        }
    }
    
    return visited[E.first][E.second];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'C') {
                if (S.first == -1) S = {i, j};
                else E = {i, j};
            }
        }
    }
    
    cout << mirror_mirror();

    return 0;
}