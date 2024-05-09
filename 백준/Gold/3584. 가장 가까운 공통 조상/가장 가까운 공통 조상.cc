#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        int N;
        cin >> N;
        
        vector<int> graph(N+1, 0);
        
        for (int i=1; i<N; ++i) {
            int parent, child;
            cin >> parent >> child;
            graph[child] = parent;
        }
        
        int task1, task2;
        cin >> task1 >> task2;
        
        vector<int> task1_parents;
        task1_parents.push_back(task1);
        int now = task1;
        
        while (true) {
            if (graph[now] != 0) {
                int nows_parent = graph[now];
                now = nows_parent;
                task1_parents.push_back(nows_parent);
            }
            else {
                break;
            }
        }
        
        int letsgo = task2;
            
        while (true) {
            if (find(task1_parents.begin(), task1_parents.end(), letsgo) != task1_parents.end()) {
                cout << letsgo << "\n";
                break;
            }
            else {
                if (graph[letsgo] != 0) {
                    int check = graph[letsgo];
                    letsgo = check;
                }
                else {
                    break;
                }
            }
        }
        
    }

    return 0;
}
