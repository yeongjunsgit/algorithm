#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
long long INF = pow(2, 31);
vector<pair<int, int> > process_size;
// 각 구간 별 곱셈 연산의 최솟값을 저장하기 위한 2차원 DP
vector<vector<long long> > dp(501, vector<long long>(501, INF)); 

long long make_dp(int start, int end)
{
    // 인덱스 값이 똑같으면 구간이 없으므로 0 반환
    if (start == end) {
        return 0;
    }
    
    // 이미 계산된 구간이라면 계산된 값을 반환
    if (dp[start][end] != INF) {
        return dp[start][end];
    }
    
    // 주어진 범위안에서 모든 경우의 범위들을 연산하여 최솟값을 구해 DP에 저장
    for (int i=start; i<end; ++i) {
        dp[start][end] = min(dp[start][end], make_dp(start, i) + make_dp(i+1, end) + (process_size[start].first * process_size[i].second * process_size[end].second));
    }
    
    // 현재 구간의 최솟값을 반환
    return dp[start][end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    int s, e;
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        process_size.push_back({s, e});
    }
    
    // 주어진 배열을 저장한 벡터의 첫 인덱스와 끝 인덱스 값을 넣어 해당 구간의 최솟값을 출력한다.
    cout << make_dp(0, N - 1);
    
    return 0;
}
