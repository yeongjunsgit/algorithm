/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int N, M;

vector<int> parents;

// 구조체 선언
struct node_base {
    int dist;
    pair<int, int> conncect;
};

struct Compare {
    bool operator() (const node_base& a, const node_base& b) const {
        return a.dist < b.dist;
    }
};

// 트리의 최상단 부모 찾기
// 만약 루트 부모가 같다면 이미 연결되어있으므로 싸이클이 돈다는 뜻
int find_root(int x) {
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find_root(parents[x]);
}

// 루트 갱신
// 비교한 두개의 노드중 1개를 루트로 사용함으로 이어준다
void union_root(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    
    if (x != y) parents[y] = x;
}

// 가장 효율이 좋은 간선을 차례대로 찾아 두 노드를 이었을 때 싸이클이 되는지를 확인한다
// 만약, 싸이클이 생기지 않는다면, 해당 간선을 채택하고 두 노드를 이어준다.
// 만약, 두 노드간의 싸이클이 있다면 다음 간선으로 넘어간다.
int mst(vector<node_base>& graph) {
    int result = 0;
    int max_dist = 0;
    int get_node = 0;
    
    for (int i=0; i < M; ++i) {
        node_base now_node = graph[i];
        
        int node_1 = now_node.conncect.first;
        int node_2 = now_node.conncect.second;
        
        // 싸이클이 있다면 해당 간선 관계는 패스
        if (find_root(node_1) == find_root(node_2)) {
            continue;
        }
        
        result += now_node.dist;
        if (max_dist < now_node.dist) {
            max_dist = now_node.dist;
        }
        union_root(node_1, node_2);
        get_node += 1;
        
        if (get_node == N-1) {
            return result - max_dist;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    parents.resize(N + 1);
    
    vector<node_base> graph;
    for (int i=1; i<N+1; ++i) {
        parents[i] = i;
    }
    
    for (int i=0; i<M; ++i) {
        int one, two, dist;
        cin >> one >> two >> dist;
        
        graph.push_back({dist, {one, two}});
        
    }
    // 최고 효율의 간선을 순서대로 맞추기위해 정렬
    sort(graph.begin(), graph.end(), Compare());
    
    int result = mst(graph);
    
    cout << result;

    return 0;
}
