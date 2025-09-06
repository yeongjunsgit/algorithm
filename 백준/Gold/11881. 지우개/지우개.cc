#include <iostream>
#include <vector>

#define INF 1000000007

using namespace std;

int N;
long long result = 0;
vector<long long> numbers, sumsum(100001, 0), cnt(100001, 0);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    numbers.resize(N+1);
    for (int i=1; i<=N; ++i) {
        cin >> numbers[i];
        cnt[numbers[i]]++;
    }
    for (int i=1; i<=100000; ++i) {
        sumsum[i] = sumsum[i-1] + (i * cnt[i]);
        // cout << sumsum[i] << "\n";
    }
    
    for (int i=1; i<=100000; ++i) {
        result = (result + (((sumsum[i-1] * (sumsum[100000] - sumsum[i]) % INF) * i) % INF * cnt[i] ) % INF ) % INF;
    }    
    
    cout << result;    

    return 0;
}
