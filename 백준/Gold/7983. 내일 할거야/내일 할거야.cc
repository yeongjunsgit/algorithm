#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

struct Compare {
    bool operator()(const pll& a, const pll& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int cost, limits;
    vector<pll> studys;
    for (int i=0; i<N; ++i) {
        cin >> cost >> limits;
        studys.push_back({limits, cost});
    }
    
    sort(studys.begin(), studys.end(), Compare());
    
    int maxy = 1000000001;
    
    for (pll p : studys) {
        maxy = min(maxy, p.first);
        maxy -= p.second;
        
    }
    
    cout << maxy;

    return 0;
}
