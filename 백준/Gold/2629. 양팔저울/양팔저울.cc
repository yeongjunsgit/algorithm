#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> weights, DP;

void make_dp()
{
    DP.resize(40001, -1);
    for (int i=0; i<N; ++i) {
        for (int j=1; j<=40000; ++j) {
            if (DP[j] != -1 && DP[j] != i && j + weights[i] <= 40000 && DP[j + weights[i]] == -1) {
                DP[j + weights[i]] = i;
                // cout << j + weights[i] << " ";
            }
        }
        DP[weights[i]] = i;
    }
    // cout << "\n";
    
    for (int i=0; i<N; ++i) {
        for (int j=1; j<=40000; ++j) {
            if (DP[j] != -1 && DP[j] != i + 31 && j - weights[i] > 0 && DP[j - weights[i]] == -1) {
                DP[j - weights[i]] = i + 31;
                // cout << j - weights[i] << " ";
            }
        }
    }
    // cout << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    weights.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> weights[i];
    }
    
    make_dp();
    int num;
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> num;
        if (DP[num] != -1) cout << "Y ";
        else cout << "N ";
    }
    
    return 0;
}
