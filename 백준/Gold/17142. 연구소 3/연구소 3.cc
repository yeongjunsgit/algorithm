#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, virus_cnt = 0, zero_cnt = 0, result = 99999999;
vector<vector<int> > board(50, vector<int>(50));
vector<pll> virus_loca;
vector<int> used;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void set_virus()
{
    vector<vector<int> > visited(N, vector<int>(N, 99999999));
    queue<pll> que;
    for (int i=0; i<virus_cnt; ++i) {
        if (used[i] == 1) {
            que.push(virus_loca[i]);
            visited[virus_loca[i].first][virus_loca[i].second] = 0;
        }
    }
    
    int cnt = 0, tmp_zero = 0;
    while (true) {
        queue<pll> next_que;
        queue<pll> tmp_que;
        while (!que.empty()) {
            pll now = que.front();
            que.pop();
            
            for (int i=0; i<4; ++i) {
                int nx = now.first + directions[i].first;
                int ny = now.second + directions[i].second;
                
                if (0 <= nx && nx < N && 0 <= ny && ny < N && board[nx][ny] != 1) {
                    if (visited[nx][ny] > visited[now.first][now.second] + 1) {
                        visited[nx][ny] = visited[now.first][now.second] + 1;
                        if (board[nx][ny] == 2) {
                            tmp_que.push({nx, ny});
                        }
                        else {
                            next_que.push({nx, ny});
                            tmp_zero++;
                        }
                    }
                }
            }
        }
        if ((next_que.empty() && tmp_que.empty()) || (next_que.empty() && zero_cnt == tmp_zero)) break;
        
        if (!tmp_que.empty()) {
            while (!tmp_que.empty()) {
                next_que.push(tmp_que.front());
                tmp_que.pop();
            }
        }
        que = next_que;
        cnt++;
        if (zero_cnt == tmp_zero) break;
        if (result < cnt) break;
    }
    
    if (tmp_zero == zero_cnt) {
        result = min(result, cnt);
    }
    
    return;
}


void combicombi(int idx, int depth)
{
    if (depth == M) {
        set_virus();
    }
    else {
        for (int i=idx; i<virus_cnt; ++i) {
            if (used[i] == 0) {
                used[i] = 1;
                combicombi(i + 1, depth + 1);
                used[i] = 0;
            }
        }
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus_cnt++;
                virus_loca.push_back({i, j});
            }
            else if (board[i][j] == 0) zero_cnt++;
        }
    }
    used.resize(virus_cnt, 0);
    
    combicombi(0, 0);
    if (result == 99999999) cout << -1;
    else cout << result;

    return 0;
}
