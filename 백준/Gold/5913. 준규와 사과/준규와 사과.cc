#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

vector<vector<int> > board(6, vector<int>(6, 0));

int N, s, e, result = 0;
pll junkyu = {1, 1}, haebin = {5, 5};
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int turn)
{
    if (turn > 23 - N) return;
    
    int nx, ny;
    for (int i=0; i<4; ++i) {
        if (turn % 2 == 0) {
            nx = junkyu.first + directions[i].first;
            ny = junkyu.second + directions[i].second;
        }
        else {
            nx = haebin.first + directions[i].first;
            ny = haebin.second + directions[i].second;
        }
        if (1 <= nx && nx <= 5 && 1 <= ny && ny <= 5) {
            // if (turn == 19 && nx == 3 && ny == 5) cout << turn << "-" << i << " {" << nx << ", " << ny << "} + {" << junkyu.first << ", " << junkyu.second << "}\n"; 
            // 마지막 나무에서 만나는 경우는 따로 관리
            if (turn == 23 - N && nx == junkyu.first && ny == junkyu.second) result++;
            
            else {
                if (board[nx][ny] != 1) {
                    board[nx][ny] = 1;
                    if (turn % 2 == 0) {
                        junkyu.first += directions[i].first;
                        junkyu.second += directions[i].second;
                        dfs(turn + 1);
                        junkyu.first -= directions[i].first;
                        junkyu.second -= directions[i].second;
                        
                    }
                    else {
                        haebin.first += directions[i].first;
                        haebin.second += directions[i].second;
                        dfs(turn + 1);
                        haebin.first -= directions[i].first;
                        haebin.second -= directions[i].second;
                    }
                    board[nx][ny] = 0;
                }
            }
            
        }
    }
    
    return;
    
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        board[s][e] = 1;
    }
    board[1][1] = 1;
    board[5][5] = 1;
    dfs(0);
    
    cout << result;

    return 0;
}

