#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool dfs(vector<int> passed, vector<pair<int, int>>& direction) {
    vector<vector<int>> check_board(5, vector<int>(5, 0));
    for (int i=0; i<7; ++i) {
        int now = passed[i];
        
        int x = now / 5;
        int y = now % 5;
        
        check_board[x][y] = 1;
    }
    
    queue<pair<int, int>> que;
    que.push({passed[0] / 5, passed[0] % 5});
    vector<vector<int>> visited(5, vector<int>(5, 0));
    visited[passed[0] / 5][passed[0] % 5] = 1;
    
    int cnt = 1;
    
    while (!que.empty()) {
        if (cnt == 7) {
            break;
        }
        
        pair<int, int> now_loca = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now_loca.first + direction[i].first;
            int ny = now_loca.second + direction[i].second;
            
            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && check_board[nx][ny] == 1 && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                cnt += 1;
                que.push({nx, ny});
                
            }
        }
    }
    
    if (cnt == 7) {
        return true;
    }
    else {
        return false;
    }
}

void search_team(vector<vector<char>>& classroom, int& result, vector<int> passed, vector<pair<int, int>>& direction, int Y, int S, int idx) {
    if (Y + S == 7) {
        if (S >= 4) {
            if (dfs(passed, direction) == true) {
                result += 1;
                return;
            }
        }
    }
    else {
        for (int i=idx; i<25; ++i) {
            if (find(passed.begin(), passed.end(), i) == passed.end()) {
                passed.push_back(i);
                int x = i / 5;
                int y = i % 5;
                if (classroom[x][y] == 'Y') {
                    Y += 1;
                }
                else {
                    S += 1;
                }
                
                search_team(classroom, result, passed, direction, Y, S, i+1);
                passed.pop_back();
                if (classroom[x][y] == 'Y') {
                    Y -= 1;
                }
                else {
                    S -= 1;
                }
                
            }
        }
    }
}


int main()
{
    vector<vector<char>> classroom;
    
    string data;
    
    for (int i=0; i<5; ++i) {
        cin >> data;
        vector<char> one_line;
        for (char c : data) {
            one_line.push_back(c);
        }
        
        classroom.push_back(one_line);
    }
    
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int result = 0;
    
    vector<int> passed;
    search_team(classroom, result, passed, direction, 0, 0, 0);

    cout << result;

    return 0;
}
