#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<pair<int, int>> direction = {{0, 1}, {1, 0}};

int little_calculator(char oper, int one, char two) {
    int result;
    // cout << one  << " " << oper << " " << two - '0' << "\n";
    if (oper == '+') {
        result = one + (two - '0');
    }
    else if (oper == '-') {
        result = one - (two - '0');
    }
    else if (oper == '*') {
        result = one * (two - '0');
    }
    // cout << result << "\n";
    return result;
}

void bfs(vector<vector<char>>& school_road, vector<vector<int>>& max_visited, vector<vector<int>>& min_visited) {
    max_visited[0][0] = school_road[0][0] - '0';
    min_visited[0][0] = school_road[0][0] - '0';
    // cout << max_visited[0][0] << " " << min_visited[0][0] << "\n";
    
    for (int q=0; q<N; ++q) {
        for (int p=0; p<N; ++p){
            if (school_road[q][p] - '0' >= 0) {
                for (int i=0; i<2; ++i) {
                    int nx = q + direction[i].first;
                    int ny = p + direction[i].second;
                    
                    if (nx < N && ny < N) {
                        for (int j=0; j<2; ++j) {
                            int nnx = nx + direction[j].first;
                            int nny = ny + direction[j].second;
                            
                            if (nnx < N && nny < N) {
                                int max_tmp = little_calculator(school_road[nx][ny], max_visited[q][p], school_road[nnx][nny]);
                                int min_tmp = little_calculator(school_road[nx][ny], min_visited[q][p], school_road[nnx][nny]);
                                
                                if (max_visited[nnx][nny] < max_tmp) {
                                    max_visited[nnx][nny] = max_tmp;
                                }
                                if (min_visited[nnx][nny] > min_tmp) {
                                    min_visited[nnx][nny] = min_tmp;
                                }
                            }
                        }
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
    
    vector<vector<char>> school_road;
    vector<vector<int>> max_visited(N, vector<int>(N, -3126));
    vector<vector<int>> min_visited(N, vector<int>(N, 3126));
    
    char one_block;
    for (int i=0; i<N; ++i) {
        vector<char> one_line;
        for (int j=0; j<N; ++j) {
            cin >> one_block;
            one_line.push_back(one_block);
        }
        school_road.push_back(one_line);
    }
    
    bfs(school_road, max_visited, min_visited);
    
    cout << max_visited[N-1][N-1] << " " << min_visited[N-1][N-1];

    return 0;
}
