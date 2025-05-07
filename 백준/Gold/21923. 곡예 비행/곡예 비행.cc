#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board(1000, vector<int>(1000, 0));
vector<vector<pll> > directions = {{{-1, 0}, {0, 1}}, {{1, 0}, {0, 1}}};

void lets_fly()
{
    vector<vector<int> > up_fly(N, vector<int>(M, -20000001));
    vector<vector<int> > down_fly(N, vector<int>(M, -20000001));
    
    up_fly[N-1][0] = board[N-1][0];
    for (int i=N-1; i>=0; --i) {
        for (int j=0; j<M; ++j) {
            for (int k=0; k<2; ++k) {
                int ni = i + directions[0][k].first;
                int nj = j + directions[0][k].second;
                
                if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                    up_fly[ni][nj] = max(up_fly[ni][nj], up_fly[i][j] + board[ni][nj]);
                }
            }
        }
    }
    
    down_fly[0][0] = up_fly[0][0] + board[0][0];
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            for (int k=0; k<2; ++k) {
                int ni = i + directions[1][k].first;
                int nj = j + directions[1][k].second;
                                
                if (0 <= ni && ni < N && 0 <= nj && nj < M) {
                    down_fly[ni][nj] = max({down_fly[ni][nj], up_fly[ni][nj] + board[ni][nj], down_fly[i][j] + board[ni][nj]});
                }
            }
        }
    }
    
    cout << down_fly[N-1][M-1];
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    
    lets_fly();

    return 0;
}
