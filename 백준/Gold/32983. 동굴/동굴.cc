#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, C, X, Y;

vector<vector<int> > cave, visited;
vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int result = 0;

void bfs()
{
    queue<pair<int, int> > que;
    que.push({X - 1, Y - 1});
    visited[X - 1][Y - 1] = 1;
    int now_value = cave[X - 1][Y - 1];
    result = max(0, cave[X - 1][Y - 1]);
    while (!que.empty()) {
        queue<pair<int, int> > tmp_que;
        now_value -= C;
        
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            
            for (int i=0; i<4; ++i) {
                int nx = now.first + direction[i].first;
                int ny = now.second + direction[i].second;
                
                if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0 && cave[nx][ny] != -1) {
                    visited[nx][ny] = 1;
                    tmp_que.push({nx, ny});
                    now_value += cave[nx][ny];
                }
            }
        }
        
        if (result < now_value) {
            result = now_value;
        }
        que = tmp_que;
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> C >> X >> Y;
    cin.ignore();
    
    visited.resize(N, vector<int>(M, 0));
    int num;
    string data;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        while (iss >> num) {
            one_line.push_back(num);
        }
        cave.push_back(one_line);
    }
    
    bfs();

    return 0;
}
