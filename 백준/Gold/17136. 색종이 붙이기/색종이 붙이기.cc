#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define pll pair<int, int>

using namespace std;

vector<vector<int> > board(10, vector<int>(10, 0));
vector<vector<int> > can_size(10, vector<int>(10, 0));
vector<vector<bool> > visited(10, vector<bool>(10, false));
unordered_map<int, int> use_paper = {{1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}};
vector<pll> direction = {{0, 1}, {1, 0}, {1, 1}};
int result = 26;

int find_size(int x, int y)
{
    int now_size = 1;
    queue<pll> passed;
    passed.push({x, y});
    vector<vector<bool> > tmp_visited(10, vector<bool>(10, false));
    tmp_visited[x][y] = true;
    
    while (now_size < 5) {
        queue<pll> tmp;
        while (!passed.empty()) {
            pll now = passed.front();
            passed.pop();
            for (int i=0; i<3; ++i) {
                int nx = now.first + direction[i].first;
                int ny = now.second + direction[i].second;
                
                if (0 <= nx && nx < 10 && 0 <= ny && ny < 10 && board[nx][ny] == 1) {
                    if (tmp_visited[nx][ny] == false) {
                        tmp_visited[nx][ny] = true;
                        tmp.push({nx, ny});
                    }
                }
                else {
                    return now_size;
                }
            }
        }
        passed = tmp;
        now_size++;
    }
    
    return now_size;
}

void attach_paper()
{
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            if (board[i][j] == 1) {
                can_size[i][j] = find_size(i, j);
            }
        }
    }
    
    return;
}

void in_to_the_brain(int x, int y, int papers)
{
    if (papers > result) {
        return;
    }
    
    if (y == 10) {
        x++;
        y = 0;
        if (x == 10) {
            if (result > papers) {
                result = papers;
            }
            return;
        }
    }
    
    if (visited[x][y] == false && board[x][y] == 1) {
        int now_power = can_size[x][y];
        while (now_power > 0) {
            bool is_ok = true;
            for (int i=0; i<now_power; ++i) {
                if (is_ok == false) {
                    break;
                }
                for (int j=0; j<now_power; ++j) {
                    if (visited[x + i][y + j] == true) {
                        is_ok = false;
                        break;
                    }
                }
            }
            
            if (is_ok == true) {
                for (int i=0; i<now_power; ++i) {
                    for (int j=0; j<now_power; ++j) {
                        visited[x + i][y + j] = true;
                    }
                }
                use_paper[now_power]--;
                
                if (use_paper[now_power] < 0) {
                    for (int i=0; i<now_power; ++i) {
                        for (int j=0; j<now_power; ++j) {
                            visited[x + i][y + j] = false;
                        }
                    }
                    use_paper[now_power]++;
                    now_power--;
                    
                    continue;
                }
                
                in_to_the_brain(x, y + 1, papers + 1);
                
                for (int i=0; i<now_power; ++i) {
                    for (int j=0; j<now_power; ++j) {
                        visited[x + i][y + j] = false;
                    }
                }
                use_paper[now_power]++;
            }
            
            now_power--;
            
        }
    }
    else {
        in_to_the_brain(x, y + 1, papers);
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int num;
    
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            cin >> num;
            board[i][j] = num;
        }
    }
    
    attach_paper();
    
    in_to_the_brain(0, 0, 0);
    
    if (result != 26) {
        cout << result;
    }
    else {
        cout << -1;
    }

    return 0;
}
