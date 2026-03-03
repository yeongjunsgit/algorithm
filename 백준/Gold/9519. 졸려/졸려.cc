#include <iostream>
#include <vector>

using namespace std;

int X, N, M;
vector<string> passed(1);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> passed[0];
    N = passed[0].size();
    M = N / 2;
    bool is_cycle = false;
    for (int i=1; i<=X; ++i) {
        string tmp = passed[0];
        int cnt = 0;
        for (int j=0; j<N; ++j) {
            if (j % 2 == 0) tmp[cnt] = passed[i-1][j];
            else {
                tmp[N-1-cnt] = passed[i-1][j];
                cnt++;
            }
        }
        passed.push_back(tmp);
        // cout << i << " " << tmp << "\n";
        if (tmp == passed[0]) {
            is_cycle = true;
            break;
        }
    }
    
    if (is_cycle == false) cout << passed[X];
    else {
        int result = X % (passed.size() - 1);
        cout << passed[result];
    }
    
    
    return 0;
}