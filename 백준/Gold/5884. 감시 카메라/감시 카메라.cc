#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N;
unordered_map<int, int> x_loca, y_loca;
vector<pll> cows(50000);

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.second > b.second;
    }
};



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int s, e, result = 0;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        x_loca[s]++;
        y_loca[e]++;
        cows[i] = {s, e};
    }    
    vector<pll> x_vec(x_loca.begin(), x_loca.end()), y_vec(y_loca.begin(), y_loca.end());
    sort(x_vec.begin(), x_vec.end(), Compare());
    sort(y_vec.begin(), y_vec.end(), Compare());
    // for (pll a : x_vec) {
    //     cout << "{" << a.first << ", " << a.second << "} ";
    // }
    // cout << "\n";
    
    // for (pll a : y_vec) {
    //     cout << "{" << a.first << ", " << a.second << "} ";
    // }
    // cout << "\n";
    
    for (int i=1; i<=6; ++i) {
        for (int j=i+1; j<=6; ++j) {
            for (int k=j+1; k<=6; ++k) {
                unordered_set<int> x_line, y_line;
                
                if (i <= 3) x_line.insert(x_vec[i % 3].first);
                else y_line.insert(y_vec[i % 3].first);
                
                if (j <= 3) x_line.insert(x_vec[j % 3].first);
                else y_line.insert(y_vec[j % 3].first);
                
                if (k <= 3) x_line.insert(x_vec[k % 3].first);
                else y_line.insert(y_vec[k % 3].first);
                
                bool is_ok = true;
                for (int q=0; q<N; ++q) {
                    if (x_line.find(cows[q].first) == x_line.end() && y_line.find(cows[q].second) == y_line.end()) {
                        is_ok = false;
                        break;
                    }
                }
                
                if (is_ok) result = 1;
            }
        }
    }
    
    cout << result;

    return 0;
}


