#include <iostream>
#include <sstream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board, visited;
int result = 0;

void divide_paper(int now_power, int covered, int col_idx, int low_idx)
{
    if (covered == N * M) {
        if (result < now_power) {
            result = now_power;
        }
        return;
    }
    
    int idx, now, weight, cnt;
    for (int i=col_idx; i<N; ++i) {
        idx = 0, now = 0, weight = 10, cnt = 0;
        vector<pll> now_loca;
        while (idx < M) {
            if (visited[i][idx] == 0) {
                cnt++;
                now *= weight;
                now += board[i][idx];
                now_loca.push_back({i, idx});
            }
            else {
                if (cnt != 0) {
                    for (pll p : now_loca) {
                        visited[p.first][p.second] = 1;
                    }
                    divide_paper(now_power + now, covered + cnt, i, low_idx);
                    for (pll p : now_loca) {
                        visited[p.first][p.second] = 0;
                    }
                    now = 0;
                    now_loca.clear();
                    cnt = 0;
                }
            }
            idx++;
        }
        if (cnt != 0) {
            for (pll p : now_loca) {
                visited[p.first][p.second] = 1;
            }
            divide_paper(now_power + now, covered + cnt, i+1, low_idx);
            for (pll p : now_loca) {
                visited[p.first][p.second] = 0;
            }
        }
    } 
    
    for (int i=low_idx; i<M; ++i) {
        idx = 0, now = 0, weight = 10, cnt = 0;
        vector<pll> now_loca;
        while (idx < N) {
            if (visited[idx][i] == 0) {
                cnt++;
                now *= weight;
                now += board[idx][i];
                now_loca.push_back({idx, i});
            }
            else {
                if (cnt != 0) {
                    for (pll p : now_loca) {
                        visited[p.first][p.second] = 1;
                    }
                    divide_paper(now_power + now, covered + cnt, col_idx, i);
                    for (pll p : now_loca) {
                        visited[p.first][p.second] = 0;
                    }
                    now = 0;
                    now_loca.clear();
                    cnt = 0;
                }
            }
            idx++;
        }
        if (cnt != 0) {
            for (pll p : now_loca) {
                visited[p.first][p.second] = 1;
            }
            divide_paper(now_power + now, covered + cnt, col_idx, i + 1);
            for (pll p : now_loca) {
                visited[p.first][p.second] = 0;
            }
        }
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin.ignore();
    
    visited.resize(N, vector<int>(M, 0));
    int num;
    string data;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        for (char c : data) {
            one_line.push_back(c - '0');
        }
        board.push_back(one_line);
    }
    
    divide_paper(0, 0, 0, 0);
    
    cout << result;

    return 0;
}
