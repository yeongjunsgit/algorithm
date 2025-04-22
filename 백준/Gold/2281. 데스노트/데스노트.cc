#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<long long> DP, numbers;

void set_DP(int depth, long long num)
{
    if (depth == N-1) {
        DP[depth] = 0;
        return;
    }
    
    int tmp = -1;
    for (int i=depth; i<N; ++i) {
        tmp += numbers[i] + 1;
        if (tmp > M) break;
        
        if (i != N-1) {
            long long tmp_power = DP[i+1] + (M - tmp) * (M - tmp);
            // cout << "나는 " << depth << "이고 현재 " << i << "번째 계산을 해서 " << tmp_power << "가 계산값으로 나왔어 \n";
            DP[depth] = min(DP[depth], tmp_power);
            // cout << "나는 " << depth << "이고 현재 " << i << "번째 계산을 해서 " << DP[depth] << "가 최소값이 나왔어 \n";
        }
        else {
            DP[depth] = 0;
            // cout << "나는 " << depth << "이고 현재 " << i << "번째 계산을 해서 " << DP[depth] << "가 최소값이 나왔어 \n";
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    DP.resize(N, 1000*1000*1000);
    numbers.resize(N, 0);
    long long num;
    vector<int> one_line;
    for (int i=0; i<N; ++i) {
        cin >> num;
        numbers[i] = num;
    }
    for (int i=N-1; i>=0; --i) {
        set_DP(i, numbers[i]);
    }

    cout << DP[0];
    
    return 0;
}
