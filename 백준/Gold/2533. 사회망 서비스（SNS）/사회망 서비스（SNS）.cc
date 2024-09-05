#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int cnt;

void dfs(vector<vector<int> >& graph, vector<bool>& celebrity, int now, int before) {
    if (graph[now].size() == 1 && graph[now][0] == before) {
        if (celebrity[before] == false) {
            celebrity[before] = true;
            cnt++;
        }
        return;
    }
    
    else {
        for (int a : graph[now]) {
            if (a != before) {
                dfs(graph, celebrity, a, now);
            }
        }
        
        if (celebrity[now] != true) {
            bool is_over = false;
            for (int a : graph[now]) {
                if (a != before) {
                    if (celebrity[a] == false) {
                        celebrity[now] = true;
                        cnt++;
                        is_over = true;
                        break;
                    }
                }
            }
            
            if (is_over == false && celebrity[before] == false && before != 0) {
                celebrity[before] = true;
                cnt++;
            }
        }
        return;
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    int s, e;
    vector<vector<int> > graph(N+1);
    vector<bool> celebrity(N+1);
    
    for (int i=1; i<N; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    dfs(graph, celebrity, 1, 0);
    
    cout << cnt;

    return 0;
}
