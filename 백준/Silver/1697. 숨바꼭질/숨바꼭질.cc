#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    queue<pair<int, int> > que;
    que.push({N, 0});
    vector<int> visited(100001, 100002);
    visited[N] = 0;
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        if (now.second > visited[now.first]) {
            continue;
        }
        
        if (now.first + 1 && now.second + 1 < visited[now.first + 1]) {
            visited[now.first + 1] = now.second + 1;
            que.push({now.first + 1, now.second + 1});
        }
        
        if (now.first - 1 >= 0 && now.second + 1 < visited[now.first - 1]) {
            visited[now.first - 1] = now.second + 1;
            que.push({now.first - 1, now.second + 1});
        }
        
        if (now.first * 2 < 100001 && now.second + 1 < visited[now.first * 2]) {
            visited[now.first * 2] = now.second + 1;
            que.push({now.first * 2, now.second + 1});
        }
    }

    cout << visited[M];
    
    return 0;
}