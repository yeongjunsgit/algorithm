#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parents;

int find_root(int x)
{
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find_root(parents[x]);
}

bool union_root(int x, int y)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    
    if (r_x == r_y) {
        return true;
    }
    
    if (r_x > r_y) {
        swap(r_x, r_y);
    }
    
    parents[r_y] = r_x;
    
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    parents.resize(N, 0);
    
    for (int i=0; i<N; ++i) {
        parents[i] = i;
    }
    
    int s, e;
    bool is_over = false;
    
    for (int i=1; i<=M; ++i) {
        cin >> s >> e;
        
        bool is_cycle = union_root(s, e);
        
        if (is_cycle == true) {
            cout << i;
            is_over = true;
            break;
        }
    }
    
    if (is_over == false) {
        cout << 0;
    }

    return 0;
}
