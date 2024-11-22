#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> numbers;

vector<vector<int> > dp;

void make_dp(int x, int y)
{
    if (dp[x][y] == -1) {
        if (numbers[x] == numbers[y]) {
            if (x + 1 == y) {
                dp[x][y] = 1;
                dp[y][x] = 1;
            }
            
            else {
                make_dp(x+1, y-1);
                if (dp[x+1][y-1] == 1) {
                    dp[x][y] = 1;
                    dp[y][x] = 1;
                }
                else {
                    dp[x][y] = 0;
                    dp[y][x] = 0;
                }
            }
        }
        else {
            dp[x][y] = 0;
            dp[y][x] = 0;
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cin.ignore();
    dp.resize(N+1, vector<int>(N+1, -1));
    
    for (int i=1; i<=N; ++i) {
        dp[i][i] = 1;
    }
    
    numbers.push_back(0);
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while(iss >> num) {
        numbers.push_back(num);
    }
    
    for (int i=1; i<=N; ++i) {
        for (int j=i+1; j<=N; ++j) {
            if (dp[i][j] == -1) {
                make_dp(i, j);
            }
        }
    }
    
    cin >> M;
    
    int s, e;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        if (s > e) {
            swap(s, e);
        }
        cout << dp[s][e] << "\n";
        
    }

    return 0;
}
