#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > board(7, vector<int>(3, 0));

void is_possible(vector<vector<int> >& connected, int& result, int depth, int idx, int cnt, int draw_idx, int draw_cnt)
{
    if (depth == 6) {
        for (int i=0; i<6; ++i) {
            for (int j=0; j<3; ++j) {
                if (board[i][j] != 0) return;
            }
        }
        result = 1;
        return;
    }
    
    if (cnt > 0) {
        for (int i=idx; i<6; ++i) {
            if (i != depth && connected[depth][i] == 0 && board[i][2] > 0) {
                connected[depth][i] = 1; connected[i][depth] = 1;
                board[i][2]--;
                board[depth][0]--;
                is_possible(connected, result, depth, i + 1, cnt - 1, draw_idx, draw_cnt);
                connected[depth][i] = 0; connected[i][depth] = 0;
                board[i][2]++;
                board[depth][0]++;
            }
        }
    }
    
    if (cnt == 0 && draw_cnt > 0) {
        for (int i=draw_idx; i<6; ++i) {
            if (i != depth && connected[depth][i] == 0 && board[i][1] > 0) {
                connected[depth][i] = 1; connected[i][depth] = 1;
                board[i][1]--;
                board[depth][1]--;
                is_possible(connected, result, depth, idx, cnt, i, draw_cnt - 1);
                connected[depth][i] = 0; connected[i][depth] = 0;
                board[i][1]++;
                board[depth][1]++;
            }
        }
    }
    
    if (cnt == 0 && draw_cnt == 0) {
        is_possible(connected, result, depth + 1, 0, board[depth + 1][0], 0, board[depth + 1][1]);
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int t=0; t<4; ++t) {
        vector<vector<int> > connected(6, vector<int>(6, 0));
        int result = 0, wins = 0, loses = 0;
        bool is_collect = true;
        for (int i=0; i<6; ++i) {
            for (int j=0; j<3; ++j) {
                cin >> board[i][j];
                if (j == 0) wins += board[i][j];
                if (j == 2) loses += board[i][j];
            }
        }
        
        for (int i=0; i<6; ++i) {
            if (board[i][0] + board[i][1] + board[i][2] != 5) {
                is_collect = false;
                break;
            }
        }
        
        if (wins != loses) is_collect = false;
        
        if (is_collect) is_possible(connected, result, 0, 0, board[0][0], 0, board[0][1]);
        
        cout << result << " ";
        
    }

    return 0;
}
