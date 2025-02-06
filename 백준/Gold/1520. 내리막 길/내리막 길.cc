#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<pll> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void downroad()
{
    vector<vector<int> > visited(N, vector<int>(M, 0));
    vector<vector<int> > pushed(N, vector<int>(M, 0));
    visited[0][0] = 1;
    priority_queue<pair<int, pll> > que;
    que.push({board[0][0], {0, 0}});
    
    while (!que.empty()) {
        pll now = que.top().second;
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[now.first][now.second] > board[nx][ny]) {
                visited[nx][ny] += visited[now.first][now.second];
                if (pushed[nx][ny] == 0) {
                    pushed[nx][ny] = 1;
                    que.push({board[nx][ny], {nx, ny}});
                }
            } 
        }
    }
    
    cout << visited[N-1][M-1];
    
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
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        board.push_back(one_line);
    }
    
    downroad();

    return 0;
}
