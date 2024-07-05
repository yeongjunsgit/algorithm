#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int paint, int base, int x, int y, vector<vector<int>>& board, vector<vector<int>>& visited) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = paint;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0 && board[nx][ny] == base) {
                visited[nx][ny] = paint;
                que.push({nx, ny});
            }
        }
    }
    
    return;
}

int main()
{
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> before;
    vector<vector<int>> after;
    vector<vector<int>> before_visited(N, vector<int>(M, 0));
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        before.push_back(one_line);
    }
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss_2(data);
        vector<int> one_line;
        while (iss_2 >> num) {
            one_line.push_back(num);
        }
        
        after.push_back(one_line);
    }
    
    int paint = 1;
    int changed = 0;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (before_visited[i][j] == 0) {
                if (before[i][j] != after[i][j]) {
                    paint = after[i][j];
                    changed += 1;
                }
                else {
                    paint = before[i][j];
                }
                
                bfs(paint, before[i][j], i, j, before, before_visited);
            }
        }
    }
    
    if (changed < 2 && before_visited == after) {
        cout << "YES";
    }
    
    else {
        cout << "NO";
    }

    return 0;
}
