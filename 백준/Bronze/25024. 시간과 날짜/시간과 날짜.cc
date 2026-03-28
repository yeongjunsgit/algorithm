#include <iostream>
#include <vector>

using namespace std;

int T, s, e;

vector<int> month_days = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> s >> e;
        if (s < 24 && e < 60) cout << "Yes ";
        else cout << "No ";
        
        if (0 < s && s <= 12 && 0 < e && e <= 31) {
            if (e <= month_days[s]) cout << "Yes";
            else cout << "No";
        }
        else cout << "No";
        cout << "\n";
    }
    

    return 0;
}