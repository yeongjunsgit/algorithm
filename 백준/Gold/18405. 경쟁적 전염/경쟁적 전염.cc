#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, K, S, X, Y;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<int>>& room, vector<vector<pair<int, int>>>& recent_virus) {
    for (int s=0; s<S; ++s) {
        for (int k=1; k<=K; ++k) {
            vector<pair<int, int>> now_virus = recent_virus[k];
            vector<pair<int, int>> next_virus;
            
            for (auto p : now_virus) {
                for (int f=0; f<4; ++f) {
                    int nx = p.first + direction[f].first;
                    int ny = p.second + direction[f].second;
                    
                    if (0 <= nx && nx < N && 0 <= ny && ny < N && room[nx][ny] == 0) {
                        room[nx][ny] = k;
                        next_virus.push_back({nx, ny});
                    }
                }
            }
            
            recent_virus[k] = next_virus;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    cin.ignore();
    
    vector<vector<int>> room;
    int num;
    string data;
    
    vector<vector<pair<int, int>>> recent_virus(K+1);
    
    for (int i=0; i<N; ++i) {
        int idx = 0;
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
            if (num != 0) {
                recent_virus[num].push_back({i, idx});
            }
            idx += 1;
        }
        
        room.push_back(one_line);
    }
    
    cin >> S >> X >> Y;
    
    bfs(room, recent_virus);
    
    cout << room[X-1][Y-1];
    
    return 0;
}
