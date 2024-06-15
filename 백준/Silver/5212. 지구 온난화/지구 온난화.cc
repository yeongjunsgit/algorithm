#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    cin.ignore();
    vector<vector<char>> board;
    
    string data;
    
    for (int i=0; i<N; ++i) {
        vector<char> one_line;
        getline(cin, data);
        
        for (char c : data) {
            one_line.push_back(c);
        }
        
        board.push_back(one_line);
        
    }

    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int start_x = 99999;
    int start_y = 99999;
    int end_x = -1;
    int end_y = -1;
    
    vector<pair<int, int>> change_lis;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j] == 'X') {
                int check_sea = 0;
                for (int k=0; k<4; ++k) {
                    int nx = i + direction[k].first;
                    int ny = j + direction[k].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                        if (board[nx][ny] == '.') {
                            check_sea += 1;
                        }
                    }
                    else {
                        check_sea += 1;
                    }
                }
                
                if (check_sea >= 3) {
                    change_lis.push_back({i, j});
                }
                
                else {
                    if (start_x > i) {
                        start_x = i;
                    }
                    if (start_y > j) {
                        start_y = j;
                    }
                    if (end_x < i) {
                        end_x = i;
                    }
                    if (end_y < j) {
                        end_y = j;
                    }
                }
            }
        }
    }
    
    for (pair<int, int> p : change_lis) {
        board[p.first][p.second] = '.';
    }
    
    for (int i=start_x; i<=end_x; ++i) {
        for (int j=start_y; j<=end_y; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}
