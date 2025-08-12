#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<char> > graph(52, vector<char>(52, '.'));
vector<vector<int> > visited(52, vector<int>(52, -1));
unordered_map<char, int> cnt_container;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


void bfs(vector<vector<int> >& vd)
{
    vector<vector<int> > tmp(52, vector<int>(52, -1));
    queue<pll> que;
    que.push({0, 0});
    
    while (!que.empty()) {
        pll now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + directions[i].first;
            int ny = now.second + directions[i].second;

            if (0 <= nx && nx <= N+1 && 0 <= ny && ny <= M+1 && graph[nx][ny] == '.' && tmp[nx][ny] == -1) {
                que.push({nx, ny});
                tmp[nx][ny] = 1;
                if (vd[nx][ny] == -1) {
                    vd[nx][ny] = 1;
                }
            }
        }
    }
    
    return;
    
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    N = storage.size();
    M = storage[0].size();
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            graph[i][j] = storage[i-1][j-1];
            cnt_container[graph[i][j]]++;
        }
    }
    for (int i=0; i<=N+1; ++i) {
        for (int j=0; j<=M+1; ++j) {
            if (i == 0 || i == N+1 || j == 0 || j == M+1) {
                // cout << "{" << i << ", " << j << "}\n";
                visited[i][j] = 1;
            }
        }
    }
    int result = N * M;
    
    for (string s : requests) {
        bfs(visited);
        
        // for (int i=0; i<=N+1; ++i) {
        //     for (int j=0; j<=M+1; ++j) {
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        char target = s[0];
        if (s.size() == 2) {
            if (cnt_container.find(target) != cnt_container.end() && cnt_container[target] > 0) {
                for (int i=1; i<=N; ++i) {
                    for (int j=1; j<=M; ++j) {
                        if (graph[i][j] == target) {
                            result--;
                            cnt_container[target]--;
                            graph[i][j] = '.';
                        }
                    }
                }
            }
        }
        else {
            for (int i=1; i<=N; ++i) {
                for (int j=1; j<=M; ++j) {
                    if (graph[i][j] == target) {
                        for (int k=0; k<4; ++k) {
                            int nx = i + directions[k].first;
                            int ny = j + directions[k].second;

                            if (0 <= nx && nx <= N+1 && 0 <= ny && ny <= M+1 && visited[nx][ny] == 1) {
                                graph[i][j] = '.';
                                result--;
                                cnt_container[target]--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    answer = result;
    
    return answer;
}
