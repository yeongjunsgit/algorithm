#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N;
    cin >> M;
    
    vector<vector<int>> left_graph(N+1);
    vector<vector<int>> right_graph(N+1);
    
    for (int i=0; i<M; ++i) {
        int one, two;
        cin >> one >> two;
        
        left_graph[two].push_back(one);
        right_graph[one].push_back(two);
    }
    
    for (int i=1; i<N+1; ++i) {
        int result = N-1;
        int visited[N+1]{0};
        
        queue<pair<int, int>> que;
        que.push({0, i});
        que.push({1, i});
        visited[i] = 1;
        
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            
            if (now.first == 0) {
                if (left_graph[now.second].size() != 0) {
                    for (int j=0; j<left_graph[now.second].size(); ++j) {
                        if (visited[left_graph[now.second][j]] == 0) {
                            visited[left_graph[now.second][j]] = 1;
                            result -= 1;
                            que.push({0, left_graph[now.second][j]});
                        }
                    }
                }
            }
            else if (now.first == 1) {
                if (right_graph[now.second].size() != 0) {
                    for (int j=0; j<right_graph[now.second].size(); ++j) {
                        if (visited[right_graph[now.second][j]] == 0) {
                            visited[right_graph[now.second][j]] = 1;
                            result -= 1;
                            que.push({1, right_graph[now.second][j]});
                        }
                    }
                }
            }
            
        }
        
        
        cout << result << "\n";
    }

    return 0;
}
