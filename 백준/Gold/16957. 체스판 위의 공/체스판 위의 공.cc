#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.first < b.first;
    }
};

int N, M;
vector<vector<int> > graph(500, vector<int>(500, 0)), my_balls(500, vector<int>(500, 1));
priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
vector<pll> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> graph[i][j];
            que.push({graph[i][j], {i, j}});
        }
    }
    
    while (!que.empty()) {
        int now = que.top().first;
        pll now_loca = que.top().second;
        que.pop();
        
        int min_near = 9999999;
        pll min_loca = {-1, -1};
        for (int i=0; i<8; ++i) {
            int nx = now_loca.first + directions[i].first;
            int ny = now_loca.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (graph[nx][ny] < now && graph[nx][ny] < min_near) {
                    min_near = graph[nx][ny];
                    min_loca = {nx, ny};
                }
            }
        }
        if (min_near == 9999999 && min_loca.first == -1 && min_loca.second == -1) {
            continue;
        }
        my_balls[min_loca.first][min_loca.second] += my_balls[now_loca.first][now_loca.second];
        my_balls[now_loca.first][now_loca.second] = 0;
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cout << my_balls[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
