#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > call_time(12, vector<int>(12));
int best_time = 20000;


void dfs(int now, int depth, int now_time, vector<int>& visited)
{
    if (depth >= 11) {
        best_time = min(best_time, now_time);
        return;
    }
    
    if (depth % 2 == 0) {
        if (now % 2 == 0) {
            int next_time = now_time + call_time[now][now+1];
            if (best_time > next_time) {
                visited[now+1] = now_time;
                dfs(now+1, depth + 1, next_time, visited);
                visited[now+1] = 20000;
            }
        }
        else {
            int next_time = now_time + call_time[now][now-1];
            if (best_time > next_time) {
                visited[now-1] = now_time;
                dfs(now-1, depth + 1, next_time, visited);
                visited[now-1] = 20000;
            }
        }
    }
    else {
        for (int i=0; i<12; ++i) {
            if (visited[i] == 20000) {
                int next_time = now_time + call_time[now][i];
                if (best_time > next_time) {
                    visited[i] = next_time;
                    dfs(i, depth + 1, next_time, visited);
                    visited[i] = 20000;
                }
            }
        }
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<12; ++i) {
        for (int j=0; j<12; ++j) {
            cin >> call_time[i][j];
        }
    }
    
    for (int i=0; i<12; ++i) {
        vector<int> visited(11, 20000);
        visited[i] = 0;
        dfs(i, 0, 0, visited);
    }
    
    cout << best_time;

    return 0;
}
