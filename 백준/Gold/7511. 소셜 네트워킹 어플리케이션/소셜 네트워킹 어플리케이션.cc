#include <iostream>
#include <vector>

using namespace std;

int T, N, K, M;
vector<int> my_root(100000, 0);

int find_root(int x) {
    if (my_root[x] == x) {
        return x;
    }
    return my_root[x] = find_root(my_root[x]);
}

void union_root(int x, int y) {
    int xr = find_root(x);
    int yr = find_root(y);
    
    if (xr != yr) {
        my_root[yr] = xr;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> K;

        
        for (int i=0; i<N; ++i) {
            my_root[i] = i;
        }
        
        vector<pair<int, int>> friends;
        int s, e;
        
        for (int i=0; i<K; ++i) {
            cin >> s >> e;
            union_root(s, e);

        }
        
        cin >> M;

        cout << "Scenario " << t+1 << ':' << "\n";
        for (int i=0; i<M; ++i) {
            cin >> s >> e;
            int root_1 = find_root(s);
            int root_2 = find_root(e);
            
            
            if (root_1 == root_2) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        
        cout << "\n";
    }

    return 0;
}
