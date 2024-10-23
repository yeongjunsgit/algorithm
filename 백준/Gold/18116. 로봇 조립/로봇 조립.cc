#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> parents;
unordered_map<int, int> childs_time;

int find_root(int a)
{
    if (parents[a] == a) {
        return a;
    }
    return parents[a] = find_root(parents[a]);
}

void union_root(int a, int b)
{
    int a_root = find_root(a);
    int b_root = find_root(b);
    
    if (a_root != b_root) {
        parents[a_root] = b_root;
        childs_time[b_root] += childs_time[a_root];
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    char command;
    int s, e;
    
    for (int i=0; i<N; ++i) {
        cin >> command;
        if (command == 'I') {
            cin >> s >> e;
            if (parents.find(s) == parents.end()) {
                parents[s] = s;
                childs_time[s] = 1;
            }
            if (parents.find(e) == parents.end()) {
                parents[e] = e;
                childs_time[e] = 1;
            }
            
            union_root(s, e);
            
        }
        else {
            cin >> s;
            if (childs_time.find(s) == childs_time.end()) {
                cout << 1 << "\n";
            }
            else {
                cout << childs_time[find_root(s)] << "\n";
            }
        }
    }
    
    return 0;
}
