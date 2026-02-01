#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > rice_cake(1000), can_rice(1000, vector<int>(10, 0) ); 
vector<int> day_size(1000), result;


void dfs(int depth, int now, vector<int>& now_passed)
{
    if (!result.empty()) return;
    
    now_passed.push_back(now);
    if (depth == 0) {
        if (result.empty()) {
            result = now_passed;
        }
    }
    else {
        for (int a : rice_cake[depth - 1]) {
            if (a != now && can_rice[depth - 1][a] == 1) {
                dfs(depth-1, a, now_passed);
            }
        }
    }
    now_passed.pop_back();

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int rice;
    for (int i=0; i<N; ++i) {
        cin >> day_size[i];
        for (int j=0; j<day_size[i]; ++j) {
            cin >> rice;
            rice_cake[i].push_back(rice);
            if (i == 0) can_rice[i][rice] = 1;
        }
    }
    
    for (int i=1; i<N; ++i) {
        for (int a : rice_cake[i]) {
            for (int j : rice_cake[i-1]) {
                if (j != a && can_rice[i-1][j] == 1) {
                    can_rice[i][a] = 1;
                    break;
                }
            }
        }
    }
    
    vector<int> passed;
    for (int t : rice_cake[N-1]) {
        if (can_rice[N-1][t] == 1) {
            dfs(N-1, t, passed);
            break;
        }
    }
    if (result.empty() ) cout << -1;
    else {
        while (!result.empty()) {
            cout << result.back() << "\n";
            result.pop_back();
        }
    }

    return 0;
}
