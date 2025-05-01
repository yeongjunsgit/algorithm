#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, D;

vector<vector<int> > board(15, vector<int>(15, 0));
vector<pll> directions = {{0, -1}, {-1, 0}, {0, 1}};
vector<int> pick_up(3, 0);
int result = 0;

int shot_arrow(vector<vector<int> >& visited)
{
    int sumsum = 0;
    for (int t=0; t<N; ++t) {
        int now_line = N - 1 - t;
        for (int i=0; i<3; ++i) {
            queue<pair<pll, int> > que;
            que.push({{now_line, pick_up[i]}, 0});
            while (!que.empty()) {
                pll now_node = que.front().first;
                int depth = que.front().second;
                que.pop();
                if (board[now_node.first][now_node.second] == 1) {
                    if (visited[now_node.first][now_node.second] == -1) {
                        visited[now_node.first][now_node.second] = t;
                        sumsum++;
                        break;
                    }
                    else if (visited[now_node.first][now_node.second] == t) {
                        break;
                    }
                }
                for (int k=0; k<3; ++k) {
                    int nx = now_node.first + directions[k].first;
                    int ny = now_node.second + directions[k].second;
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (depth + 1 < D) {
                            que.push({{nx, ny}, depth + 1});
                        }
                    }
                }
            }
        }
    }
    
    return sumsum;
}

void get_score(int idx, int depth)
{
    if (depth == 3) {
        vector<vector<int> > visited(N, vector<int>(M, -1));
        result = max(result, shot_arrow(visited));
        return;
    }
    
    for (int i=idx; i<M; ++i) {
        pick_up[depth] = i;
        get_score(i + 1, depth + 1);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> D;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    
    get_score(0, 0);
    cout << result;

    return 0;
}
