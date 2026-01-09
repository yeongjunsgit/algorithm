#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int T, N;
// 0번 인덱스는 y가 짝수일때, 1번 인덱스는 y가 홀수 일때
vector<vector<pll> > directions = { {{-1, 0}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}}, {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}} };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N;
        
        vector<vector<vector<int> > > DP(N+1, vector<vector<int> >(40, vector<int>(40, 0) ) );
        DP[0][20][20] = 1;
        for (int i=1; i<=N; ++i) {
            for (int j=0; j<40; ++j) {
                for (int k=0; k<40; ++k) {
                    if (DP[i-1][j][k] > 0) {
                        for (int q=0; q<6; ++q) {
                            int nx = j + directions[k % 2][q].first, ny = k + directions[k % 2][q].second;
                            if (0 <= nx && nx < 40 && 0 <= ny && ny < 40) DP[i][nx][ny] += DP[i-1][j][k];
                        }
                    }
                }
            }
        }
        
        cout << DP[N][20][20] << "\n";
    }
    

    return 0;
}
