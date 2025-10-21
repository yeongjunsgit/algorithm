#include <iostream>
#include <vector>
#include <deque>

#define pll pair<int, int>

using namespace std;

int N, R, s, e, dist, giga_node, giga_length = 0, longest_leaf = 0;
vector<vector<pll> > graph(200001);
vector<int> visited(200001, 0);

void find_giga()
{
    int now_node = R, before = -1; 
    while (true) {
        visited[now_node] = 1;
        if (graph[now_node].size() > 2 || (graph[now_node].size() >= 2 && now_node == R) || (graph[now_node].size() == 1 && now_node != R) ) {
            giga_node = now_node;
            break;
        }
        for (auto p : graph[now_node]) {
            if (p.first != before) {
                before = now_node;
                now_node = p.first;
                giga_length += p.second;
                break;
            }
        }
    }

    return;
}


void find_leaf(int now, int now_length)
{
    longest_leaf = max(longest_leaf, now_length);
    for (auto p : graph[now]) {
        if (visited[p.first] == 0) {
            visited[p.first] = 1;
            find_leaf(p.first, now_length + p.second);
        }
    }
    
    return;

}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R;
    
    for (int i=0; i<N-1; ++i) {
        cin >> s >> e >> dist;
        graph[s].push_back({e, dist});
        graph[e].push_back({s, dist});
    }
    if (N > 1) {
        find_giga();
        int now_length = 0;
        find_leaf(giga_node, 0);
    }
    
    cout << giga_length << " " << longest_leaf;
    

    return 0;
}
