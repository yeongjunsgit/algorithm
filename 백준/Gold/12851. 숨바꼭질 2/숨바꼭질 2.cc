#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main()
{
    int N, K;
    
    cin >> N >> K;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    vector<pair<int, int>> visited(1000001, {999999, 0});
    
    visited[N] = {0, 1};
    que.push({0, N});
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        
        if (now.first > visited[K].first) {
            continue;
        }
        
        if (visited[now.second + 1].first > now.first + 1 && now.second + 1 >= 0 && now.second + 1 < 100001) {
            if (visited[now.second + 1].second == 0) {
                que.push({now.first + 1, now.second + 1});
                visited[now.second + 1].second = visited[now.second].second;
                visited[now.second + 1].first = now.first + 1;
            }
            else {
                visited[now.second + 1].second = visited[now.second].second;
                visited[now.second + 1].first = now.first + 1;
            }
        }
        else if (visited[now.second + 1].first == now.first + 1 && now.second + 1 >= 0 && now.second + 1 < 100001) {
            visited[now.second + 1].second += visited[now.second].second;
        }
        
        if (visited[now.second - 1].first > now.first + 1 && now.second - 1 >= 0 && now.second - 1 < 100001) {
            if (visited[now.second - 1].second == 0) {
                que.push({now.first + 1, now.second - 1});
                visited[now.second - 1].second = visited[now.second].second;
                visited[now.second - 1].first = now.first + 1;
            }
            else {
                visited[now.second - 1].second = visited[now.second].second;
                visited[now.second - 1].first = now.first + 1;
            }
        }
        else if (visited[now.second - 1].first == now.first + 1 && now.second - 1 >= 0 && now.second - 1 < 100001) {
            visited[now.second - 1].second += visited[now.second].second;
        }
        
        if (visited[now.second * 2].first > now.first + 1 && now.second * 2 >= 0 && now.second * 2 < 100001) {
            if (visited[now.second * 2].second == 0) {
                que.push({now.first + 1, now.second * 2});
                visited[now.second * 2].second = visited[now.second].second;
                visited[now.second * 2].first = now.first + 1;
            }
            else {
                visited[now.second * 2].second = visited[now.second].second;
                visited[now.second * 2].first = now.first + 1;
            }
        }
        else if (visited[now.second * 2].first == now.first + 1 && now.second * 2 >= 0 && now.second * 2 < 100001) {
            visited[now.second * 2].second += visited[now.second].second;
        }
    }
    
    cout << visited[K].first << "\n" << visited[K].second;

    return 0;
}
