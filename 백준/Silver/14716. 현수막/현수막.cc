#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();
    
    string data;
    vector<vector<int>> board;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int result = 0;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        board.push_back(one_line);
    }
    
    vector<pair<int, int>> direction = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j] == 1 && visited[i][j] == 0) {
                queue<pair<int, int>> que;
                que.push({i, j});
                visited[i][j] = 1;
                result += 1;
                
                while (!que.empty()) {
                    pair<int, int> now = que.front();
                    que.pop();
                    
                    for (int k=0; k<8; ++k) {
                        int nx = now.first + direction[k].first;
                        int ny = now.second + direction[k].second;
                        
                        if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0 && board[nx][ny] == 1) {
                            que.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    
    cout << result;

    return 0;
}
