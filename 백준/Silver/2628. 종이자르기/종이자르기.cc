#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // N = 가로길이, M = 세로길이
    int N, M, K, kind, num, best_size = 0;
    cin >> N >> M >> K;
    
    vector<int> N_cut = {0}, M_cut = {0};
    for (int i=0; i<K; ++i) {
        cin >> kind >> num;
        if (kind == 0) M_cut.push_back(num);
        else N_cut.push_back(num);
    }
    N_cut.push_back(N); M_cut.push_back(M);
    int N_size = N_cut.size(), M_size = M_cut.size();
    sort(N_cut.begin(), N_cut.end(), less());
    sort(M_cut.begin(), M_cut.end(), less());
    for (int i=1; i<N_size; ++i) {
        for (int j=1; j<M_size; ++j) {
            best_size = max(best_size, (N_cut[i] - N_cut[i-1]) * (M_cut[j] - M_cut[j-1]) );
        }
    }
    
    cout << best_size;
    
    return 0;
}
