#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> board;
    
    string data;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        vector<int> one_line;
        
        for (char c : data) {
            one_line.push_back(c - '0');
        }
        
        board.push_back(one_line);
    }
    
    vector<vector<int>> save_board(N, vector<int>(M, 0));
    
    int result = 0;
    
    for (int j=1; j<=M; ++j) {
        for (int i=1; i<=N; ++i) {
            
            if (j != 1) {
                if (i-1 != 0) {
                    save_board[i-1][j-1] = max(save_board[i-1][j-1], save_board[i-2][j-2]);
                }
                
                save_board[i-1][j-1] = max(save_board[i-1][j-1], save_board[i-1][j-2]);
                
                if (i != N) {
                    save_board[i-1][j-1] = max(save_board[i-1][j-1], save_board[i][j-2]);
                }
                
            }
            
            if (result < save_board[i-1][j-1]) {
                result = save_board[i-1][j-1];
            }
            
            save_board[i-1][j-1] += board[i-1][j-1];
        }
    }

    cout << result;

    return 0;
}
