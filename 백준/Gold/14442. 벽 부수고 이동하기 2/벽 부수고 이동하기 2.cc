#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
vector<vector<int> > board;
vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int result = 1000001;

struct my_node {
    int x;
    int y;
    int dist;
    int HP;
};

void bfs()
{
    queue<my_node> que;
    que.push({0, 0, 1, K});
    vector<vector<vector<int> > > visited(K + 1, vector<vector<int> >(N, vector<int>(M, 0)));
    visited[0][0][0] = 1;
    
    while (!que.empty()) {
        my_node now = que.front();
        que.pop();
        if (now.x == N - 1 && now.y == M - 1) {
            result = now.dist;
            return;
        }
        
        for (int i=0; i<4; ++i) {
            int nx = now.x + direction[i].first;
            int ny = now.y + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (board[nx][ny] == 1) {
                    if (now.HP - 1 >= 0 && visited[now.HP - 1][nx][ny] == 0) {
                        visited[now.HP - 1][nx][ny] = 1;
                        que.push({nx, ny, now.dist + 1, now.HP - 1});
                    }
                }
                else if (board[nx][ny] == 0) {
                    if (visited[now.HP][nx][ny] == 0) {
                        visited[now.HP][nx][ny] = 1;
                        que.push({nx, ny, now.dist + 1, now.HP});
                    }
                }
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    
    string data;
    for (int i=0; i<N; ++i) {
        vector<int> one_line;
        cin >> data;
        for (char a : data) {
            one_line.push_back(a - '0');
        }
        board.push_back(one_line);
    }
    
    bfs();
    
    if (result == 1000001) {
        cout << -1;
    }
    else {
        cout << result;
    }

    return 0;
}
