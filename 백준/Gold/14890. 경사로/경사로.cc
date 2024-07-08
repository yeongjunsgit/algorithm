#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, L;

vector<pair<int, int>> direction = {{1, 0}, {0, 1}};

int across_line(vector<vector<int>>& board, int num, int version) {
    int base;
    pair<int, int> now;
    if (version == 0) {
        base = board[0][num];
        now = {0, num};
    }
    else {
        base = board[num][0];
        now = {num, 0};
    }
    
    int area = 1;

    while (now.first != N && now.second != N) {
        pair<int, int> next_node = {now.first + direction[version].first, now.second + direction[version].second};
        if (next_node.first >= N && version == 0) {
            break;
        }
        else if (next_node.second >= N && version == 1) {
            break;
        }
        
        if (board[next_node.first][next_node.second] == base) {
            area += 1;
            now = next_node;
        }
        
        else if (board[next_node.first][next_node.second] == base + 1) {
            if (area >= L) {
                base = board[next_node.first][next_node.second];
                area = 1;
                now = next_node;
            }
            else {
                return 0;
            }
        }
        
        else if (board[next_node.first][next_node.second] + 1 == base) {
            int tmp_area = 1;
            pair<int, int> tmp_now = {next_node.first, next_node.second};
            while (tmp_area < L) {
                int nx = tmp_now.first + direction[version].first;
                int ny = tmp_now.second + direction[version].second;
                
                if (nx < N && ny < N) {
                    if (board[next_node.first][next_node.second] == board[nx][ny]) {
                        tmp_area += 1;
                        tmp_now = {nx, ny};
                    }
                    else {
                        break;
                    }
                }
                else {
                    return 0;
                }
            }
            
            if (tmp_area == L) {
                area = 0;
                now = tmp_now;
                base = board[now.first][now.second];
            }
            else {
                return 0;
            }
        }
        
        else {
            return 0;
        }
    }
    
    return 1;
}

int main()
{
    cin >> N >> L;
    cin.ignore();
    
    vector<vector<int>> board;
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        board.push_back(one_line);
    }
    
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        result += across_line(board, i, 0);
        result += across_line(board, i, 1);
    }

    cout << result;

    return 0;
}
