/*
현재 자신의 키가 정확히 몇번째인지 알 수 있으려면 모든 노드와 연결이
되어있어야 알 수 있다.
하지만 양방향으로 보면 알 수 없다.
나보다 작은것과 큰 것을 따로 확인해보고 다 갖춰지는지 보자
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int now, int& checked, vector<bool>& visited, vector<vector<int>>& now_tree) {
    if (now_tree[now].size() != 0) {
        for (int i=0; i<now_tree[now].size(); ++i) {
            if (visited[now_tree[now][i]] == false) {
                visited[now_tree[now][i]] = true;
                checked += 1;
                dfs(now_tree[now][i], checked, visited, now_tree);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> small_tree(N+1);
    vector<vector<int>> big_tree(N+1);
    
    int result = 0;
    
    for (int i=0; i<M; ++i) {
        int small, big;
        cin >> small >> big;
        
        big_tree[small].push_back(big);
        small_tree[big].push_back(small);
    }
    
    for (int i=1; i<=N; ++i) {
        int checked = 1;
        vector<bool> visited(N+1, false);
        visited[i] = true;
        
        dfs(i, checked, visited, big_tree);
        dfs(i, checked, visited, small_tree);
        
        if (checked == N) {
            result += 1;
        }
    }

    cout << result;

    return 0;
}
