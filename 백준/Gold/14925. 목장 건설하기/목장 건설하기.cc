#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

vector<pair<int, int>> check_method = {{0, 1}, {1, 0}};

int check_square(vector<vector<int>>& area, vector<vector<int>>& visited, int& result, int x, int y) {
    queue<pair<int, int>> top_line;
    top_line.push({x, y});
    
    int ny = y;
    
    vector<int> col; 
    int row = 1;
    
    while (true) {
        ny += 1;
        
        if (ny < M && area[x][ny] == 0) {
            top_line.push({x, ny});
            visited[x][ny] = 1;
            row += 1;
        }
        else {
            break;
        }
    }
    
    if (row <= result) {
        return 0;
    }
    
    int col_max = 0;
    
    while (!top_line.empty()) {
        pair<int, int> now = top_line.front();
        top_line.pop();
        int nx = now.first;
        
        int tmp_col = 1;
        while (true) {
            nx += 1;
            
            if (nx < N && area[nx][now.second] == 0) {
                tmp_col += 1;
            }
            else {
                break;
            }
        }
        col.push_back(tmp_col);
        if (col_max < tmp_col) {
            col_max = tmp_col;
        }
    }
    
    int tmp_result = 1;
    
    for (int i=2; i<=col_max; ++i) {
        int check = 0;
        for (int A : col) {
            if (A >= i) {
                check += 1;
                if (check >= i) {
                    tmp_result = i;
                    break;
                }
            }
            else {
                check = 0;
            }
        }
    }
    
    return tmp_result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> area;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int num;
    string data;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;    
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        area.push_back(one_line);
        
    }
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (area[i][j] == 0 && visited[i][j] == 0) {
                int tmp = check_square(area, visited, result, i, j);
                if (tmp > result) {
                    result = tmp;
                }
            }
        }
    }
    
    cout << result;

    return 0;
}
