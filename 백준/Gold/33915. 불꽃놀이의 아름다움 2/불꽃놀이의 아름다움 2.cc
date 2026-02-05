// 생각한 방법은 dfs를 하면서 현재 노드에 연결된 노드애 적힌 색깔들을 기록하고 기록되지 않은 가장 낮은 값을
// 현재 노드에 사용하려고 했다. 흠.. 시간 초과가 날수도 있을거같은데... 어떠려나...

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, max_color = 0;
vector<vector<int> > graph(200001);
vector<int> colors(200001, 0);


void dfs(int now)
{
    int now_color;
    unordered_set<int> near_color;    
    for (int a : graph[now]) {
        if (colors[a] != -1) near_color.insert(colors[a]);
    }
    
    for (int i=1; i<=N; ++i) {
        if (near_color.find(i) == near_color.end()) {
            now_color = i;
            break;
        }
    }
    
    colors[now] = now_color;
    max_color = max(max_color, now_color);
    
    for (int a : graph[now]) {
        if (colors[a] == 0) dfs(a);
    }
    
    return;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int s, e;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for (int i=1; i<=N; ++i) {
        if (colors[i] == 0) {
            dfs(i);
        }        
    }
    
    cout << max_color;

    return 0;
}
