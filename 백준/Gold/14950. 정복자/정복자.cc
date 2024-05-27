#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N, M, T, moved;

vector<int> parents;

struct info {
    int dist;
    pair<int, int> connect;
};

struct Compare {
    bool operator() (const info& a, const info& b) {
        return a.dist < b.dist;
    }
};

// 트리의 최상단 부모 찾기
int find_root(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find_root(parents[x]);
}

// 루트 갱신
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    
    if (x != y) { 
        parents[y] = x;
    }
}

int mst(vector<info>& graph) {
    int result = 0;
    
    for (int i=0; i<M; ++i) {
        info now_info = graph[i];
        
        int node_1 = now_info.connect.first;
        int node_2 = now_info.connect.second;
        
        if (find_root(node_1) == find_root(node_2)) {
            continue;
        }
        
        result += now_info.dist + moved;
        moved += T;
        union_root(node_1, node_2);
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 도시의 개수, M = 도로의 개수, T = 추가비용
    cin >> N >> M >> T;
    
    vector<info> graph;
    
    for (int i=0; i<M; ++i) {
        int s, e, dist;
        cin >> s >> e >> dist;
        
        graph.push_back({dist, {s, e}});

    }
    
    sort(graph.begin(), graph.end(), Compare());
    
    for (int i=0; i<N+1; ++i) {
        parents.push_back(i);
    }
    
    int result = mst(graph);
    
    cout << result;
    

    return 0;
}
