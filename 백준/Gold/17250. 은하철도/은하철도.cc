#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> my_space(100001, 0), parent(100001, 0);


// 현재 행성의 부모를 찾는 find_root
int find_root(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);
}


// 2개의 행성을 잇는 union_root
void union_root(int x, int y)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    // 이미 연결되어 있는 행성끼리 다시 연결된다면 그냥 현재 갯수를 출력해주기만 하면 된다.
    if (r_x == r_y) {
        cout << my_space[r_x] << "\n";
        return;
    }
    
    if (r_x > r_y) swap(r_x, r_y);
    
    parent[r_y] = r_x;
    my_space[r_x] += my_space[r_y];
    cout << my_space[r_x] << "\n";
    
    return;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
        parent[i] = i;
    }
    for (int i=1; i<=N; ++i) {
        cin >> my_space[i];
    }
    int s, e;
    for (int i=1; i<=M; ++i) {
        cin >> s >> e;
        union_root(s, e);
    }

    return 0;
}
