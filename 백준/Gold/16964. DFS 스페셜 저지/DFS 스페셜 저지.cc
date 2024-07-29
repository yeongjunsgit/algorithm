#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;

int result = 0;

void dfs(vector<unordered_map<int, int>>& graph, vector<int>& dfs_route, int& idx, vector<int>& stacker) {
    while (stacker.size() != 1 && idx != N) {
        if (graph[stacker.back()].find(dfs_route[idx]) != graph[stacker.back()].end() && dfs_route[idx] != stacker[stacker.size()-2]) {
            stacker.push_back(dfs_route[idx]);
            idx += 1;
        }
        else {
            stacker.pop_back();
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    vector<unordered_map<int, int>> graph(N+1);
    int s, e;
    
    for (int i=0; i<N-1; ++i) {
        cin >> s >> e;
        graph[s][e] = 1;
        graph[e][s] = 1;
    }
    
    cin.ignore();
    
    vector<int> dfs_route;
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    
    while (iss >> num) {
        dfs_route.push_back(num);
    }
    
    int idx = 1;
    
    vector<int> stacker = {0, 1};
    
    dfs(graph, dfs_route, idx, stacker);

    if (idx == N) {
        result = 1;
    }

    cout << result;

    return 0;
}
