#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct explorer {
    bool is_out;
    int movement;
    int x;
    int y;
};

struct Compare {
    bool operator()(const explorer& a, const explorer& b) {
        if (a.is_out != b.is_out) {
            return a.is_out > b.is_out;
        }
        
        return a.movement > b.movement;
    }
};

void bfs(vector<vector<int>>& ocean, vector<vector<int>>& visited, int& result, int island_num, int x, int y) {
    priority_queue<explorer, vector<explorer>, Compare> que;
    que.push({false, 0, x, y});
    visited[x][y] = island_num;
    
    while (!que.empty()) {
        explorer now = que.top();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.x + direction[i].first;
            int ny = now.y + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (visited[nx][ny] == 0 && ocean[nx][ny] == 1) {
                    if (now.is_out == false) {
                        visited[nx][ny] = island_num;
                        que.push({now.is_out, now.movement, nx, ny});
                    }
                    else {
                        if (visited[nx][ny] != island_num) {
                            if (result > now.movement) {
                                result = now.movement;
                            }
                        }
                    }
                }
                else if (visited[nx][ny] != island_num && ocean[nx][ny] == 0) {
                    visited[nx][ny] = island_num;
                    if (now.movement + 1 < result) {
                        que.push({true, now.movement + 1, nx, ny});
                    }
                }
            }
        }
        
    }

    return;
}

int main()
{
    cin >> N;
    
    cin.ignore();
    
    vector<vector<int>> ocean;
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        ocean.push_back(one_line);
    }
    
    vector<vector<int>> visited(N, vector<int>(N, 0));
    int island_num = 1;
    int result = 99999999;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (ocean[i][j] == 1 && visited[i][j] == 0) {
                bfs(ocean, visited, result, island_num, i, j);
                island_num += 1;
            }
        }
    }
    
    cout << result;

    return 0;
}
