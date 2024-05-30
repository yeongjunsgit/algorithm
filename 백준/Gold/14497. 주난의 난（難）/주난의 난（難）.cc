#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<vector<char>> board;
    
    pair<int, int> junan;
    pair<int, int> thief;
    
    for (int i=0; i<N; ++i) {
        vector<char> one_line;
        char ele;
        for (int j=0; j<M; ++j) {
            cin >> ele;
            one_line.push_back(ele);
            if (ele == '*') {
                junan = {i, j};
            }
            else if (ele == '#') {
                thief = {i, j};
            }
        }
        
        board.push_back(one_line);
    }

    int charge_jump = 0;
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<pair<int, int>> recent_break;
    queue<pair<int, int>> recent_break_que;
    bool catch_thief = false;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    
    while (catch_thief == false) {
        charge_jump += 1;
        if (recent_break.size() == 0) {
            queue<pair<int, int>> que;
            que.push(junan);
            
            while (!que.empty()) {
                pair<int, int> now = que.front();
                que.pop();
                
                for (int i=0; i<4; ++i) {
                    int nx = now.first + direction[i].first;
                    int ny = now.second + direction[i].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0) {
                        if (board[nx][ny] == '0') {
                            que.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                        else if (board[nx][ny] == '1') {
                            recent_break.push_back({nx, ny});
                            recent_break_que.push({nx, ny});
                            visited[nx][ny] = 1;
                        }
                        else if (board[nx][ny] == '#') {
                            catch_thief = true;
                            break;
                        }
                    }
                }
            }
            for (int i=0; i<recent_break.size(); ++i) {
                board[recent_break[i].first][recent_break[i].second] = '0';
            }
        }
        else {
            vector<pair<int, int>> tmp_recent_break;
            queue<pair<int, int>> tmp_recent_break_que;
            
            for (int i=0; i<recent_break.size(); ++i) {
                while (!recent_break_que.empty()) {
                    pair<int, int> now = recent_break_que.front();
                    recent_break_que.pop();
                    
                    for (int i=0; i<4; ++i) {
                        int nx = now.first + direction[i].first;
                        int ny = now.second + direction[i].second;
                        
                        if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0) {
                            if (board[nx][ny] == '0') {
                                recent_break_que.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                            else if (board[nx][ny] == '1') {
                                tmp_recent_break.push_back({nx, ny});
                                tmp_recent_break_que.push({nx, ny});
                                visited[nx][ny] = 1;
                            }
                            else if (board[nx][ny] == '#') {
                                catch_thief = true;
                                break;
                            }
                        }
                    }
                }
            }
            
            recent_break = tmp_recent_break;
            recent_break_que = tmp_recent_break_que;
            
            for (int i=0; i<recent_break.size(); ++i) {
                board[recent_break[i].first][recent_break[i].second] = '0';
            }
        }
    }
    
    cout << charge_jump;

    return 0;
}
