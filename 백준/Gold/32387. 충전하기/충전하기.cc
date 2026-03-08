#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, Q, T, P;
vector<int> concent(1000001, 0);
set<int> empty_concent;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i=1; i<=N; ++i) {
        empty_concent.insert(i);
    }
    
    for (int i=1; i<=Q; ++i) {
        cin >> T >> P;
        if (T == 1) {
            auto now_concent = empty_concent.lower_bound(P);
            if (now_concent == empty_concent.end()) cout << -1 << "\n";
            else {
                cout << *now_concent << "\n";
                concent[*now_concent] = i;
                empty_concent.erase(now_concent);
            }
        }
        else {
            if (concent[P] == 0) cout << -1 << "\n";
            else {
                cout << concent[P] << "\n";
                concent[P] = 0;
                empty_concent.insert(P);
            }
        }
    }
    

    return 0;
}