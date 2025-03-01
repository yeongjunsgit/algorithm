#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, T, A, B;

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.first > b.first;
    }
};

priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> body_bang;

void avoid_bang()
{
    unordered_map<int, int> previous, next, tmp;

    for (int j=-1000; j<=1000; ++j) {
        previous[j] = 2003;
    }
    
    next = previous;
    tmp = previous;
    
    previous[0] = 0;
    
    int now = 1;
    
    while (!body_bang.empty()) {
        
        int limit = body_bang.top().first;
        int start = body_bang.top().second.first;
        int end = body_bang.top().second.second;
        body_bang.pop();
        
        while (now <= limit) {
            for (int j=-1000; j<=1000; ++j) {
                
                if (j - 1 >= -1000 && previous[j - 1] != 2003) {
                    next[j] = min(previous[j - 1] + 1, next[j]);
                }
                if (previous[j] != 2003) {
                    next[j] = min(previous[j], next[j]);
                }
                if (j + 1 <= 1000 && previous[j + 1] != 2003) {
                    next[j] = min(previous[j + 1] + 1, next[j]);
                }
            }
            now++;
            
            previous = next;
            next = tmp;
            
        }
        
        for (int p=start + 1; p<end; ++p) {
            previous[p] = 2003;
        }
        
    }
    
    
    int result = 2003;
    
    for (int j=-1000; j<=1000; ++j) {
        if (previous[j] < result) {
            result = previous[j];
        }
    }
    
    if (result == 2003) {
        cout << -1;
    }
     else {
        cout << result;
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> T >> A >> B;
        body_bang.push({T, {A, B}});
    }
    
    avoid_bang();

    return 0;
}
