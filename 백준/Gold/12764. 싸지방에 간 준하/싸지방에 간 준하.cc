#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

struct Pair_Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Pair_Compare> que;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> now_used;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Pair_Compare> tmp_que;
    int s, e;
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        que.push({s, e});
    }
    
    vector<int> use_com;
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        if (now_used.empty()) {
            use_com.push_back(1);
            now_used.push({0, now.second});
        }
        else {
            while (!now_used.empty()) {
                if (now_used.top().second <= now.first) {
                    pair<int, int> now_best = now_used.top();
                    now_used.pop();
                    tmp_que.push(now_best);
                }
                else {
                    break;
                }
            }
            if (tmp_que.empty()) {
                use_com.push_back(1);
                now_used.push({use_com.size() - 1, now.second});
                continue;
            }
            
            pair<int, int> target = tmp_que.top();
            tmp_que.pop();
            use_com[target.first] += 1;
            now_used.push({target.first, now.second});
        }
    }
    
    cout << use_com.size() << "\n";
    
    for (int a : use_com) {
        cout << a << " ";
    }

    return 0;
}
