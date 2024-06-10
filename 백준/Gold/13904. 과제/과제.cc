#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Compare{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        
        return a.second < b.second;
    }
};

int main()
{
    int N;
    cin >> N;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    
    for (int i=0; i<N; ++i) {
        int day, score;
        cin >> day >> score;
        
        que.push({day, score});
    }
    
    vector<int> schedule(1001, 0);
    
    int result = 0;
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        
        if (schedule[now.first] == 0) {
            schedule[now.first] = now.second;
            result += now.second;
        }
        
        else {
            for (int i=now.first-1; i>=1; --i) {
                if (schedule[i] == 0) {
                    schedule[i] = now.second;
                    result += now.second;
                    break;
                }
            }
        }
    }

    cout << result;

    return 0;
}
