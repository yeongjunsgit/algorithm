#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> dp(10001, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i=0; i<10001; ++i) {
        int tmp = i;
        string tmp_s = to_string(tmp);
        
        for (char a : tmp_s) {
            tmp += a - '0';
        }
        if (tmp < 10001) {
            dp[tmp] = 1;
        }
    }
    
    for (int i=0; i<10001; ++i) {
        if (dp[i] == 0) {
            cout << i << "\n";
        }
    }

    return 0;
}