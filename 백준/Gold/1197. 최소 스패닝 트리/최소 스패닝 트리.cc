#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, E;
vector<int> parents;

struct my_node {
    int start;
    int end;
    int dist;
};

struct Compare {
    bool operator()(const my_node& a, const my_node& b) {
        return a.dist > b.dist;
    }  
};

priority_queue<my_node, vector<my_node>, Compare> graph;

int find_root(int now)
{
    if (parents[now] == now) {
        return now;
    }
    return parents[now] = find_root(parents[now]);
}


void union_root(int a, int b)
{
    int r_a = find_root(a);
    int r_b = find_root(b);
    
    if (r_a == r_b) {
        return;
    }
    
    if (r_a > r_b) {
        swap(r_a, r_b);
    }
    
    parents[r_b] = r_a;
    
    return;
}


void spaning_tree_check()
{
    int stack_dist = 0;
    
    while (!graph.empty()) {
        my_node now = graph.top();
        graph.pop();
        
        int root_a = find_root(now.start);
        int root_b = find_root(now.end);
        
        if (root_a == root_b) {
            continue;
        }
        
        stack_dist += now.dist;
        
        union_root(now.start, now.end);
        
    }
    
    cout << stack_dist;
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> E;
    int s, e, dist;
    
    parents.resize(N+1);
    
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
    }
    
    for (int i=0; i<E; ++i) {
        cin >> s >> e >> dist;
        
        graph.push({s, e, dist});
        
    }
    
    spaning_tree_check();

    return 0;
}
