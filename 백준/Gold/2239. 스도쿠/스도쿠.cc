#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

bool dfs(int x, int y)
{
    if (y == 9) {
        x++;
        y = 0;
        if (x == 9) {
            return true;
        }
    }
    
    if (board[x][y] == 0) {
        vector<bool> now_select(10, true);
    
        for (int k=0; k<9; ++k) {
            // 가로 라인 보기
            if (board[x][k] != 0) {
                if (now_select[board[x][k]] == true) {
                    now_select[board[x][k]] = false;
                }
            }
            // 세로 라인 보기
            if (board[k][y] != 0) {
                if (now_select[board[k][y]] == true) {
                    now_select[board[k][y]] = false;
                }
            }
        }
        // 9블록 구간 보기
        int x_block = x / 3;
        int y_block = y / 3;
        
        for (int q = x_block * 3; q < x_block * 3 + 3; ++q) {
            for (int p = y_block * 3; p < y_block * 3 + 3; ++p) {
                if (board[q][p] != 0) {
                    if (now_select[board[q][p]] == true) {
                        now_select[board[q][p]] = false;
                    }
                }
            }
        }
        
        for (int k=1; k<10; ++k) {
            if (now_select[k] == true) {
                board[x][y] = k;
                bool is_ok = dfs(x, y+1);
                if (is_ok == true) {
                    return true;
                }
            }
        }
        board[x][y] = 0;
        return false;
    }
    else {
        bool is_ok = dfs(x, y+1);
        if (is_ok == true) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main()
{
    string data;
    for (int i=0; i<9; ++i) {
        cin >> data;
        
        vector<int> one_line;
        
        for (char c : data) {
            one_line.push_back(c - '0');
        }
        
        board.push_back(one_line);
    }
    
    dfs(0, 0);
    
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}