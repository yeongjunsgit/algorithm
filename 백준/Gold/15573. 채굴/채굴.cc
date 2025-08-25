#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, K;
vector<vector<int> > mineral(1000, vector<int>(1000)), visited(1000, vector<int>(1000, 0));
int max_power = 0;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int mining(int now_power)
{
    queue<pll> que;
    int cnt = 0;
    
    for (int i=0; i<M; ++i) {
        if (mineral[0][i] <= now_power) {
            que.push({0, i});
            visited[0][i] = now_power;
            cnt++;
        }
    }
    
    for (int i=1; i<N; ++i) {
        if (mineral[i][0] <= now_power) {
            que.push({i, 0});
            visited[i][0] = now_power;
            cnt++;
        }
        if (mineral[i][M-1] <= now_power) {
            que.push({i, M-1});
            visited[i][M-1] = now_power;
            cnt++;
        }
    }
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && mineral[nx][ny] <= now_power && visited[nx][ny] != now_power) {
                visited[nx][ny] = now_power;
                que.push({nx, ny});
                cnt++;
            }
        }
        
    }
    
    return cnt;
}

int binary_check()
{
    int start = 1;
    int end = max_power;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int now_cnt = mining(mid);
        
        if (now_cnt >= K) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return start;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> mineral[i][j];
            if (max_power < mineral[i][j]) max_power = mineral[i][j];
        }
    }
    
    cout << binary_check();

    return 0;
}
