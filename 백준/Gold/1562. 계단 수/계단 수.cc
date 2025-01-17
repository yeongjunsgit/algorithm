#include <iostream>
#include <vector>

using namespace std;

int N;
int INF = 1000000000;
vector<vector<vector<int> > > dp(10, vector<vector<int> >(101, vector<int>(1024)));

// 인자로 현재 자리에 들어갈 수와, 현재 자리수, 0~9의 숫자가 들어갔는지 판단할 bit를 받는다.
int make_dp(int now_num, int depth, int bitbit)
{
    // 만약 이전에 계산된 적 있는 경우라면 기록된 값을 반환한다.
    if (dp[now_num][depth][bitbit] != 0) return dp[now_num][depth][bitbit];
    
    // 만약 현재 자리가 주어진 N의 자리와 같다면 더 이상 자릿수를 늘릴 필요가 없으므로, 현재 0~9의 모든 숫자가 쓰였는지
    // 확인하고 다 쓰였다면 1을 반환 아니라면 0을 반환한다.
    if (depth == N) {
        if (bitbit == 1023) return 1;
        else return 0;
    }
    
    // 현재 경우에서 파생되는 모든 경우의 수를 저장하기 위한 tmp를 선언
    int tmp = 0;
    // 현재 수에서 +1 과 -1 할 수 있는 경우 자리수를 늘리고 해당 숫자를 bit or 연산을 이용해 기록하여 재귀한다
    // 재귀에서 돌아왔을 때 가지고 온 파생된 경우의 수의 계단 수 개수를 tmp에 더한다.
    if (now_num + 1 <= 9) {
        tmp += make_dp(now_num + 1, depth + 1, bitbit | 1 << (now_num + 1));
    }
    if (now_num - 1 >= 0) {
        tmp += make_dp(now_num - 1, depth + 1, bitbit | 1 << (now_num - 1));
    }
    
    // 주어진 조건에 맞게 나눈다.
    tmp %= INF;

    // dp에 기록하면서 반환
    return dp[now_num][depth][bitbit] = tmp;
    
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N;
    int result = 0;
    // 가장 첫번째 자리 수를 선정해 인자로 넣는다.(0으로 시작하는 수는 없으니까 1부터 시작)
    // bitmask를 이용해 0~9까지의 숫자의 여부를 판단한다. 이는 10개의 비트(2^10)를 이용하여 각 비트값을 bool처럼 사용해 판단한다.
    // 모든 숫자가 있다면 1111111111(=1023) 이 될것이다.
    // 해당 첫째자리 수에서 발생하는 모든 경우의 계단 수를 result에 더한다.
    for (int i=1; i<=9; ++i) {
        result += make_dp(i, 1, 1<<i);
        result %= INF;
    }
    
    cout << result;

    return 0;
}
