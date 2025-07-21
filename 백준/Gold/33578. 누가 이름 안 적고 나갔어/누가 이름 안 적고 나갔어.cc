#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<char> > classroom(3000, vector<char>(3000));
vector<pll> teacher;
pll target, start_point;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<int> move_cost = {2, 1};

struct Compare {
    bool operator()(const pair<pll, pll>& a, const pair<pll, pll>& b) {
        return a.first.second > b.first.second;
    }
};

int catch_target()
{
    vector<vector<vector<int> > > visited(2, vector<vector<int> >(N, vector<int>(M, 99999999)));
    visited[0][start_point.first][start_point.second] = 0;
    priority_queue<pair<pll, pll>, vector<pair<pll, pll> >, Compare> que;
    que.push({{0, 0}, start_point});
    
    while (!que.empty()) {
        int is_teacher = que.top().first.first;
        int now_move = que.top().first.second;
        pll now = que.top().second;
        que.pop();
        if (visited[is_teacher][now.first][now.second] < now_move) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && classroom[nx][ny] != '#' && visited[is_teacher][nx][ny] > now_move + move_cost[is_teacher] && visited[0][target.first][target.second] > now_move + move_cost[is_teacher] && visited[1][target.first][target.second] > now_move + move_cost[is_teacher]) {
                visited[is_teacher][nx][ny] = now_move + move_cost[is_teacher];
                que.push({{is_teacher, visited[is_teacher][nx][ny]}, {nx, ny}});
                if (is_teacher == 0 && classroom[nx][ny] == 'T' && visited[1][nx][ny] > visited[is_teacher][nx][ny]) {
                    visited[1][nx][ny] = visited[is_teacher][nx][ny];
                    que.push({{1, visited[1][nx][ny]}, {nx, ny}});
                }
            }
        }
    }
    
    return min(visited[0][target.first][target.second], visited[1][target.first][target.second]);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> classroom[i][j];
            if (classroom[i][j] == 'J') start_point = {i, j};
            else if (classroom[i][j] == 'S') target = {i, j};
            else if (classroom[i][j] == 'T') teacher.push_back({i, j});
        }
    }
    
    int result = catch_target();
    if (result == 99999999) cout << -1;
    else cout << result;
    
    return 0;
}

