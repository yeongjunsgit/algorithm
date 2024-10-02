#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N, K, S, E;
vector<vector<int> > graph;
vector<string> my_code;

struct my_node {
    int dist;
    int loca;
    string route;
};

struct Compare {
    bool operator()(const my_node& a, const my_node& b){
        return a.dist < b.dist; 
    }
};

void make_line()
{
    for (int i=1; i<=N; ++i) {
        for (int j=i; j<=N; ++j) {
            int cnt = 0;
            for (int k=0; k<K; ++k) {
                if (my_code[i][k] != my_code[j][k]) {
                    cnt++;
                }
                graph[i][j] = cnt;
                graph[j][i] = cnt;
            }
        }
    }
    
    return;
}

void find_root()
{
    priority_queue<my_node, vector<my_node>, Compare> que;
    vector<int> visited(N+1, 2001);
    que.push({0, S, " "});
    int E_dist = 2001;
    string E_route = " ";
    visited[S] = 0;

    while (!que.empty()) {
        my_node now = que.top();
        que.pop();
        if (now.dist > E_dist) {
            continue;
        }
        
        for (int i=1; i<=N; ++i) {
            if (i != S) {
                if (graph[now.loca][i] == 1) {
                    if (E_dist > now.dist + 1 && visited[i] > now.dist + 1) {
                        que.push({now.dist + 1, i, now.route + " " + to_string(now.loca)});
                        visited[i] = now.dist + 1;
                        
                        if (i == E && now.dist + 1 < E_dist) {
                            E_dist = now.dist + 2;
                            E_route = now.route + " " + to_string(now.loca) + " " + to_string(E);
                        }
                    }
                }
            }
        }
    }
    
    if (E_route == " ") {
        cout << -1;
    }
    else {
        istringstream iss(E_route);
        string a;
        while (iss >> a) {
            cout << a << " ";
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    
    graph.resize(N+1, vector<int>(N+1, 0));
    my_code.resize(N+1, " ");
    string data;
    
    for (int i=1; i<=N; ++i) {
        cin >> data;
        my_code[i] = data;
    }
    
    cin >> S >> E;
    
    make_line();
    find_root();

    return 0;
}
