#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, S, D;

int dfs(vector<vector<int>>& graph, vector<int>& visited, int& result, int now, int before) {
    // 현재 위치에서 연결된 모든 노드를 판단한다.
    for (auto A : graph[now]) {
        // 이동한 노드가 이전 노드가 아니라면
        if (A != before) {
            // 현재 저장된 아래 노드의 깊이를 dfs를 돈 길이와 비교하여 최대값을 저장한다.
            int tmp = max(visited[now], dfs(graph, visited, result, A, now) + 1);
            visited[now] = tmp;
        }
    }
    // 만약 현재 위치에서 아래에 있는 노드의 깊이가 주어진 힘보다 크다면 (시작위치가 아니라면)
    // 해당 위치는 이동을 해야하는 노드임으로 result를 1 추가한다.
    if (visited[now] >= D && now != S) {
        result += 1;
    }
    
    // 현재 위치의 값을 반환
    return visited[now];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> S >> D;
    
    vector<vector<int>> graph(N+1);

    
    for (int i=0; i<N-1; ++i) {
        int one, two;
        cin >> one >> two;
        graph[one].push_back(two);
        graph[two].push_back(one);
    }
    
    
    vector<int> visited(N+1, 0);

    int result = 0;
    
    dfs(graph, visited, result, S, -1);
    
    cout << result * 2;

    return 0;
}
