#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M, H, W;

pair<int, int> start, destination;
vector<vector<int> > board;

vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int> > visited;
int result = 1000001;

void bfs()
{
    queue<pair<int, int> > que;
    que.push(start);
    visited[start.first][start.second] = 0;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        if (visited[now.first][now.second] > visited[destination.first][destination.second]) {
            continue;
        }
        
        // H = 높이, W = 넓이
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 < nx && nx <= N - (H - 1) && 0 < ny && ny <= M - (W - 1)) {
                if (visited[nx][ny] != -1 && visited[nx][ny] > visited[now.first][now.second] + 1) {
                    visited[nx][ny] = visited[now.first][now.second] + 1;
                    que.push({nx, ny});
                    
                    if (nx == destination.first && ny == destination.second) {
                        result = min(result, visited[nx][ny]);
                    }
                }
            }
        }
    }
    
    if (result == 1000001) {
        cout << -1;
    }
    else {
        cout << result;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    string data;
    int num;
    board.resize(1, vector<int>(M, 0));
    visited.resize(N + 1, vector<int>(M + 1, 1000001));
    vector<pair<int, int> > walls;
    
    for (int i=1; i<=N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        one_line.push_back(0);
        int idx = 1;
        
        while (iss >> num) {
            one_line.push_back(num);
            if (num == 1) {
                walls.push_back({i, idx});
            }
            idx++;
        }
        
        board.push_back(one_line);
    }
    
    cin >> H >> W >> start.first >> start.second >> destination.first >> destination.second;
    
    for (auto a : walls) {
        for (int i=0; i<H; ++i) {
            for (int j=0; j<W; ++j) {
                if (a.first - i > 0 && a.second - j > 0) {
                    visited[a.first - i][a.second - j] = -1;
                }
            }
        }
    }
    
    bfs();

    return 0;
}
