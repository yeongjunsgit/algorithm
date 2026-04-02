#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.first > b.first;
    }
};

int N, M, A, B, K, s, e;
pll start_point, end_point;
vector<vector<int> > board(501, vector<int>(501, 0)), visited(501, vector<int>(501, 999999999)), check_map(501, vector<int>(501, 0));
vector<pll> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int now_check(int x, int y)
{
    for (int a=0; a<A; ++a) {
        for (int b=0; b<B; ++b) {
            int tx = x + a;
            int ty = y + b;
            if (1 <= tx && tx <= N && 1 <= ty && ty <= M && board[tx][ty] != 1) {
                continue;
            }
            else return 0;
        }
    }
    
    return 1;
}



void map_checking()
{
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            check_map[i][j] = now_check(i, j);
        }
    }
    return;
}



void bfs()
{
    visited[start_point.first][start_point.second] = 0;
    priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
    que.push({0, start_point});
    
    while (!que.empty()) {
        int now_move = que.top().first;
        pll now_loca = que.top().second;
        que.pop();
        
        if (now_move > visited[now_loca.first][now_loca.second] || now_move >= visited[end_point.first][end_point.second]) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now_loca.first + direction[i].first;
            int ny = now_loca.second + direction[i].second;
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && board[nx][ny] != 1 && check_map[nx][ny] == 1 && visited[nx][ny] > now_move + 1) {
                visited[nx][ny] = now_move + 1;
                que.push({now_move + 1 , {nx, ny}});
            }
        }
        
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> A >> B >> K;
    for (int i=0; i<K; ++i) {
        cin >> s >> e;
        board[s][e] = 1;
    }
    cin >> start_point.first >> start_point.second >> end_point.first >> end_point.second;
    
    map_checking();
    bfs();
    
    if (visited[end_point.first][end_point.second] == 999999999) cout << -1;
    else cout << visited[end_point.first][end_point.second];

    return 0;
}


