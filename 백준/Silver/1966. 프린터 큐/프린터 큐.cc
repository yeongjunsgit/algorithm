#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

int T, N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        int num;
        priority_queue<int, vector<int>, less<int>> pq;
        queue<pair<int, int> > que;
        
        for (int i=0; i<N; ++i) {
            cin >> num;
            que.push({num, i});
            pq.push(num);
        }
        
        int idx = 1;
        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            if (now.first == pq.top()) {
                pq.pop();
                if (now.second == M) {
                    cout << idx << "\n";
                }
                idx++;
            }
            else {
                que.push(now);
            }
        }
    }

    return 0;
}
