#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

void check_route(vector<vector<int>>& graph, int start, int end, int limit) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    vector<int> visited(N+1, 1000000001);
    que.push({0, start});
    visited[start] = 0;
    
    while(!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        
        for (int i=0; i<N; ++i) {
            if (i == end) {
                if (now.first + graph[now.second][i] <= limit) {
                    cout << "Enjoy other party" << "\n";
                    return;
                }
            }
            
            else if (i != now.second) {
                if (now.first + graph[now.second][i] <= limit) {
                    if (visited[i] > now.first + graph[now.second][i]) {
                        visited[i] = now.first + graph[now.second][i];
                        que.push({now.first + graph[now.second][i], i});
                    }
                }
            }
        }
    }
    
    cout << "Stay here" << "\n";
    return;
    
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<int>> graph;
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        graph.push_back(one_line);
    }
    
    int start, end, limit;
    
    for (int i=0; i<M; ++i) {
        cin >> start >> end >> limit;
        if (start != end) {
            check_route(graph, start - 1, end - 1, limit);
        }
        else {
            cout << "Enjoy other party" << "\n";
        }
    }

    return 0;
}
