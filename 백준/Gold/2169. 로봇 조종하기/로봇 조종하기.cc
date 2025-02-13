#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board;
int dp[2][1001][1001];
// vector<pll> direction = {{0, 1}, {1, 0}, {0, -1}};

void make_dp()
{
    dp[0][0][0] = dp[1][0][0] = board[0][0];
    
    for (int i=0; i<M; ++i) {
        dp[0][0][i] = dp[1][0][i] = dp[0][0][i - 1] + board[0][i]; 
    }
    
    for (int i=1; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (j == 0) {
                dp[0][i][j] = max(dp[0][i - 1][j] + board[i][j], dp[1][i - 1][j] + board[i][j]);
            }
            else {
                dp[0][i][j] = max({dp[0][i - 1][j] + board[i][j], dp[1][i - 1][j] + board[i][j], dp[0][i][j - 1] + board[i][j]});
            }
        }
        for (int j=M-1; j>=0; --j) {
            if (j == M-1) {
                dp[1][i][j] = max(dp[0][i - 1][j] + board[i][j], dp[1][i - 1][j] + board[i][j]);
            }
            else {
                dp[1][i][j] = max({dp[0][i - 1][j] + board[i][j], dp[1][i - 1][j] + board[i][j], dp[1][i][j + 1] + board[i][j]});
            }
        }
    }
    
    cout << max(dp[0][N-1][M-1], dp[1][N-1][M-1]);
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M; cin.ignore();
    
    string data;
    int num;
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        board.push_back(one_line);
    }
    
    make_dp();
    
    // for (int i=0; i<2; ++i) {
    //     cout << "이번에는 " << i << " 입니다" << "\n";
    //     for (int j=0; j<N; ++j) {
    //         for (int k=0; k<M; ++k) {
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    
    return 0;
}
