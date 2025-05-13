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
vector<pll> papers;

void set_paper()
{
    int result = 0;
    vector<int> DP(N, 1);
    for (int i=1; i<N; ++i) {
        for (int j=0; j<i; ++j) {
            if (papers[j].first >= papers[i].first && papers[j].second >= papers[i].second) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    for (int i=0; i<N; ++i) {
        result = max(result, DP[i]);
    }
    
    cout << result;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int s, e;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        if (s > e) swap(s, e);
        papers.push_back({s, e});
    }
    
    sort(papers.begin(), papers.end(), Compare());

    set_paper();

    return 0;
}