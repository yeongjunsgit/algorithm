/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;

vector<int> parents;

struct node_base {
    int dist;
    pair<int, int> connection;
};

struct Compare {
    bool operator()(const node_base& a, const node_base& b) {
        return a.dist < b.dist;
    }
};

int find_root(int x) {
    // 현재 자신이 최상위 루트라면 본인을 반환 
    if (parents[x] == x) {
        return x;
    }
    // 현재 노드의 최상위 루트를 찾아 반환
    return parents[x] = find_root(parents[x]);
}

void union_root(int x, int y) {
    // 두개의 루트를 찾는다
    x = find_root(x);
    y = find_root(y);
    
    // 만약 두개의 루트가 다르다면 x를 y의 자식으로 두어 루트를 합친다.
    if (x != y) {
        parents[x] = y;
    }
}

long long mst(vector<node_base> graph) {
    // 현재 진행한 최적 경로의 가중치를 담을 best_way
    long long best_way = 0;
    // 진행한 연결도시의 개수를 담을 citys
    int citys = 0;
    
    // 그래프를 순회하여
    for (int i=0; i<M; ++i) {
        // 가중치가 낮은 순서대로 값을 꺼냄
        node_base now_node = graph[i];
        
        // 해당 연결관계의 노드 두개를 기록
        int node_1 = now_node.connection.first;
        int node_2 = now_node.connection.second;
        
        // 두개의 최상 루트가 같다면 다음으로 넘긴다.
        if (find_root(node_1) == find_root(node_2)) {
            continue;
        }
        
        // 현재 가중치 값을 더한다.
        best_way += now_node.dist;
        
        // 연결되지 않은 두개의 노드를 연결한다
        union_root(node_1, node_2);
        // 연결도시의 개수를 1개 올린다.
        citys += 1;
        
        // 만약 연결도시의 개수가 N-1 (처음 연결에는 2개 이후로는 1개씩 이기 때문) 라면 현재 저장된 가중치 값을 반환
        if (citys == N-1) {
            return best_way;
        }
    }
    // 끝날때까지 반환 못했다면 -1 반환환
    return -1;
    
}

int main()
{
    cin >> N >> M;
    
    vector<node_base> graph;
    
    int s, e, dist;
    
    long long all_cost = 0;
    
    parents.resize(N+1);
    
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
    }
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        
        graph.push_back({dist, {s, e}});
        
        all_cost += dist;
    }
    
    sort(graph.begin(), graph.end(), Compare());
    
    vector<int> visited(N+1, 0);
    long long result = mst(graph);
    
    if (result == -1) {
        cout << "-1";
    }
    else {
        cout << all_cost - result;
    }

    return 0;
}
