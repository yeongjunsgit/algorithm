#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> parents(100001, 0), armys(100001, 0);

int find_root(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = find_root(parents[x]);
}


void union_root(int x, int y, int command)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    
    if (r_x == -1 || r_y == -1 || r_x == r_y) return;
    if (r_x > r_y) swap(r_x, r_y);
    
    if (command == 1) {
        parents[r_y] = r_x;
        armys[r_x] += armys[r_y];
        armys[r_y] = 0;
    }
    else {
        if (armys[r_x] > armys[r_y]) {
            parents[r_y] = r_x;
            armys[r_x] -= armys[r_y];
            armys[r_y] = 0;
        }
        else if (armys[r_x] < armys[r_y]) {
            parents[r_x] = r_y;
            armys[r_y] -= armys[r_x];
            armys[r_x] = 0;
        }
        else {
            parents[r_x] = -1;
            parents[r_y] = -1;
            armys[r_x] = 0;
            armys[r_y] = 0;
        }
    }
    
    return;
}


void get_result()
{
    int cnt = 0;
    for (int i=1; i<=N; ++i) {
        if (parents[i] == i) cnt++;
    }
    cout << cnt << "\n";
    sort(armys.begin(), armys.end(), less<int>());
    
    for (int a : armys) {
        if (a > 0) {
            cout << a << " ";
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=1; i<=N; ++i) {
        cin >> armys[i];
    }
    
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
    }
    
    int command, s, e;
    for (int i=0; i<M; ++i) {
        cin >> command >> s >> e;
        union_root(s, e, command);
    }
    
    get_result();

    return 0;
}
