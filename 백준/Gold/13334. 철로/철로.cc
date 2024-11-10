#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, D;
vector<pair<int, int> > liners;
int result = 0;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

struct pq_Compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

void check_lines()
{
    priority_queue<int, vector<int>, pq_Compare> que;
    
    for (int i=0; i<N; ++i) {
        if (liners[i].second - liners[i].first > D) {
            continue;
        }
        que.push(liners[i].first);

        while (!que.empty()) {
            if (que.top() + D < liners[i].second) {
                que.pop();
            }
            else {
                break;
            }
        }
        
        if (que.size() > result) {
            result = que.size();
        }

    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    int s, e;
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        if (s > e) {
            swap(s, e);
        }
        liners.push_back({s, e});
    }
    
    cin >> D;
    
    sort(liners.begin(), liners.end(), Compare());

    check_lines();

    return 0;
}
