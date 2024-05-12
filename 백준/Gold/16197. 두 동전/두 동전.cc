#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // 입력 받기
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    string data;
    
    vector<vector<char>> board;
    
    pair<int, int> one_coin = {-1, -1};
    pair<int, int> two_coin;
    
    for (int n=0; n<N; ++n) {
        vector<char> one_line;
        getline(cin, data);
        
        for (int m=0; m<M; ++m) {
            one_line.push_back(data[m]);
            if (data[m] == 'o') {
                if (one_coin == make_pair(-1, -1)) {
                    one_coin = {n, m};
                }
                else {
                    two_coin = {n, m};
                }
            }
        }
        
        board.push_back(one_line);
    }
    
    // 순회하기
    int result = -1;
    
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    queue<pair<pair<int, int>, pair<int, int>>> que;
    queue<int> click_button;
    
    que.push({one_coin, two_coin});
    click_button.push(0);
    
    bool is_over = false;
    
    while (!que.empty()) {
        if (is_over == false) {
            pair<pair<int, int>, pair<int, int>> now = que.front();
            int now_click = click_button.front();
            que.pop();
            click_button.pop();
            
            for (int i=0; i<4; ++i) {
                int one_nx = now.first.first + directions[i].first;
                int one_ny = now.first.second + directions[i].second;
                int two_nx = now.second.first + directions[i].first;
                int two_ny = now.second.second + directions[i].second;
                
                bool check_one = true;
                bool check_two = true;
                
                if (0 <= one_nx && one_nx < N && 0 <= one_ny && one_ny < M) {
                    if (board[one_nx][one_ny] == '#') {
                        one_nx = now.first.first;
                        one_ny = now.first.second;
                    }
                }
                else {
                    check_one = false;
                }
                
                if (0 <= two_nx && two_nx < N && 0 <= two_ny && two_ny < M) {
                    if (board[two_nx][two_ny] == '#') {
                        two_nx = now.second.first;
                        two_ny = now.second.second;
                    }
                }
                else {
                    check_two = false;
                }
                
                if (check_one == true && check_two == true) {
                    if (now_click + 1 <= 9) {
                        que.push({{one_nx, one_ny}, {two_nx, two_ny}});
                        click_button.push(now_click + 1);
                    }
                }
                
                else if (check_one == false && check_two == false) {
                    continue;
                }
                
                else if ((check_one == false && check_two == true) || (check_one == true && check_two == false)) {
                    result = now_click + 1;
                    is_over = true;
                    
                }
            }
        }
        else {
            break;
        }
    }

    cout << result;

    return 0;
}
