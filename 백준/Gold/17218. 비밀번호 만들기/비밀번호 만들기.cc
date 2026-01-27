// 문제를 읽어보니 가장 긴 공통 부분 문자열을 구하는 문제로 보였다. 그러나 너무 오랜만에 봐서 그런가...
// N*M 크기의 배열을 선언하여 서로 비교하고 값을 기록하는 건 기억이 나는데 같지 않을경우 어디에서 값을 가져오는지,
// 그리고 같으면 상단, 왼쪽, 왼상단 3중 어디 값을 사용하는지 기억이 드물어 다시 공부하고 문제를 풀었다!
// 우선 값이 같지 않다면 왼쪽과 상단 중 가장 큰 값을 가져오고, 값이 같다면 왼상단의 값에 1을 더한다.
// 위와 같이 구현한 후 길이를 알아낸 다음 lcs[N][M]에서 시작해 현재 위치와 같은 값을 왼쪽 or 상단에서 찾아 이쪽으로 이동하고,
// 만약 없다면 현재 위치의 알파벳을 기록한 후 왼상단으로 이동하며 0이 나오면 종료하고 얻은 알파벳을 역순으로 보이면 끝이다!

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > dp(41, vector<int>(41, 0));
string s, e;
int s_size, e_size;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> e;
    s_size = s.size(); e_size = e.size();
    
    for (int i=1; i<=s_size; ++i) {
        for (int j=1; j<=e_size; ++j) {
            if (s[i-1] == e[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<char> result(dp[s_size][e_size]);
    int n = s_size, m = e_size;
    while (dp[n][m] > 0) {
        if (dp[n][m] == dp[n-1][m]) n--;
        else if (dp[n][m] == dp[n][m-1]) m--;
        else if (dp[n][m] > dp[n-1][m] && dp[n][m] > dp[n][m-1]) {
            result[dp[n][m] - 1] = s[n-1];
            n--; m--;
        }
    }
    
    for (char a : result) {
        cout << a;
    }
    
    return 0;
}
