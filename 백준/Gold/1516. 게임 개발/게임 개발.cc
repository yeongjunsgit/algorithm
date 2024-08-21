#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N;

void bfs(vector<int>& build_time, vector<int>& total_time, vector<vector<int>>& before_build, vector<vector<int>>& connection_build, vector<bool>& is_build, queue<int>& que) {
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        
        for (int i : connection_build[now]) {
            if (is_build[i] == false) {
                
                bool is_over = true;
                for (int j : before_build[i]) {
                    if (is_build[j] == false) {
                        is_over = false;
                        break;
                    }
                    else {
                        total_time[i] = max(total_time[i], total_time[j]);
                    }
                }
                
                if (is_over == true) {
                    is_build[i] = true;
                    total_time[i] += build_time[i];
                    que.push(i);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    vector<int> build_time(N, 0);
    vector<int> total_time(N, 0);
    vector<vector<int>> before_build(N);
    vector<vector<int>> connection_build(N);
    vector<bool> is_build(N, false);
    queue<int> que;
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        bool cost_check = false;
        
        while (iss >> num) {
            if (cost_check == false) {
                cost_check = true;
                build_time[i] = num;
            }
            else {
                if (num == -1) {
                    break;
                }
                else {
                    before_build[i].push_back(num-1);
                    connection_build[i].push_back(num-1);
                    connection_build[num-1].push_back(i);
                }
            }
        }
        
        if (before_build[i].size() == 0) {
            total_time[i] = build_time[i];
            is_build[i] = true;
            que.push(i);
        }
    }
    
    bfs(build_time, total_time, before_build, connection_build, is_build, que);
    
    for (int i=0; i<N; ++i) {
        cout << total_time[i] << "\n";
    }

    return 0;
}
