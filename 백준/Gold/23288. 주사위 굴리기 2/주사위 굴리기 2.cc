#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int N, M, K;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int get_score(vector<vector<int>>& board, int x, int y) {
    int base = board[x][y];
    vector<vector<int>> visited(N, vector<int>(M, 0));
    visited[x][y] = 1;
    queue<pair<int, int>> que;
    que.push({x, y});
    
    int result = 1;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (visited[nx][ny] == 0 && board[nx][ny] == base) {
                    result += 1;
                    visited[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    
    return base * result;
    
}

int main()
{
    cin >> N >> M >> K;
    
    cin.ignore();
    
    vector<vector<int>> board;
    
    string data;
    int num;
    for (int i=0; i<N; ++i) {
        vector<int> one_line;
        getline(cin, data);
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        } 
        
        board.push_back(one_line);
    }
    
    vector<pair<int, int>> dice_rotate = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int now_idx = 0;
    
    pair<int, int> now = {0, 0};
    
    int top_dice = 1;
    int bottom_dice = 6;
    int left_dice = 4;
    int right_dice = 3;
    int front_dice = 5;
    int back_dice = 2;
    
    int result = 0;
    int tmp_data;
    
    for (int k=0; k<K; ++k) {
        int nx = now.first + direction[now_idx].first;
        int ny = now.second + direction[now_idx].second;
        
        // 이동 후 점수 계산
        if (0 <= nx && nx < N && 0 <= ny && ny < M) {
            now.first = nx;
            now.second = ny;
            result += get_score(board, nx, ny);
            
        } 
        
        else {
            now_idx = (now_idx + 2) % 4;
            nx = now.first + direction[now_idx].first;
            ny = now.second + direction[now_idx].second;
            
            now.first = nx;
            now.second = ny;
            result += get_score(board, nx, ny);
        }
        
        // 주사위 갱신
        if (now_idx == 0) {
            tmp_data = left_dice;
            
            left_dice = bottom_dice;
            bottom_dice = right_dice;
            right_dice = top_dice;
            top_dice = tmp_data;
            
        }
        else if (now_idx == 1) {
            tmp_data = top_dice;
            
            top_dice = back_dice;
            back_dice = bottom_dice;
            bottom_dice = front_dice;
            front_dice = tmp_data;

        }
        else if (now_idx == 2) {
            tmp_data = left_dice;
            
            left_dice = top_dice;
            top_dice = right_dice;
            right_dice = bottom_dice;
            bottom_dice = tmp_data;
            
        }
        else if (now_idx == 3) {
            tmp_data = top_dice;
            
            top_dice = front_dice;
            front_dice = bottom_dice;
            bottom_dice = back_dice;
            back_dice = tmp_data;
        }
        
        // cout << top_dice << " " << bottom_dice << " " << left_dice << " " << right_dice << " " << front_dice << " " << back_dice << "\n";
        
        // 이동 방향 갱신
        if (bottom_dice > board[now.first][now.second]) {
            now_idx = (now_idx + 1) % 4;
        }
        else if (bottom_dice < board[now.first][now.second]) {
            now_idx -= 1;
            if (now_idx < 0) {
                now_idx = 3;
            }
        }
    }
    
    cout << result;

    return 0;
}
