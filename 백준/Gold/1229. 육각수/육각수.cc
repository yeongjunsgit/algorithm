#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> six_angle, dp(1000001, 999999999);

void make_six_angle_num()
{
    int now = 1, plusplus = 1;
    while (now <= 1002000) {
        six_angle.push_back(now);
        plusplus += 4;
        now += plusplus;
    }
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    make_six_angle_num();
    dp[0] = 0;
    int M = six_angle.size();
    for (int i=1; i<=1000000; ++i) {
        for (int j=0; j<=M; ++j) {
            if (i < six_angle[j]) break;
            dp[i] = min(dp[i], dp[i - six_angle[j]] + 1);
        }
    }
    cout << dp[N];

    return 0;
}
