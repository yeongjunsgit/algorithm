#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, cnt = 0, idx = 0;
vector<vector<char> > choco(40, vector<char>(40));
vector<vector<int> > visited(40, vector<int>(40, 0));
vector<pll> passed, directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


bool tick_choco(pll one)
{
    choco[one.first][one.second] = '.';
    idx++;
    int repeat = 0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (choco[i][j] == '#' && visited[i][j] != idx) {
                if (repeat == 0) repeat++;
                else {
                    choco[one.first][one.second] = '#';
                    return false;
                }
                visited[i][j] = idx;
                queue<pair<pll, pll> > que;
                que.push({{-1, -1}, {i, j}});
                
                while (!que.empty()) {
                    pll pre = que.front().first;
                    pll now = que.front().second;
                    que.pop();
                    
                    for (int k=0; k<4; ++k) {
                        int nx = now.first + directions[k].first;
                        int ny = now.second + directions[k].second;
                        
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && choco[nx][ny] == '#') {
                            if (visited[nx][ny] == idx) {
                                if (pre.first == nx && pre.second == ny) continue;
                                else {
                                    choco[one.first][one.second] = '#';
                                    return false;
                                }
                            }
                            else {
                                visited[nx][ny] = idx;
                                que.push({now, {nx, ny}});
                            }
                        }
                    }
                }
            }
        }
    }
    choco[one.first][one.second] = '#';
    return true;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> choco[i][j];
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (choco[i][j] == '#') {
                if (tick_choco({i, j})) {
                    cnt++;
                    passed.push_back({i, j});
                }
            }
        }
    }
    
    cout << cnt << "\n";
    for (auto a : passed) {
        cout << a.first + 1 << " " << a.second + 1 << "\n";
    }
    

    return 0;
}
