#include <iostream>
#include <vector>

using namespace std;

int N, M;
string pass_code;
vector<string> devil_angel(2);
vector<vector<vector<int> > > sumsum(2, vector<vector<int> >(20, vector<int>(100, 0)));


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> pass_code >> devil_angel[0] >> devil_angel[1];
    int N = pass_code.size(), M = devil_angel[0].size(), cnt = 0;
    
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            for (int k=0; k<2; ++k) {
                sumsum[k][i][j] = sumsum[k][i][max(0, j - 1)];
                if (devil_angel[k][j] == pass_code[i]) {
                    if (i == 0) {
                        sumsum[k][i][j]++;
                    }
                    else {
                        sumsum[k][i][j] += sumsum[(k + 1) % 2][i - 1][j - 1];
                    }
                }
            }
        }
    }
    
    cout << sumsum[0][N-1][M-1] + sumsum[1][N-1][M-1];

    return 0;
}
