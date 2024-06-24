#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<pair<int, int>> direction = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int find_moutain(vector<vector<int>>& parm, vector<vector<int>>& visited, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = 1;
    bool is_upper = false;
    
    while(!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<8; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (parm[nx][ny] < parm[now.first][now.second]) {
                    continue;
                }
                else if (parm[nx][ny] == parm[now.first][now.second]) {
                    if (visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        que.push({nx, ny});
                    }
                }
                else if (parm[nx][ny] > parm[now.first][now.second]) {
                    is_upper = true;
                }
            }
        }
    }
    
    if (is_upper == false) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<int>> parm;
    
    string data;
    int num;
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        parm.push_back(one_line);
    }
    
    int result = 0;
    
    vector<vector<int>> visited(N, vector<int>(M, 0));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (parm[i][j] != 0 && visited[i][j] == 0) {
                result += find_moutain(parm, visited, i, j);
            }
        }
    }

    cout << result;

    return 0;
}
