#include <iostream>
#include <vector>

using namespace std;

int N = -1, K = -1;

long long el_dorado(vector<int>& numbers)
{
    vector<vector<long long> > DP(N, vector<long long>(K + 1, 0));
    long long result = 0;
    DP[0][1] = 1;
    
    for (int i=1; i<N; ++i) {
        for (int j=0; j<i; ++j) {
            if (numbers[i] > numbers[j]) {
                for (int k=1; k<K; ++k) {
                    DP[i][k + 1] += DP[j][k];
                }
            }
        }
        
        DP[i][1] = 1;
    }
    
    for (int i=0; i<N; ++i) {
        result += DP[i][K];
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N >> K;
        if (N == 0 && K == 0) break;
        
        vector<int> numbers(N, 0);
        for (int i=0; i<N; ++i) {
            cin >> numbers[i];
        }
        
        cout << el_dorado(numbers) << "\n";
        
    }

    return 0;
}
