#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
vector<vector<char> > board(6, vector<char>(6, '.'));
int white_cnt = 2, black_cnt = 2;

vector<pair<int, int> > directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

bool change_pawn(int x, int y, int dir, char now_color)
{
    if (board[x][y] == now_color) {
        return true;
    }
    else if (board[x][y] != '.' && board[x][y] != now_color) {
        int nx = x + directions[dir].first; int ny = y + directions[dir].second;
        if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
            bool is_paint = change_pawn(nx, ny, dir, now_color);
            if (is_paint == true) {
                board[x][y] = now_color;
                if (now_color == 'W') {
                    white_cnt++;
                    black_cnt--;
                }
                else {
                    white_cnt--;
                    black_cnt++;
                }
                return true;
            }
        }
        return false;
    }
    else {
        return false;
    }
}

void print_answer()
{
    for (int i=0; i<6; ++i) {
        for (int j=0; j<6; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
    
    if (white_cnt > black_cnt) {
        cout << "White";
    }
    else {
        cout << "Black";
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    board[2][2] = board[3][3] = 'W';
    board[2][3] = board[3][2] = 'B';
    
    cin >> N;
    int x, y;
    int color = 0;
    char now_color;
    for (int i=0; i<N; ++i) {
        cin >> x >> y;
        if (color == 0) now_color = 'B';
        else now_color = 'W';
        bool is_set = false;
        for (int j=0; j<8; ++j) {
            int nx = x - 1 + directions[j].first;
            int ny = y - 1 + directions[j].second;
            if (0 <= nx && nx < 6 && 0 <= ny && ny < 6) {
                bool is_ok = change_pawn(nx, ny, j, now_color);
                if (is_ok == true && is_set == false) {
                    is_set = true;
                }
            }
        }
        board[x - 1][y - 1] = now_color;
        color = (color + 1) % 2;
    }
    
    print_answer();
    
    return 0;
}