#include <iostream>
#include <vector>

using namespace std;

int N, result = 0;
vector<vector<char> > board(100, vector<char>(100));
vector<pair<int, int> > directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

void check_around(int x, int y)
{
    for (int i=0; i<8; ++i) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;
        
        if (('1' <= board[nx][ny] && board[nx][ny] <= '9') || board[nx][ny] == '#') {
            continue;
        }
        else return;
    }
    
    for (int i=0; i<8; ++i) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;
        if ('1' <= board[nx][ny] && board[nx][ny] <= '9') board[nx][ny]--;
    }
    
    result++;
    
    return;
}

void find_mine()
{
    for (int i=1; i<N-1; ++i) {
        for (int j=1; j<N-1; ++j) {
            if (i == 1 || i == N-2) {
                check_around(i, j);
            }
            else if (j == 1 || j == N-2) {
                check_around(i, j);
            }
            else {
                result++;
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
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
        }
    }
    
    find_mine();
    
    cout << result;

    return 0;
}
