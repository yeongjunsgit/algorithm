#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, M, A, B, s, e;
vector<vector<int> > board(101, vector<int>(101, 0)), must_have(101, vector<int>(101, 0));
vector<vector<pll> > visited(101, vector<pll>(101, {0, 0}));
vector<pll> directions = {{0, 1}, {1, 0}};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> A >> B;
    
    // 1 = 아이템, 2 = 장애물
    for (int i=0; i<A; ++i) {
        cin >> s >> e;
        board[s][e] = 1;
    }
    for (int i=0; i<B; ++i) {
        cin >> s >> e;
        board[s][e] = 2;
    }
    int before_item = 0;
    for (int i=1; i<=N; ++i) {
        int now_item = before_item;
        for (int j=1; j<=M; ++j) {
            must_have[i][j] = max(must_have[i][j], before_item);
            
            if (j + 1 <= M) must_have[i][j+1] = max(must_have[i][j+1], must_have[i][j]);
            if (i + 1 <= N) must_have[i+1][j] = max(must_have[i+1][j], must_have[i][j]);
            
            if (board[i][j] == 1) {
                now_item++;
                if (j + 1 <= M) must_have[i][j+1]++;
                if (i + 1 <= N) must_have[i+1][j]++;
            }
        }
        before_item = now_item;
    }
    
    visited[1][1] = {1, 0};
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            for (int k=0; k<2; ++k) {
                int nx = i + directions[k].first;
                int ny = j + directions[k].second;
                
                if (1 <= nx && nx <= N && 1 <= ny && ny <= M && board[nx][ny] != 2 && must_have[nx][ny] <= visited[i][j].second) {
                    int next_item = visited[i][j].second;
                    if (board[nx][ny] == 1) next_item++;
                    visited[nx][ny].first += visited[i][j].first;
                    visited[nx][ny].second = next_item;
                }
            }
        }
    }
            
    cout << visited[N][M].first;

    return 0;
}
