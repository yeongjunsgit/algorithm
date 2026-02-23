#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
string A, B;


int lets_make_B()
{   
    int before_idx = N, cnt = 0;
    
    for (int i=N-1; i>=0; --i) {
        int now_idx = -1;
        for (int j=0; j<before_idx; ++j) {
            if (A[j] == B[i]) {
                // cout << A[j] << " " << B[i] << "\n";
                now_idx = j;
            }
        }
        if (now_idx == -1) break;
        cnt += before_idx - now_idx - 1;
        before_idx = now_idx;
    }
    if (before_idx != 0) cnt += before_idx;
    
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    N = A.size();
    unordered_map<char, int> AB_cnt;
    bool not_correct = false;
    for (char c : A) {
        AB_cnt[c]++;
    }
    for (char c : B) {
        AB_cnt[c]--;
        if (AB_cnt[c] < 0) not_correct = true;
    }
    
    if (not_correct) cout << -1;
    else cout << lets_make_B();

    return 0;
}
