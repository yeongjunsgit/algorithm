/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N, M;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> board;
    
    board.push_back(vector<int>(M+2, 0));
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        one_line.push_back(0);
        while (iss >> num) {
            one_line.push_back(num);
        }
        one_line.push_back(0);
        
        board.push_back(one_line);
    }
    
    board.push_back(vector<int>(M+2, 0));
    
    queue<pair<int, int>> que;
    que.push({0, 0});
    
    int cnt = 0;
    vector<vector<int>> visited(N+2, vector<int>(M+2, 0));
    
    while (!que.empty()) {
        vector<vector<int>> tmp_board = board;
        queue<pair<int, int>> cheeze_queue;
        queue<pair<int, int>> next_queue;
        map<pair<int, int>, int> check_cheeze;
        bool is_melt = false;
        
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            
            for (int i=0; i<4; ++i) {
                int nx = now.first + direction[i].first;
                int ny = now.second + direction[i].second;
                
                if (0 <= nx && nx < N+2 && 0 <= ny && ny < M+2) {
                    if (board[nx][ny] == 0 && visited[nx][ny] == 0) {
                        que.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                    else if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
                        if (check_cheeze.find({nx, ny}) == check_cheeze.end()) {
                            cheeze_queue.push({nx, ny});
                            check_cheeze[{nx, ny}] = 1;
                        }
                    }
                }
            }
        }
        
        while (!cheeze_queue.empty()) {
            pair<int, int> now_cheeze = cheeze_queue.front();
            cheeze_queue.pop();
            int air_cnt = 0;
            
            for (int i=0; i<4; ++i) {
                int nx = now_cheeze.first + direction[i].first;
                int ny = now_cheeze.second + direction[i].second;
                
                if (0 <= nx && nx < N+2 && 0 <= ny && ny < M+2) {
                    if (board[nx][ny] == 0 && visited[nx][ny] == 1) {
                        air_cnt += 1;
                    }
                }
                else {
                    air_cnt += 1;
                }
                
                if (air_cnt >= 2) {
                    next_queue.push({now_cheeze.first, now_cheeze.second});
                    visited[now_cheeze.first][now_cheeze.second] = 1;
                    tmp_board[now_cheeze.first][now_cheeze.second] = 0;
                    is_melt = true;
                }
            }
        }
        
        if (is_melt == false) {
            break;
        }
        else {
            cnt += 1;
            board = tmp_board;
            que = next_queue;
        }
    }
    
    cout << cnt;

    return 0;
}
