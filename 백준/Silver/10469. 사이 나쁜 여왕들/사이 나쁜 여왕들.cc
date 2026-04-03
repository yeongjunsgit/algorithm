#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

vector<vector<char> > board(8, vector<char>(8));
vector<pll> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool check_now(int x, int y)
{
    for (int i=0; i<8; ++i) {
        int nx = x, ny = y;
        while (true) {
            nx += directions[i].first;
            ny += directions[i].second;
            if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
                if (board[nx][ny] == '*') return false;
            }
            else break;
            
        }
    }
    
    return true;
}


bool search_start()
{
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if (board[i][j] == '*') {
                bool now_check = check_now(i, j);
                if (!now_check) return false;
            }
        }
    }
    
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt = 0;
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            cin >> board[i][j];
            if (board[i][j] == '*') cnt++;
        }
    }
    if (cnt != 8) cout << "invalid";
    else {
        bool result = search_start();
        if (!result) cout << "invalid";
        else cout << "valid";
    }

    return 0;
}

