#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int N, int M, int x, int y, vector<vector<int>>& visited, vector<vector<int>>& arr, vector<vector<int>>& copy_arr) {
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    queue<pair<int, int>> que;
    que.push({x, y});
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (arr[nx][ny] == 0 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
                else if (arr[nx][ny] == 1 && visited[nx][ny] == 0) {
                    copy_arr[nx][ny] = 0;
                    visited[nx][ny] = 1;
                }
            }
        }
    }
    
    
}

int main()
{
    
    // N = 세로 길이, M = 가로 길이
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<int>> arr;
    
    for (int i=0; i<N; ++i) {
        string data;
        getline(cin, data);
        
        istringstream iss(data);
        int num;
        vector<int> one_line;
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        arr.push_back(one_line);
    }
    
    vector<int> now_cheeze;
    int now_idx = 0;
    
    while (true) {
        int cheeze = 0;
        vector<vector<int>> visited(N, vector<int>(M, 0));
        vector<vector<int>> copy_arr(N, vector<int>(M));
        bool isMelt = false;
        
        for (int i=0; i<N; ++i) {
            copy(begin(arr[i]), end(arr[i]), begin(copy_arr[i]));
        }
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (arr[i][j] == 0 && (i == 0 || i == N-1 || j == 0 || j == M-1)) {
                    if (visited[i][j] == 0) {
                        bfs(N, M, i, j, visited, arr, copy_arr);
                        isMelt = true;
                    }
                }
                else if (arr[i][j] == 1) {
                    cheeze += 1;
                }
            }
        }
        
        if (cheeze == 0) {
            cout << now_idx << "\n";
            cout << now_cheeze[now_cheeze.size() - 1];
            break;
        }
        
        else {
            now_cheeze.push_back(cheeze);
            arr = copy_arr;
            now_idx += 1;
        }
    }

    return 0;
}
