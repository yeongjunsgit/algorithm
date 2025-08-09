#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

unordered_map<int, vector<int> > graph;
vector<int> visited(1000001, 0);
int start_point = -1;

int dfs(int start, int color)
{
    deque<int> que;
    que.push_back(start);
    visited[start] = color;
    bool is_multi = false;
    while (!que.empty()) {
        int now = que.back();
        
        // 아무곳도 가지 못한다면 막대 모양 그래프의 번호를 반환
        if (graph[now].size() == 0) {
            // cout << "막대그래프 나가욧~!\n";
            return 2;
        }
        // 한 노드에서 2개의 간선이 나간다면 이는 8자 모양이다
        else if (graph[now].size() == 2) {
            is_multi = true;
            // cout << now << " " << graph[now].size() << "\n";
        }
        
        for (int a : graph[now]) {
            // cout << "현재 나는 " << now << "이고 나로부터 나가는 간선인 "<< a << "를 보고있다.\n";
            // 이동한 곳의 색깔이 현재 색과 동일하다면 이는 싸이클이므로 도넛 모양 그래프의 번호를 반환
            if (visited[a] == color) {
                // cout << a << " " << color << " " << is_multi << "\n";
                if (is_multi) return 3;
                else return 1;
            }
            // 이전에 검토했던 그래프에 참여하므로 0을 반환
            else if (visited[a] != 0 && visited[a] < color) {
                // cout << a << "는 봤던곳이네.. 런!\n";
                return 0;
            }
            // 현재 이동한적없는 곳을 que에 push_back하고 방문처리
            else if (visited[a] == 0) {
                // cout << "현재 나는 " << now << "이고 "<< a << "를 que에 넣었다.\n";
                visited[a] = color;
                que.push_back(a);
            }
        }
    }
}


vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    unordered_map<int, int> in_out;
    
    for (auto a : edges) {
        graph[a[0]].push_back(a[1]);
        in_out[a[0]] += 1; in_out[a[1]] -= 1;
    }
    
    for (auto a : in_out) {
        if (a.second >= 2) {
            start_point = a.first;
            answer[0] = start_point;
            break;
        }
    }
    
    int color = 0;
    for (auto a : in_out) {
        if (visited[a.first] == 0 && a.first != start_point) {
            color++;
            int check = dfs(a.first, color);
            if (check) answer[check]++;
        }
    }
    
    return answer;
}