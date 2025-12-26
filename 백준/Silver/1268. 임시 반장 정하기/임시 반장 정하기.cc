#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > class_match(1001, (vector<int>(6) ) ), match_info(1001, vector<int>(1001, 0));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=5; ++j) {
            cin >> class_match[i][j];
        }
    }
    
    for (int i=1; i<=5; ++i) {
        vector<vector<int> > classroom(10);
        for (int j=1; j<=N; ++j) {
            classroom[class_match[j][i]].push_back(j);
        }
        for (int k=1; k<10; ++k) {
            if (classroom[k].size() >= 2) {
                int n_size = classroom[k].size();
                for (int p=0; p<n_size; ++p) {
                    for (int q=p+1; q<n_size; ++q) {
                        match_info[classroom[k][p]][classroom[k][q]] = 1;
                        match_info[classroom[k][q]][classroom[k][p]] = 1;
                    }
                }
            }
        }
    }
    
    int result = -1, best_friends = 0;
    for (int i=1; i<=N; ++i) {
        int now_cnt = 0;
        for (int j=1; j<=N; ++j) {
            if (i != j && match_info[i][j] == 1) now_cnt++;
        }
        if (now_cnt > best_friends) {
            best_friends = now_cnt;
            result = i;
        }
    }
    
    if (result != -1) cout << result;
    else cout << 1;


    return 0;
}
