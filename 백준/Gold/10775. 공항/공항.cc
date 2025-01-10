#include <iostream>
#include <vector>

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

void union_root(int x, int y)
{
    int rx = find_root(x);
    int ry = find_root(y);
    
    if (rx == ry) {
        return;
    }
    
    parents[ry] = rx;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    parents.resize(N+1, 0);
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
    }
    
    int num;
    int result = 0;
    for (int i=0; i<M; ++i) {
        cin >> num;
        if (parents[num] == num) {
            result++;
            union_root(num-1, num);
        }
        else {
            int target = find_root(num);
            if (target != 0) {
                result++;
                union_root(target - 1, target);
            }
            else {
                break;
            }
        }
    }
    
    cout << result;

    return 0;
}
