#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, int& result, vector<int>& passed, int start) {
    if (passed.size() == 5) {
        result = 1;
        return;
    }
    
    if (graph[start].size() != 0) {
        for (int g=0; g<graph[start].size(); ++g) {
            if (find(passed.begin(), passed.end(), graph[start][g]) == passed.end()) {
                passed.push_back(graph[start][g]);
                dfs(graph, result, passed, graph[start][g]);
                passed.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N);
    int result = 0;
    vector<int> visited(N, 0);
    
    for (int m=0; m<M; ++m) {
        int one, two;
        cin >> one >> two;
        
        graph[one].push_back(two);
        graph[two].push_back(one);
    }
    
    for (int i=0; i<N; ++i) {
        if (result != 1) {
            vector<int> passed;
            passed.push_back(i);
            dfs(graph, result, passed, i);
        }
        else {
            break;
        }
    }
    
    cout << result;

    return 0;
}
