#include <iostream>
#include <vector>

using namespace std;

int N;
vector<bool> used;
vector<int> pq;

void permu(int idx)
{
    if (idx == N) {
        for (int i=0; i<N; ++i) {
            cout << pq[i] << " ";
        }
        cout << "\n";
        
        return;
    }
    else {
        for (int i=1; i<=N; ++i) {
            if (used[i] == false) {
                used[i] = true;
                pq[idx] = i;
                permu(idx + 1);
                used[i] = false;
                pq[idx] = 0;
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
    used.resize(N + 1, false);
    pq.resize(N, 0);
    
    permu(0);

    return 0;
}
