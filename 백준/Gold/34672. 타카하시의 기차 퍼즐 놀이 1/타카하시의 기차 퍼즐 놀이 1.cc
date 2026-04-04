#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int T, N, M;
long long K;
vector<vector<string> > blocks = {{"114", "322"}, {"144", "332"}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N >> M >> K;
        // 꽉 채울 수 없는 경우들은 바로 -1 출력
        if (N < 2 || M % 3 != 0) cout << -1 << "\n";
        // 채울 수 있는 경우
        else {
            int match_cnt = M / 3;
            bitset<333333> bit_mask;
            long long all_cnt = -1;
            if (match_cnt < 62) all_cnt = (1LL << match_cnt);
            if (all_cnt != -1 && all_cnt < K) cout << -1 << "\n";
            else {
                bit_mask = K - 1;
                for (int i=0; i<2; ++i) {
                    for (int j=match_cnt - 1; j>=0; --j) {
                        int tmp = bit_mask[j];
                        cout << blocks[i][tmp];
                    }
                    cout << "\n";
                }
            }
            
        }
    }

    return 0;
}
