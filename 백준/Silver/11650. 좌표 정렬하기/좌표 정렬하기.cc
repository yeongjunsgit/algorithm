#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    int s, e;
    vector<pair<int, int> > locas;
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        locas.push_back({s, e});
    }
    
    sort(locas.begin(), locas.end());
    
    for (auto a : locas) {
        cout << a.first << " " << a.second << "\n";
    }

    return 0;
}