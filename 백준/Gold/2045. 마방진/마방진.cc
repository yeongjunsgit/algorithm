#include <iostream>
#include <vector>
#include <map>

#define pll pair<int, int>

using namespace std;

vector<vector<int> > board(3, vector<int>(3, 0));

int main()
{
    int num;
    
    map<pll, int> zeros;
    vector<pll> z_idx;
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> num;
            board[i][j] = num;
            if (num == 0) z_idx.push_back({i, j});
        }
    }
    
    int basic = 0;
    
    for (int i=0; i<3; ++i) {
        int col = 0; int low = 0; int c_zero = 0; int l_zero = 0;
        pll c_p, l_p;
        for (int j=0; j<3; ++j) {
            if (board[j][i] != 0) col += board[j][i];
            else {
                c_zero++; 
                c_p = {j, i};
            }
            if (board[i][j] != 0) low += board[i][j];
            else {
                l_zero++;
                l_p = {i, j};
            }
        }
        if (c_zero == 0) basic = col;
        else if (c_zero == 1) zeros[c_p] = col;
        
        if (l_zero == 0) basic = low;
        else if (l_zero == 1) zeros[l_p] = low;
    }
    
    int left = 0; int right = 0; int le_zero = 0; int r_zero = 0;
    pll ri_p, le_p;
    for (int i=0; i<3; ++i) {
        if (board[i][i] != 0) left += board[i][i];
        else {
            le_zero++;
            le_p = {i, i};
        }
        if (board[i][2 - i] != 0) right += board[i][2 - i];
        else {
            r_zero++;
            ri_p = {i, 2 - i};
        }
    }
    
    if (le_zero == 0) basic = left;
    else if (le_zero == 1) zeros[le_p] = left;
    
    if (r_zero == 0) basic = right;
    else if (r_zero == 1) zeros[ri_p] = right;
    
    if (basic != 0) {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (board[i][j] == 0) board[i][j] = basic - zeros[{i, j}];
            }
        }
    }
    else {
        int xy = zeros[z_idx[2]];
        int xz = zeros[z_idx[1]];
        int yz = zeros[z_idx[0]];
        
        int x = (xy + xz - yz) / 2;
        int y = xy - x;
        int z = yz - y;
        
        board[z_idx[0].first][z_idx[0].second] = x;
        board[z_idx[1].first][z_idx[1].second] = y;
        board[z_idx[2].first][z_idx[2].second] = z;
    }
    
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
