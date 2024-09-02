#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

int S, E;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

void bfs(map<int, string>& visited, priority_queue<pair<int, int>, vector<pair<int, int> >, Compare>& que) {
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        if (visited[now.second].size() < now.first) {
            continue;
        }
        
        // "+" 연산
        if (now.second * 2 <= E) {
            if (visited.find(now.second * 2) == visited.end()) {
                visited[now.second * 2] = visited[now.second] + "+";
                que.push({now.first + 1, now.second * 2});
                
            }
            else {
                if (visited[now.second * 2].size() > visited[now.second].size() + 1) {
                    visited[now.second * 2] = visited[now.second] + "+";
                    que.push({now.first + 1, now.second * 2});
                }
                else if (visited[now.second * 2].size() == visited[now.second].size() + 1) {
                    if (visited[now.second * 2] > visited[now.second] + "+") {
                        visited[now.second * 2] = visited[now.second] + "+";
                    }
                }
            }
        }
        
        // "*" 연산
        if (pow(now.second, 2) <= E) {
            if (visited.find(pow(now.second, 2)) == visited.end()) {
                visited[pow(now.second, 2)] = visited[now.second] + "*";
                que.push({now.first + 1, pow(now.second, 2)});
                
            }
            else {
                if (visited[pow(now.second, 2)].size() > visited[now.second].size() + 1) {
                    visited[pow(now.second, 2)] = visited[now.second] + "*";
                    que.push({now.first + 1, pow(now.second, 2)});
                }
                else if (visited[pow(now.second, 2)].size() == visited[now.second].size() + 1) {
                    if (visited[pow(now.second, 2)] > visited[now.second] + "*") {
                        visited[pow(now.second, 2)] = visited[now.second] + "*";
                    }
                }
            }
        }
    }
    
    return;
}


int main()
{
    cin >> S >> E;
    
    string result = "";
    
    if (S == E) {
        result = "0";
    }
    else if (E == 1) {
        result = "/";
    }
    
    else if (E == 0) {
        result = "-";
    }
    
    else {
        map<int, string> visited;
        priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> que;
        que.push({0, S});
        visited[S] = "";
        
        bfs(visited, que);
        
        que.push({1, 1});
        visited[1] = "/";
        
        bfs(visited, que);
        
        if (visited.find(E) == visited.end()) {
            result = "-1";
        }
        
        else {
            result = visited[E];
        }
    }
    
    cout << result;

    return 0;
}
