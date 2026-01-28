// 보아하니 좌우가 대칭이면 뺄 필요가 없다 N=4일때 모든 경우의 수는 11개, 대칭인 수는 5개, 대칭이 아닌 개수는 절반을 뺀다 = 3개
// 총 8개가 된다
// 그럼 현재 대칭인 경우의 개수는 어떻게 알까?? 2칸전에 대칭이었던 값에 양 옆에 │ 모양을 두면 대칭이 된다.
// 4칸 전에 대칭이었던 값의 양 옆에 ㅁ 이나, = 모양을 두면 대칭이 된다. 전체 개수를 가진 dp와 대칭의 개수를 가진 same_dp를 선언하여 이 값을 진행하면서 만들어서
// 계산에 쓰면 되지 않을까?
// 로직을 잘생각해놓고 양 옆에 │를 둔다는 코드에 i-2가 아니라 i-1을 하고있었다.... 진짜 정신 차리면서 문제 풀자.. 제발..!!

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> dp(31, 0), same_dp(31, 0);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    // 0을 1로 두는 이유는 계산 로직이 동작하기 위함이다. │ 모양과 ㅁ 모양, = 모양은 각각 자체가 대칭이라 할 수 있다.
    same_dp[0] = 1; same_dp[1] = 1; same_dp[2] = 2;
    dp[0] = 1;
    for (int i=1; i<=N; ++i) {
        // │ 가 뒤에 추가되는 경우
        dp[i] += dp[i-1];
        // ㅁ과 = 가 뒤에 추가되는 경우
        if (i - 2 >= 0) {
            dp[i] += dp[i-2] * 2;
            // 양 끝에 │가 추가되어 대칭인 경우
            same_dp[i] += same_dp[i-2];
        }
        // 양 끝에 ㅁ과 =가 추가되어 대칭인 경우
        if (i - 4 >= 0) {
            same_dp[i] += same_dp[i-4] * 2;
        }
    }
    
    cout << same_dp[N] + (dp[N] - same_dp[N]) / 2;

    return 0;
}
