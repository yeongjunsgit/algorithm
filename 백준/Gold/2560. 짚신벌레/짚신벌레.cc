#include <iostream>
#include <vector>

using namespace std;

int N, a, b, d;

int bugs_life()
{
    vector<int> DP(N+1, 0), born_bug(N+1, 0);
    DP[0] = 1; born_bug[0] = 1;
    for (int i=1; i<=N; ++i) {
        // 태어난지 a일이 됬고 b일이 되지 않은 개체는 번식한다.
        DP[i] = DP[i - 1]; born_bug[i] = born_bug[i - 1];
        if (i - a >= 0) {
            if (i - b < 0) {
                born_bug[i] += born_bug[i - a];
            }
            else {
                int tmp_bug = born_bug[i - a] - born_bug[i - b];
                if (tmp_bug < 0) tmp_bug += 1000;
                born_bug[i] += tmp_bug;
            }
            DP[i] += born_bug[i] - born_bug[i - 1];
            if (DP[i] < 0) DP[i] += 1000;
        }
        
        if (i - d >= 0) {
            if (i - d == 0) {
                DP[i] -= born_bug[0];
            }
            else {
                int tmp_die_bug = born_bug[i - d] - born_bug[i - d - 1];
                if (tmp_die_bug < 0) tmp_die_bug += 1000;
                DP[i] -= tmp_die_bug;
            }
            if (DP[i] < 0) DP[i] += 1000;
        }
        
        born_bug[i] %= 1000;
        DP[i] %= 1000;
    }
    
    return DP[N];
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> d >> N;
    
    cout << bugs_life();
    
    return 0;
}
