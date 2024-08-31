#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<pair<int, int> > direction = {{-1, 0}, {0, -1}, {-1, -1}};

struct Compare {
    bool operator()(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
        return a.first < b.first;
    }
};

void bfs(vector<vector<int> >& board)
{
    vector<vector<int> > visited(N, vector<int>(M, -1));
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            visited[i][j] = board[i][j];
            int tmp = visited[i][j];
            for (int k=0; k<3; ++k) {
                int nx = i + direction[k].first;
                int ny = j + direction[k].second;
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    visited[i][j] = max(visited[i][j], tmp + visited[nx][ny]);
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
    
    vector<vector<int> > board;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        while (iss >> num) {
            one_line.push_back(num);
        }
        board.push_back(one_line);
    }
    
    bfs(board);

    return 0;
}
