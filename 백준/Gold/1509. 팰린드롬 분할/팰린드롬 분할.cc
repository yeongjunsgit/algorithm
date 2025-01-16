#include <iostream>
#include <vector>

using namespace std;

string target;
int result = 0;
int N;
vector<vector<int> > is_pal;
vector<int> dp;

// 펠린드롬이라면 해당 개수는 1일 것이다.
int make_pal(int x, int y)
{
    if (x == y) return 1;
    
    if (target[x] == target[y]) {
        if (x+1 == y) {
            is_pal[x][y] = 1;
            is_pal[y][x] = 1;
            return 1;
        }   
        
        bool beyond = make_pal(x+1, y-1);
        
        if (beyond == 1) {
            is_pal[x][y] = 1;
            is_pal[y][x] = 1;
        }
        else {
            is_pal[x][y] = 0;
            is_pal[y][x] = 0;
        }
    }
    
    else {
        is_pal[x][y] = 0;
        is_pal[y][x] = 0;
    }
    
    return is_pal[x][y];
}

void find_best()
{
    for (int end = 0; end < N; ++end) {
        for (int start = 0; start <= end; ++start) {
            if (is_pal[start][end] == 1) {
                if (start != 0) {
                    dp[end] = min(dp[end], dp[start - 1] + 1);
                }
                else {
                    dp[end] = min(dp[end], 1);
                }
            }
        }
    }
    
    return;
}

int main()
{
    cin >> target;
    N = target.size();
    is_pal.resize(N, vector<int>(N, -1));
    dp.resize(N, 2501);
    
    for (int i=0; i<N; ++i) {
        is_pal[i][i] = true;
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (is_pal[i][j] == -1) {
                make_pal(i, j);
            }
        }
    }
    
    find_best();
    
    cout << dp[N-1];

    return 0;
}
