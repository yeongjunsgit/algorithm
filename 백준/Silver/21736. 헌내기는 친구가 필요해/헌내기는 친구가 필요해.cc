#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<char>> campus;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    pair<int, int> my_location;
    
    string data;
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<char> tmp_vec;
        for (int j=0; j<M; ++j) {
            tmp_vec.push_back(data[j]);
            if (data[j] == 'I') {
                my_location = {i, j};
            }
        }
        campus.push_back(tmp_vec);
    }
    
    queue<pair<int, int>> que;
    que.push(my_location);
    visited[my_location.first][my_location.second] = 1;
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int result = 0;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int f=0; f<4; ++f) {
            int nx = now.first + direction[f].first;
            int ny = now.second + direction[f].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (campus[nx][ny] == 'O' && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
                else if (campus[nx][ny] == 'P' && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                    result += 1;
                }
            }
        }
    }

    if (result > 0) {
        cout << result;
    }
    else {
        cout << "TT";
    }
    
    return 0;
}
