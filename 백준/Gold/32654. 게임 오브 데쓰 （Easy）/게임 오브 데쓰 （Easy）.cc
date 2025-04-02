#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
vector<vector<int> > graph;

int get_num()
{
    int K = 0;
    set<int> now_loca;
    now_loca.insert(1);
    while (K < 100) {
        if (K >= 10) {
            if (now_loca.find(1) == now_loca.end()) return K;
        }
        set<int> next_loca;
        for (int a : now_loca) {
            for (int b : graph[a]) {
                next_loca.insert(b);
            }
        }
        
        now_loca = next_loca;
        K++;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    graph.resize(N+1);
    int l, r;
    
    for (int i=1; i<=N; i++) {
        cin >> l >> r;
        graph[i].push_back(l); graph[i].push_back(r);
    }
    
    cout << get_num();

    return 0;
}
