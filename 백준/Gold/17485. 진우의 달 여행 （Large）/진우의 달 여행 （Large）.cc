#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int> > board;

int main()
{
    int N, M;
    
    cin >> N >> M;
    cin.ignore();
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        board.push_back(one_line);
    }
    
    vector<vector<vector<int> > > dp(N, vector<vector<int> >(M, vector<int>(3, 1000001)));
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<3; ++j) {
            dp[0][i][j] = board[0][i];
        }
    }
    
    for (int i=1; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            for (int p=-1; p<2; ++p) {
                if (j + p >= 0 && j + p < M) {
                    for (int k=0; k<3; ++k) {
                        if (p != k-1) {
                            dp[i][j][p+1] = min(dp[i][j][p+1], dp[i-1][j + p][k] + board[i][j]);
                        }
                    }
                }
            }
        }
    }
    
    int result = 1000001;
    
    for (int i=0; i<M; ++i) {
        for (int a : dp[N-1][i]) {
            result = min(result, a);
        }
    }
    
    cout << result;

    return 0;
}
